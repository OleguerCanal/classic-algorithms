#pragma once

#include <iterator>
#include <iostream>
#include <stdlib.h>
#include <unordered_set>

namespace graph
{
  struct Node
  {
    int val;
    std::unordered_set<Node *> childs;
    Node(const int v) : val(v){}; // Member initialization
  };

  struct Graph
  {
    Node* root;
    Node* destination;
    explicit Graph(Node *node) : root(node) {}
    explicit Graph(Node *origin, Node *dest) : root(origin), destination(dest) {}
  };

  // Builds a graph to test the algorithms
  Graph buildExampleTree()
  {
    // OBS: Allocate nodes in heap so we can keep them instantiated
    // Not sure if its the best option (slower)
    Node *root = new Node(0);
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);
    Node *n9 = new Node(9);

    root->childs.insert(n1);
    root->childs.insert(n2);
    root->childs.insert(n3);

    n1->childs.insert(n4);
    n2->childs.insert(n5);
    n2->childs.insert(n6);
    n5->childs.insert(n7);
    n5->childs.insert(n8);
    n5->childs.insert(n9);
    std::cout << "Tree built" << std::endl;
    return Graph(root);
  }

  // Builds a graph to test the algorithms
  Graph buildExampleGraph()
  {
    // OBS: Allocate nodes in heap so we can keep them instantiated
    // Not sure if its the best option (slower)
    Node *origin = new Node(0);
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);
    Node *n9 = new Node(9);
    Node *destination = new Node(0);

    origin->childs.insert(n1);
    origin->childs.insert(n2);
    origin->childs.insert(n3);

    n1->childs.insert(n4);
    n2->childs.insert(n5);
    n2->childs.insert(n6);
    n5->childs.insert(n7);
    n5->childs.insert(n8);
    n5->childs.insert(n9);
    std::cout << "Tree built" << std::endl;
    return Graph(origin, destination);
  }
} // namespace graph