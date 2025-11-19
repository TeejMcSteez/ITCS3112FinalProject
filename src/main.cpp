#include "./classes/Tokenizers.cpp"
#include "./classes/CostCalculator.cpp"
#include "./classes/ConfigIO.cpp"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <limits> // for std::numeric_limits

SpaceTokenizer st = SpaceTokenizer();
CostCalculator calc;

/**
 * Upper inclusive - lower exclusive
 * 
 * This is to ensure array operations with 0-based indexing work properly with input.
 */
int readBoundedInt(int lower, int upper) {
    int value;

    while (true) {
        std::cout << "Enter an integer: ";

        if (std::cin >> value && value <= upper && value > lower) {
            // Success: cin parsed an int
            return value;
        }

        std::cout << "Invalid input. Please enter a whole number between " << lower + 1 << " and " << upper << std::endl;

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
        std::string input;
        std::cout << "Please enter a string you wish to tokenzie and calculate" << std::endl;
        std::string in = "";
        while (in == "") {
            std::getline(std::cin, in);
        }
        const TokenBuffer tokenString = TokenBuffer(in);
        Buffer tokens = st.Tokenize(tokenString);
        float cost = calc.Calculate(tokens.input.size(), calc.models[modelChoice - 1]);
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