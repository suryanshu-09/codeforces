#include "combinations.h"
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> Combinations::getPermutations(const std::vector<int>& elements, int length) const {
    std::vector<std::vector<int>> permutations;
    std::vector<int> sortedElements = elements;

    // Sort the elements to get permutations in lexicographically sorted order
    std::sort(sortedElements.begin(), sortedElements.end());

    do {
        std::vector<int> currentPermutation;
        for (int i = 0; i < length; ++i) {
            currentPermutation.push_back(sortedElements[i]);
        }
        permutations.push_back(currentPermutation);
    } while (std::next_permutation(sortedElements.begin(), sortedElements.end()));

    return permutations;
}

