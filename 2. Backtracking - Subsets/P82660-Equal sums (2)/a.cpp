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

void print_equal_sums(int pos, int sum, const std::vector<int> &elems,
                      bool *found, std::vector<bool> *selections) {
  if (*found) return;  // If we already found a solution, stop
  if (pos == static_cast<int>(elems.size())) {
    if (sum == 0) print_set(*selections, elems);
    *found = (sum == 0);
    return;
  }

  // IDEA: I can either pick or not pick elem of position pos
  int elem = elems[pos];

  // Case we pick this elem
  // (we want to add as many values as we can to make it larger in case of tie)
  selections->at(pos) = true;
  print_equal_sums(pos + 1, sum - elem, elems, found, selections);

  // Case we dont pick it
  selections->at(pos) = false;
  print_equal_sums(pos + 1, sum, elems, found, selections);
}

int main() {
  int s, n;
  std::cin >> s >> n;
  std::vector<int> elems(n);
  for (int i = 0; i < n; ++i) std::cin >> elems[i];

  // IDEA: Sort and iterate from the biggest to smallest
  std::sort(elems.begin(), elems.end(), std::greater<int>());

  std::vector<bool> selections(n, false);
  bool found = false;
  print_equal_sums(0, s, elems, &found, &selections);
  if (!found) std::cout << "no solution" << std::endl;
}