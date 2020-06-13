#pragma once

#include <stdlib.h>

namespace single_link_list
{
  // Definition for singly-linked list.
  struct ListNode
  {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode *getList()
  {
    ListNode* node_1 = new ListNode(1);
    ListNode* node_2 = new ListNode(2);
    ListNode* node_3 = new ListNode(3);
    ListNode* node_4 = new ListNode(4);
    ListNode* node_5 = new ListNode(5);
    ListNode* node_6 = new ListNode(6);
    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = node_5;
    node_5->next = node_6;
    return node_1;
  }
} // namespace single_link_list