#pragma once

#include "../interfaces/IModelParams.h"
#include <string>

class ModelParams : IModelParams {
public:
  std::string MODEL_NAME;
  int MAX_CONTEXT_LENGTH;
  int TOKENS_PER_SECOND;
  int SYSTEM_POWER_DRAW;
  double KWH_COST;
  ModelParams() {
    MODEL_NAME = "";
    MAX_CONTEXT_LENGTH = 15000;
    TOKENS_PER_SECOND = 15;
    SYSTEM_POWER_DRAW = 700;
    KWH_COST = 0.13;
  }
  ModelParams(std::string mdlName, int mcl, int tps, int systemPowerDraw,
              double kwhCost) {
    MODEL_NAME = mdlName;
    MAX_CONTEXT_LENGTH = mcl;
    TOKENS_PER_SECOND = tps;
    SYSTEM_POWER_DRAW = systemPowerDraw;
    KWH_COST = kwhCost;
  }
};
