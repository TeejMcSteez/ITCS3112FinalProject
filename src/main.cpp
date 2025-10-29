#include "ITokenizer.cpp"
#include "ICostCalculator.cpp"

int main() {
    char * input;
    size_t input_length = 1;
    TokenBuffer tb  =  TokenBuffer({input, input_length});

    Tokenizer(tb);
    
}