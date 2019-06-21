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

void print_multiset(const std::vector<uint> &appearances) {
  std::vector<uint> multiset;
  for (uint i = 0; i < appearances.size(); ++i)
    for (uint j = 0; j < appearances[i]; ++j) multiset.push_back(i + 1);
  print_vect<uint>(multiset);
}

void print_multisets(uint pos, uint t,
                     std::vector<uint> *appearances) {
  if (t == 0) {
    print_multiset(*appearances);
    return;
  }
  if (pos == appearances->size()) return;

  for (uint i = 0; i <= t; ++i) {
    appearances->at(pos) = i;
    print_multisets(pos + 1, t - i, appearances);
    appearances->at(pos) = 0;
  }
}

int main() {
  uint n, t;
  std::cin >> n >> t;
  std::vector<uint> appearances(n);
  print_multisets(0, t, &appearances);
}