#include "file_handler.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

bool loadCitiesAndDistances(const std::string& fileName, std::vector<std::string>& cities, std::vector<std::vector<int>>& distances) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        return false;
    }

    json data;
    file >> data;

    // Parse city names
    for (const auto& city : data["cities"]) {
        cities.push_back(city["name"]);
    }

    // Parse distances
    distances = data["distances"].get<std::vector<std::vector<int>>>();

    return true;
}
