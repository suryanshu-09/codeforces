#include "combinations.h"

void generateCombinations(const std::vector<int>& nums, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    result.push_back(current); // Add the current combination to the result

    for (int i = start; i < nums.size(); ++i) {
        current.push_back(nums[i]); // Include nums[i] in the current combination
        generateCombinations(nums, i + 1, current, result); // Recursively generate combinations starting from i + 1
        current.pop_back(); // Backtrack: remove nums[i] from the current combination
    }
}

std::vector<std::vector<int>> getAllCombinations(const std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    generateCombinations(nums, 0, current, result);
    return result;
}
