#pragma once

#include <iterator>
#include <iostream>
#include <stdlib.h>
#include <unordered_set>
#include <utility>

namespace weighted_graph
{
  struct Node
  {
    int id;
    std::unordered_set<std::pair<Node *, int>> childs;
    Node(const int v) : id(v) {}; // Member initialization

    void addChild(Node *child, int weight)
    {
      childs.insert(std::make_pair(child, weight));
    }
  };

  struct Graph
  {
    Node *origin, *destination;
    Graph(Node *start, Node *end) {
      origin = start;
      destination = end;
    }

    bool isDestination(Node *node)
    {
      return node == destination;
    }
  };
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
    Node *destination = new Node(10);

    origin->addChild(n1, 4);
    origin->addChild(n2, 2);
    origin->addChild(n3, 2);

    n1->addChild(n4, 5);
    n1->addChild(n6, 1);
    n1->addChild(origin, 1);

    n2->addChild(destination, 10);
    n4->addChild(destination, 2);

    std::cout << "Graph built" << std::endl;
    return Graph(origin, destination);
  }
} // namespace weighted_graph