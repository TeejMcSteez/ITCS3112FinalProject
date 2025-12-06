#include "../interfaces/ICostCalculator.h"
#include "./EnergyDecorator.cpp"

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
  OutputDecorator dec = OutputDecorator();
  public:
  std::vector<ModelParams> models;
  CostCalculator() = default;
  CostCalculator(std::vector<ModelParams> mdls) { models = mdls; }
  double Calculate(std::size_t numberOfTokens, ModelParams model) {
    std::cout << "NOT: " << numberOfTokens << std::endl;
    std::cout << "Model Params: " << model.MODEL_NAME << std::endl;
    std::cout << "TPS: " << model.TOKENS_PER_SECOND << std::endl;
    double seconds = static_cast<int>(numberOfTokens) / model.TOKENS_PER_SECOND;
    double hours = seconds / 3600;
    std::cout << "Hours: " << hours << std::endl;

    double energyWh = model.SYSTEM_POWER_DRAW * hours;
    double energyKWh = dec.WhToKwh(energyWh);

    std::cout << "Energy (KWh): " << energyKWh << std::endl;
    double cost = energyKWh * model.KWH_COST;
    return cost;
  }
};
