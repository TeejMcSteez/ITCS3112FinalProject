#include "../types.h"

class ITokenizer {
    virtual Buffer Tokenize(const TokenBuffer& tb);
};