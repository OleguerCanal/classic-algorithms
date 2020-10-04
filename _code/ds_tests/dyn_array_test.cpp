#include <iostream>

#include "dyn_array.hpp"

int main() {
    size_t size = 3;
    custom_ds::DynArray<int> darray(size);

    for (size_t i = 0; i < darray.Size(); i++)
        darray[i] = i; // Testing operator

    darray.push_back(40);
    darray.push_back(41);
    darray.push_back(42);
    darray.push_back(43);
    darray.push_back(44);
    darray.push_back(45);

    darray.Print();
}