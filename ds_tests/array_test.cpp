#include <iostream>

#include "array.hpp"

int main() {
    custom_ds::Array<int, 5> array;

    for (size_t i = 0; i < array.Size(); i++)
        array[i] = i; // Testing operator
    
    for (size_t i = 0; i < array.Size(); i++)
        std::cout << array[i] << std::endl;
}