#include "../interfaces/ITokenizer.h"
#include <cctype>
#include <map>
#include <string>
#include <vector>
#include <string>

class SpaceTokenizer : ITokenizer {
private:
  static bool isSpace(unsigned char c) { return std::isspace(c) != 0; }

  static void buffer_push(std::string_view slice, Buffer &out) {
    out.input.emplace_back(slice); // copies slice into a new std::string
  }

public:
  Buffer Tokenize(const TokenBuffer &tb) {
    Buffer out;
    const auto s = tb.input;
    size_t i = 0, n = s.size();

    while (i < n) {
      while (i < n && isSpace((unsigned char)s[i]))
        ++i;
      size_t begin = i;
      while (i < n && !isSpace((unsigned char)s[i]))
        ++i;
      size_t end = i;
      if (end > begin)
        buffer_push(s.substr(begin, end - begin), out);
    }
    return out;
  }
};

class BPETokenizer : ITokenizer {
private:
  std::map<std::string, int> vocab{
      // --- Basic whitespace ---
      {" ", 0},
      {"\n", 1},

      // --- Single lowercase letters ---
      {"a", 2},
      {"b", 3},
      {"c", 4},
      {"d", 5},
      {"e", 6},
      {"f", 7},
      {"g", 8},
      {"h", 9},
      {"i", 10},
      {"j", 11},
      {"k", 12},
      {"l", 13},
      {"m", 14},
      {"n", 15},
      {"o", 16},
      {"p", 17},
      {"q", 18},
      {"r", 19},
      {"s", 20},
      {"t", 21},
      {"u", 22},
      {"v", 23},
      {"w", 24},
      {"x", 25},
      {"y", 26},
      {"z", 27},

      // --- Single punctuation / operators ---
      {"(", 40},
      {")", 41},
      {"{", 42},
      {"}", 43},
      {";", 44},
      {"=", 45},
      {",", 46},
      {"+", 47},
      {"-", 48},
      {"*", 49},
      {"/", 50},
      {"<", 51},
      {">", 52},
      {"_", 53},
      {"#", 54},
      {":", 55},

      // --- Important multi-character BPE merges ---
      // C++ keywords
      {"in", 100},  // i + n
      {"int", 101}, // in + t
      {"ma", 102},
      {"mai", 103},
      {"main", 104},

      {"re", 105},
      {"ret", 106},
      {"retu", 107},
      {"retur", 108},
      {"return", 109},

  };

public:
  Buffer Tokenize(const TokenBuffer &tb) {
    Buffer out;
    const std::string_view s = tb.input;
    // breaks s into chars to search for byte pairs
    for (char c : s) {
      out.input.push_back(std::string(1, c));
    }
    for (int i = 0; i + 1 < out.input.size();) {
      std::string key = out.input[i] + out.input[i+1];
      if (auto it = vocab.find(key); it != vocab.end()) {
        out.input.erase(out.input.begin() + i, out.input.begin() + i + 2);
        out.input.push_back(key);
      } else {
        i++;
      }
    }
    return out;
  }
};
