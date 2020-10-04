#pragma once

#include <iterator>
#include <iostream>
#include <stdlib.h>
#include <unordered_set>

namespace binnary_tree
{
  struct Node {
      int val;
      Node* left = NULL;
      Node* right = NULL;
      explicit Node(int data) : val(data) {}
  };

  struct Tree
  {
    Node *root;
    explicit Tree(Node *node) : root(node) {}
  };

  // Builds a graph to test the algorithms
  Tree buildExampleBinTree()
  {
    // OBS: Allocate nodes in heap so we can keep them instantiated
    // Not sure if its the best option (slower)
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    std::cout << "Tree built" << std::endl;
    return Tree(n1);
  }
} // namespace binnary_tree