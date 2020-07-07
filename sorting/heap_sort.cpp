#include <stdlib.h>
#include <vector>
#include <queue>

#include "utils.hpp"

/// HEAP SORT CHARACTERISTICS
/// Average Time: O(log(n))
/// Worst Time: O(log(n))
/// Extra Space: O(n)

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