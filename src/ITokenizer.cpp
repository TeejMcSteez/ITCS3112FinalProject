#include <cstddef>
#include <iostream>
struct TokenBuffer {
    char * input;
    size_t size;
};

TokenBuffer Tokenizer(TokenBuffer tb) {
    std::cout << tb.size << std::endl;
    return tb;
}