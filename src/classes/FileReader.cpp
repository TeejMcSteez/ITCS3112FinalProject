#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string ReadFile(std::string path) {
  std::ifstream file(path);
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << path << std::endl;
    return "";
  }

  std::stringstream buffer;

  buffer << file.rdbuf();
  file.close();

  return buffer.str();
}
