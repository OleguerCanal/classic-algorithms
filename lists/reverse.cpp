#include <stdlib.h>
#include <iostream>

#include "single_link_list.hpp"
#include "utils.hpp"

single_link_list::ListNode* reverseList(single_link_list::ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    single_link_list::ListNode* p_ptr = head;
    single_link_list::ListNode* c_ptr = head->next;
    p_ptr->next = nullptr;
    while (c_ptr != nullptr) {
        single_link_list::ListNode* helper_ptr = c_ptr->next;
        c_ptr->next = p_ptr;
        p_ptr = c_ptr;            
        c_ptr = helper_ptr;
    }
    return p_ptr;
}

int main()
{
  single_link_list::ListNode* head = single_link_list::getList();
  utils::print(head);
  head = reverseList(head);
  utils::print(head);
}