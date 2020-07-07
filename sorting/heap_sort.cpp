#include <stdlib.h>
#include <vector>
#include <queue>

#include "utils.hpp"

/// BUBBLE SORT CHARACTERISTICS
/// Average Time: O(n^2)
/// Worst Time: O(n^2)
/// Space: O(1)

void heap_sort(std::vector<int> *vect)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (size_t i = 0; i < vect->size(); i++)
    {
        pq.push(vect->at(i));
    }

    for (size_t i = 0; i < vect->size(); i++)
    {
        vect->at(i) = pq.top();
        pq.pop();
    }
}

int main()
{
    std::vector<int> vect = {4, 6, 2, 5, 1, 8, 4, 0, 2, 11, 6};
    heap_sort(&vect);
    utils::print(vect);
    return 0;
}