#pragma once

#include <string>
#include <vector>

struct TokenBuffer {
  std::string_view input;
  TokenBuffer(std::string in) { input = in; }
};

struct Buffer {
  std::vector<std::string> input;
  Buffer() {}
  Buffer(std::string in) { input.push_back(in); }
};

enum class Token_Algorithms {
  SPACE_WISE = 1,
  BYTE_PAIR = 2,
};