#include "../classes/ModelParams.h"

class ICostCalculator {
    float Calculate(int numberOfTokens, ModelParams mdls);
};