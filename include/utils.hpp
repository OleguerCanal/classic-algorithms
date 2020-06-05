#pragma once

#include <array>
#include <iostream>
#include <math.h>
#include <queue>
#include <stdlib.h>
#include <string>
#include <vector>

#include "graph.hpp"

namespace utils
{
  const double pi = std::acos(-1);

  float sign(float v)
  {
    if (v < 0)
      return -1.f;
    if (v > 0)
      return 1.f;
    return 0.f;
  }

  // Start timer
  time_t tic()
  {
    return clock();
  }

  // Stop counting time and print timer
  void toc(time_t t, std::string print)
  {
    t = clock() - t;
    std::cout << "-->[TIME]: " << print << ": " << ((float)t) / CLOCKS_PER_SEC << '\n';
  }

  // Prints object
  void print(std::vector<int> vec)
  {
    for (size_t i = 0; i < vec.size(); i++)
      std::cout << vec[i] << " ";
    std::cout << std::endl;
  }

  void print(graph::Graph graph)
  {
    std::queue<graph::Node*> nodes_to_visit;  // Push nodes to list
    nodes_to_visit.push(graph.root);

    while (!nodes_to_visit.empty()) {
      graph::Node* node = nodes_to_visit.front();
      nodes_to_visit.pop();
      std::cout << node->val << ", ";

      std::unordered_set<graph::Node*>::iterator it;
      for (it = node->childs.begin(); it != node->childs.end(); it++)
        nodes_to_visit.push(*it);
    }
    std::cout << std::endl;
  }
} // namespace utils
