// #include <iostream>
// #include "tsp.h"
// #include "file_handler.h"

// int main() {
//     // Load data from file (optional for Phase 1)
//     std::string fileName = "data/cities.json";
//     std::vector<std::string> cities;
//     std::vector<std::vector<int>> distances;

//     if (!loadCitiesAndDistances(fileName, cities, distances)) {
//         std::cerr << "Error loading data from file!" << std::endl;
//         return 1;
//     }

//     std::cout << "Available cities: " << std::endl;
//     for (size_t i = 0; i < cities.size(); i++) {
//         std::cout << i << ": " << cities[i] << std::endl;
//     }

//     std::cout << "\nEnter the indices of cities you want to visit (space-separated, ending with -1): ";
//     std::vector<int> selectedCities;
//     int cityIndex;
//     while (std::cin >> cityIndex && cityIndex != -1) {
//         selectedCities.push_back(cityIndex);
//     }

//     if (selectedCities.size() < 2) {
//         std::cerr << "At least two cities are required to calculate the route." << std::endl;
//         return 1;
//     }

//     // Solve TSP
//     std::vector<int> optimalRoute;
//     int totalCost = solveTSP(selectedCities, distances, optimalRoute);

//     std::cout << "\nOptimal Route: ";
//     for (int city : optimalRoute) {
//         std::cout << cities[city] << " -> ";
//     }
//     std::cout << cities[optimalRoute.front()] << std::endl;  // Loop back to start
//     std::cout << "Total Travel Cost: " << totalCost << " km" << std::endl;

//     return 0;
// }
#include <iostream>
#include "tsp.h"
#include "file_handler.h"

int main() {
    std::string fileName = "data/cities.json";
    std::vector<std::string> cities;
    std::vector<std::vector<int>> distances;

    if (!loadCitiesAndDistances(fileName, cities, distances)) {
        std::cerr << "Error loading data from file!" << std::endl;
        return 1;
    }

    std::cout << "Available cities: " << std::endl;
    for (size_t i = 0; i < cities.size(); i++) {
        std::cout << i << ": " << cities[i] << std::endl;
    }

    std::cout << "\nEnter the indices of cities you want to visit (space-separated, ending with -1): ";
    std::vector<int> selectedCities;
    int cityIndex;
    while (std::cin >> cityIndex && cityIndex != -1) {
        if (cityIndex >= 0 && cityIndex < cities.size()) {
            selectedCities.push_back(cityIndex);
        } else {
            std::cout << "Invalid index. Try again: ";
        }
    }

    if (selectedCities.size() < 2) {
        std::cerr << "At least two cities are required to calculate the route." << std::endl;
        return 1;
    }

    // Solve TSP
    std::vector<int> optimalRoute;
    int totalCost = solveTSP(selectedCities, distances, optimalRoute);

    std::cout << "\nOptimal Route: ";
    for (int city : optimalRoute) {
        std::cout << cities[city] << " -> ";
    }
    std::cout << cities[optimalRoute.front()] << std::endl;  // Loop back to start
    std::cout << "Total Travel Cost: " << totalCost << " km" << std::endl;

    return 0;
}
