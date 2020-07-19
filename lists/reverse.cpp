#include <stdlib.h>
#include <iostream>

#include "single_link_list.hpp"
#include "utils.hpp"

using namespace custom_ds;

s_list_node<int>* reverseList(s_list_node<int>* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    s_list_node<int>* p_ptr = head;
    s_list_node<int>* c_ptr = head->next;
    p_ptr->next = nullptr;
    while (c_ptr != nullptr) {
        s_list_node<int>* helper_ptr = c_ptr->next;
        c_ptr->next = p_ptr;
        p_ptr = c_ptr;            
        c_ptr = helper_ptr;
    }
    return p_ptr;
}

int main()
{
    Slist<int> list = getList();
    s_list_node<int>* head = list.GetHead();
    utils::print(head);
    head = reverseList(head);
    utils::print(head);
}