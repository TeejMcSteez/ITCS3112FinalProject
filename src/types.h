#include <vector>
#include <string>

struct TokenBuffer {
    std::string_view input;
    TokenBuffer(std::string in) {
        input = in;
    }
};

struct Buffer {
    std::vector<std::string> input;
    Buffer() {}
    Buffer(std::string in) {
        input.push_back(in);
    }
};

