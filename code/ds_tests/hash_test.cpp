#include <iostream>

#include "hash_table.hpp"

using namespace custom_ds;

// Define hash functor
struct Hash {
  void operator()(int& elem) {} // In this case the hahs function is the identity
};


int main() {
    HashTable<int, 10, Hash> hash_table;
    hash_table.Insert(36);
    hash_table.Insert(46);
    hash_table.Insert(54);
    hash_table.Insert(12);

    hash_table.Print();

    std::cout << "Hashtable contains 46: " << hash_table.Contains(46) << std::endl;
    std::cout << "Hashtable contains 22: " << hash_table.Contains(22) << std::endl;
}