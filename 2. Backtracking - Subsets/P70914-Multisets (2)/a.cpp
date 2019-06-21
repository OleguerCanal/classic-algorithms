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

void print_multisets(uint pos, const uint &x, const uint &y,
                     std::vector<uint> *appearances) {
  if (pos == appearances->size()) {
    print_multiset(*appearances);
    return;
  }
  for (uint i = x; i <= y; ++i) {
    appearances->at(pos) = i;
    print_multisets(pos + 1, x, y, appearances);
  }
}

int main() {
  uint n, x, y;
  std::cin >> n >> x >> y;
  std::vector<uint> appearances(n);
  print_multisets(0, x, y, &appearances);
}