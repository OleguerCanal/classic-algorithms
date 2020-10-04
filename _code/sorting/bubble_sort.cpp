#include <stdlib.h>
#include <vector>

#include "utils.hpp"

/// BUBBLE SORT CHARACTERISTICS
/// Average Time: O(n^2)
/// Worst Time: O(n^2)
/// Space: O(1)

void bubble_sort(std::vector<int> *vect)
{
  bool change = true;
  while (change)
  {
    change = false;
    for (size_t i = 0; i < vect->size() - 1; i++)
    {
      if (vect->at(i) > vect->at(i + 1))
      {
        std::swap(vect->at(i), vect->at(i + 1));
        change = true;
      }
    }
  }
}

int main()
{
  std::vector<int> vect = {4, 6, 2, 5, 1, 8, 4, 0, 2, 11, 6};
  bubble_sort(&vect);
  utils::print(vect);
  return 0;
}