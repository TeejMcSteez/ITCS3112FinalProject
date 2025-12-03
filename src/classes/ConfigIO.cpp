#include "ModelParams.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

/* TODO: There is a bug such that if there are improper amount of lines the
   program will crash with no output This needs to be fixed
*/

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
  if (!in)
    throw std::runtime_error("Open failed: " + path);

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
