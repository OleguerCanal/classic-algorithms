#include <algorithm>
#include <iostream>
#include <stdlib.h>

#include "utils.hpp"

// Good old binnary search O(log n)
int bin_search(const std::vector<int> &v, int target, int i, int j)
{
    if (j < i) // Returns -1 if not found
        return -1;

    int m = i + (j - i) / 2; // Avoid possible overflow: if doing (i+j)/2, i+j might not fit into a int32

    if (v[m] == target)
        return m;
    if (v[m] < target)
        i = m + 1;
    if (v[m] > target)
        j = m - 1;
    return bin_search(v, target, i, j);
}

// Finds the closest larger value to a given target in O(log n) 
int find_closest_larger(const std::vector<int> &v, int target, int i, int j)
{
    if (i == j) // Returns the value if not found
        return v[i];

    int m = i + (j - i) / 2; // Avoid possible overflow

    if (v[m] <= target)
        i = m + 1;
    if (v[m] > target)
        j = m;
    return find_closest_larger(v, target, i, j);
}

int main()
{
    size_t size = 20;
    int seed = 0;
    int max = 50;
    std::vector<int> v = utils::get_random_vector<int>(size, seed, max);
    for (int i = 0; i < 10; i++) v[i] = 36;

    std::sort(v.begin(), v.end());

    utils::print<int>(v);

    int target = 36;
    int target_pos = bin_search(v, target, 0, size - 1);

    std::cout << "Target: " << target << " is in pos: " << target_pos << std::endl;

    int closest_larger = find_closest_larger(v, target, 0, size - 1);

    std::cout << "Next different elem from target: " << target << " is: " << closest_larger << std::endl;
}