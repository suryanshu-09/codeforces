#ifndef COMBINATIONS_H
#define COMBINATIONS_H

#include <vector>

void generateCombinations(const std::vector<int>& nums, int start, std::vector<int>& current, std::vector<std::vector<int>>& result);
std::vector<std::vector<int>> getAllCombinations(const std::vector<int>& nums);

#endif

