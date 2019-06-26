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
  std::vector<uint> positions;
  for (uint i = 0; i < selections.size(); ++i) {
    if (selections[i]) multiset.push_back(elems[i]);
    if (selections[i]) positions.push_back(i);
  }
  print_vect<int>(multiset);
}

void print_equal_sums(int pos, int sum, const std::vector<int> &elems,
                      const std::vector<int> &acc,
                      std::vector<bool> *selections) {
  if (pos == static_cast<int>(elems.size()) && sum == 0)
    print_set(*selections, elems);

  // Crop branches:
  // if reached limit
  // if already surpassed max
  // if even with all the rest its impossible to sum
  if (pos == static_cast<int>(elems.size()) || sum < 0 || sum - acc[pos] > 0)
    return;

  // IDEA: I can either pick or not pick elem of position pos
  int elem = elems[pos];

  // Case we pick this elem
  selections->at(pos) = true;
  print_equal_sums(pos + 1, sum - elem, elems, acc, selections);

  // Case we dont pick it
  selections->at(pos) = false;
  print_equal_sums(pos + 1, sum, elems, acc, selections);
}

int main() {
  int s, n;
  std::cin >> s >> n;
  std::vector<int> elems(n), acc(n);
  for (int i = 0; i < n; ++i) std::cin >> elems[i];

  // IDEA: Apply backtracking with a lot of branch cropping
  std::sort(elems.begin(), elems.end());
  acc[n - 1] = elems[n - 1];
  for (int i = n - 2; i >= 0; --i) acc[i] = acc[i + 1] + elems[i];

  std::vector<bool> selections(n, false);
  print_equal_sums(0, s, elems, acc, &selections);
}
