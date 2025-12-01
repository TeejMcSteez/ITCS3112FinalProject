#include "../types.h"

struct ITokenizer {
  virtual ~ITokenizer() = default;
  virtual Buffer Tokenize(const TokenBuffer &tb) = 0;
};
