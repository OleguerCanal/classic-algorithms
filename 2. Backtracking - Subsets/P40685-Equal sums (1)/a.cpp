#include <iostream>
#include <vector>

template <class T>
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
  for (int i = 0; i < selections.size(); ++i)
    if (selections[i]) multiset.push_back(elems[i]);
  print_vect<int>(multiset);
}

void print_equal_sums(uint pos, uint sum, std::vector<bool> *selections,
                      const std::vector<int> &elems) {
  if (pos == elems.size()) {
    if (sum == 0) print_set(*selections, elems);
    return;
  }

  // IDEA: I can either pick or not pick elem of position pos
  int elem = elems[pos];

  // Case we pick this elem:
  selections->at(pos) = true;
  print_equal_sums(pos + 1, sum - elem, selections, elems);

  // Case we dont pick it
  selections->at(pos) = false;
  print_equal_sums(pos + 1, sum, selections, elems);
}

int main() {
  int s, n;
  std::cin >> s >> n;
  std::vector<int> elems(n);
  for (int i = 0; i < n; ++i) std::cin >> elems[i];

  std::vector<bool> selections(n, false);
  print_equal_sums(0, s, &selections, elems);
}