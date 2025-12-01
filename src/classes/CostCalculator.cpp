#include "../interfaces/ICostCalculator.h"

#include "ModelParams.h"
#include <iostream>
#include <vector>

/*
Formula: Energy (\(Wh\)) = Total Wattage (\(W\)) x Hours (\(h\)).
Example:
If your hardware setup has a total of 1000W and you run the LLM for 8 hours:
\(1000W\times 8h=8000Wh\). To get kilowatt-hours (\(kWh\)), divide the total
Watt-hours by 1000: \(8000Wh\div 1000=8kWh\).

Hours = (tokensPerSecond / number of tokens) / 3600


*/

class CostCalculator : ICostCalculator {
public:
  std::vector<ModelParams> models;
  CostCalculator() = default;
  CostCalculator(std::vector<ModelParams> mdls) { models = mdls; }
  float Calculate(int numberOfTokens, ModelParams model) {
    std::cout << "NOT: " << numberOfTokens << std::endl;
    std::cout << model.MODEL_NAME << std::endl;
    std::cout << "TPS: " << model.TOKENS_PER_SECOND << std::endl;
    float seconds = numberOfTokens / model.TOKENS_PER_SECOND;
    float hours = seconds / 3600;
    std::cout << "Hours: " << hours << std::endl;

    float energyWh = model.SYSTEM_POWER_DRAW * hours;
    float energyKWh = energyWh / 1000;

    std::cout << "Energy (KWh): " << energyKWh << std::endl;
    float cost = energyKWh * model.KWH_COST;
    return cost;
  }
  double RealisticCalculate(int numberOfTokens, ModelParams model) {
    std::cout << model.MODEL_NAME << std::endl;
    std::cout << "NOT: " << numberOfTokens << std::endl;

    std::cout << "TPS: " << model.TOKENS_PER_SECOND << std::endl;

    float seconds = numberOfTokens / model.TOKENS_PER_SECOND;
    float hours = seconds / 3600;
    std::cout << "Hours: " << hours << std::endl;

    float energyWh = model.SYSTEM_POWER_DRAW * hours;
    float energyKWh = energyWh / 1000;

    std::cout << "Energy (KWh): " << energyKWh << std::endl;
    double cost = energyKWh * model.KWH_COST;
    return cost;
  }
};
