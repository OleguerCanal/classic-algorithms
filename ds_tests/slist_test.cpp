#include <stdlib.h>
#include <iostream>

#include "single_link_list.hpp"
#include "utils.hpp"

using namespace custom_ds;

int main()
{
    Slist<int> list = getList();
    utils::print(list);
    std::cout << list.Contains(4) << " " << list.Contains(32) << std::endl;
    std::cout << "List has size: " << list.Size() << std::endl;
    list.Add(32);
    std::cout << "List has size: " << list.Size() << std::endl;
    std::cout << list.Contains(4) << " " << list.Contains(32) << std::endl;
}