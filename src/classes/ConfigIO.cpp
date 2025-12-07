#include "ModelParams.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<std::string> split_commas(const std::string &line) {
  std::vector<std::string> out;

  std::stringstream ss(line);
  std::string cell;

  while (std::getline(ss, cell, ','))
    out.push_back(cell);
  return out;
}

std::vector<ModelParams> load_models_csv(const std::string &path) {
  std::ifstream in(path);
  if (!in) {
    std::cout << "Invalid filename please re-run the program and use the "
                 "correct file name"
              << std::endl;
    throw std::runtime_error("Open failed: " + path);
  }
  std::vector<ModelParams> rows;
  std::string line;

  if (!std::getline(in, line))
    return rows;

  while (std::getline(in, line)) {
    if (line.empty())
      continue;
    auto cells = split_commas(line);
    if (cells.size() < 5)
      throw std::runtime_error("Invalid config file");
    ModelParams m =
        ModelParams(cells[0], std::stoi(cells[1]), std::stoi(cells[2]),
                    std::stoi(cells[3]), std::stof(cells[4]));
    rows.push_back(std::move(m));
  }
  return rows;
}

std::vector<ModelParams> load_config(const char *path) {
  std::vector<ModelParams> models = load_models_csv(path);
  if (models.size() == 0) {
    std::cerr << "No models loaded from config" << std::endl;
  }
  return models;
}

void edit_config(const char *path) {
  std::fstream io(path, std::ios::in | std::ios::out | std::ios::app);
  if (!io)
    throw std::runtime_error("Failed to open file");

  std::cout << "1. Add Model" << std::endl;
  std::string choice;
  std::cin >> choice;

  int c = std::stoi(choice);
  std::string name, max_content_length, tokens_per_second, system_power_draw,
      cost_per_kwh, write;

  switch (c) {
  case 1:
    std::cout << "Please enter the name of the model" << std::endl;
    std::cin >> name;
    std::cout << "Please enter the max context length of the model"
              << std::endl;
    std::cin >> max_content_length;
    std::cout << "Please enter the tokens per second" << std::endl;
    std::cin >> tokens_per_second;
    std::cout << "Please enter the systems total power draw at max load"
              << std::endl;
    std::cin >> system_power_draw;
    std::cout << "Please enter your local cost in electricity per kwh"
              << std::endl;
    std::cin >> cost_per_kwh;
    write = name + "," + max_content_length + "," + tokens_per_second + "," +
            system_power_draw + "," + cost_per_kwh;
    io << write << '\n';
    break;
  default:
    std::cout << "Invalid choice" << std::endl;
  }
}
