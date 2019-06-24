#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void print_vect(const std::vector<T> &vect) {
  int size = vect.size();
  std::cout << "{";
  for (int i = 0; i < size - 1; ++i) std::cout << vect[i] << ",";
  if (size > 0) std::cout << vect[size - 1];
  std::cout << "}" << std::endl;
}

void print_set(const std::vector<bool> &selections,
               const std::vector<int> &elems) {
  std::vector<int> multiset;
  for (uint i = 0; i < selections.size(); ++i)
    if (selections[i]) multiset.push_back(elems[i]);
  print_vect<int>(multiset);
}

bool print_equal_sums(int pos, int sum, std::vector<bool> *selections,
                      const std::vector<int> &elems) {
  if (pos == static_cast<int>(elems.size())) {
    if (sum == 0) print_set(*selections, elems);
    return (sum == 0);
  }

  // IDEA: I can either pick or not pick elem of position pos
  int elem = elems[pos];

  // Case we pick this elem
  // (we want to add as many values as we can to make it larger in case of tie)
  selections->at(pos) = true;
  bool status_add = print_equal_sums(pos + 1, sum - elem, selections, elems);

  // Case we dont pick it
  selections->at(pos) = false;
  bool status_dont_add =  print_equal_sums(pos + 1, sum, selections, elems);

  return (status_add || status_dont_add);
}

int main() {
  int s, n;
  std::cin >> s >> n;
  std::vector<int> elems(n);
  for (int i = 0; i < n; ++i) std::cin >> elems[i];

  // IDEA: Sort and iterate from the biggest to smallest
  std::sort(elems.begin(), elems.end(), std::greater<int>());

  std::vector<bool> selections(n, false);
  bool found = print_equal_sums(0, s, &selections, elems);
  if (!found) std::cout << "no solution" << std::endl;
}