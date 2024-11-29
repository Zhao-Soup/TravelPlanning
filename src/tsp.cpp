#include "tsp.h"
#include <limits>
#include <vector>
#include <algorithm>

int solveTSP(const std::vector<int>& cities, const std::vector<std::vector<int>>& distances, std::vector<int>& optimalRoute) {
    int n = cities.size();
    int fullMask = (1 << n) - 1;

    std::vector<std::vector<int>> dp(fullMask, std::vector<int>(n, std::numeric_limits<int>::max()));
    std::vector<std::vector<int>> parent(fullMask, std::vector<int>(n, -1));

    dp[1][0] = 0;  // Starting city (assume cities[0] is start)

    for (int mask = 1; mask <= fullMask; mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) continue;  // Skip if city i is not in the subset

            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;  // Skip if city j is already in the subset

                int nextMask = mask | (1 << j);
                int cost = dp[mask][i] + distances[cities[i]][cities[j]];

                if (cost < dp[nextMask][j]) {
                    dp[nextMask][j] = cost;
                    parent[nextMask][j] = i;
                }
            }
        }
    }

    // Reconstruct the optimal route
    int minCost = std::numeric_limits<int>::max();
    int lastCity = -1;
    for (int i = 1; i < n; i++) {
        int cost = dp[fullMask][i] + distances[cities[i]][cities[0]];
        if (cost < minCost) {
            minCost = cost;
            lastCity = i;
        }
    }

    optimalRoute.clear();
    int currentMask = fullMask;
    while (lastCity != -1) {
        optimalRoute.push_back(cities[lastCity]);
        int nextCity = parent[currentMask][lastCity];
        currentMask &= ~(1 << lastCity);
        lastCity = nextCity;
    }
    optimalRoute.push_back(cities[0]);  // Return to the starting city
    std::reverse(optimalRoute.begin(), optimalRoute.end());

    return minCost;
}
