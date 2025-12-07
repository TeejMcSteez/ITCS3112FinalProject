#include "IModelParams.h"

class ICostCalculator {
  float Calculate(std::size_t numberOfTokens, IModelParams mdls);
};
