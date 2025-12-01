#include "./classes/ConfigIO.cpp"
#include "./classes/CostCalculator.cpp"
#include "./classes/FileReader.cpp"
#include "./classes/Tokenizers.cpp"
#include <cstring>
#include <iostream>
#include <limits> // for std::numeric_limits
#include <string>
#include <vector>

BPETokenizer bt = BPETokenizer();
SpaceTokenizer st = SpaceTokenizer();
CostCalculator calc = CostCalculator();

/**
 * Upper inclusive - lower exclusive
 *
 * This is to ensure array operations with 0-based indexing work properly with
 * input.
 */
int readBoundedInt(int lower, int upper) {
  int value;

  while (true) {
    std::cout << "Enter an integer: ";

    if (std::cin >> value && value <= upper && value > lower) {
      // Success: cin parsed an int
      return value;
    }

    std::cout << "Invalid input. Please enter a whole number between "
              << lower + 1 << " and " << upper << std::endl;

    std::cin.clear();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

int main() {

  std::cout << "Please enter config file\n" << std::endl;
  std::string configFile;
  std::cin >> configFile;

  while (true) {
    calc = CostCalculator(load_config(configFile.c_str()));
    std::cout << "Please choose a model" << std::endl;
    for (int i = 0; i < calc.models.size(); i++) {
      std::cout << i + 1 << ": " << calc.models[i].MODEL_NAME << std::endl;
    }
    int modelChoice = readBoundedInt(0, calc.models.size());

    std::string in;
    std::cout << "1. Enter a filename to convert to string\n2. Enter string"
              << std::endl;
    std::cin >> in;

    if (in == "1") {
      std::cout << "Please enter the path of the file" << std::endl;
      std::string path;
      std::cin >> path;
      in = ReadFile(path);
    } else if (in == "2") {
      std::string input;
      std::cout << "Please enter a string you wish to tokenzie and calculate"
                << std::endl;
      std::string in2 = "";
      while (in2 == "") {
        std::getline(std::cin, in2);
      }
    } else {
      std::cout << "Invalid input exiting" << std::endl;
      return 0;
    }

    const TokenBuffer tokenString = TokenBuffer(in);
    std::string in3;
    std::cout << "Choose tokenization algorithm\n1. Space tokenizer\n2. "
                 "Byte-Pair Tokenizer"
              << std::endl;
    std::cin >> in3;
    Buffer tokens;
    if (in3 == "1") {
      std::cout << "Using space-wise tokenizer" << std::endl;
      tokens = st.Tokenize(tokenString);
    } else if (in3 == "2") {
      std::cout << "Using byte-pair encoding tokenizer" << std::endl;
      tokens = bt.Tokenize(tokenString);
    } else {
      std::cout << "Invalid input exiting" << std::endl;
      return 0;
    }
    std::cout << "Calculating cost . . .\n" << std::endl;
    float cost =
        calc.Calculate(tokens.input.size(), calc.models[modelChoice - 1]);
    std::cout << "Current cost: " << cost << std::endl;
    char exit;
    std::cout << "Exit? (y/n)" << std::endl;
    std::cin >> exit;
    if (exit == 'y') {
      break;
    }
  }
  std::cout << "Exiting . . ." << std::endl;
  return 0;
}
