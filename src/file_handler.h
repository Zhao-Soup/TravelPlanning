#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <vector>
#include <string>

bool loadCitiesAndDistances(const std::string& fileName, std::vector<std::string>& cities, std::vector<std::vector<int>>& distances);

#endif
