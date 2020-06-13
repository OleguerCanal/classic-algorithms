#pragma once

#include <array>
#include <iostream>
#include <math.h>
#include <queue>
#include <stdlib.h>
#include <string>
#include <vector>

#include "graph.hpp"
#include "single_link_list.hpp"

namespace utils
{

  // HELPERS ---------------------------------------------------
  std::vector<float> get_random_vector(size_t size, int seed)
  {
    srandom(seed);
    std::vector<float> vect(size);
    for (size_t i = 0; i < size; i++)
      vect[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    return vect;
  }

  // TIMING ----------------------------------------------------
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

  // PRINTING -------------------------------------------------
  // Prints object
  template <typename T = int>
  void print(std::vector<T> vec, std::string msg = "")
  {
    if (msg != "")
      std::cout << msg << ": ";
    for (size_t i = 0; i < vec.size(); i++)
      std::cout << vec[i] << " ";
    std::cout << std::endl;
  }

  void print(single_link_list::ListNode *node)
  {
    while (node != nullptr)
    {
      std::cout << node->val << ", ";
      node = node->next;
    }
    std::cout << std::endl;
  }

  void print(graph::Graph graph)
  {
    std::queue<graph::Node *> nodes_to_visit; // Push nodes to list
    nodes_to_visit.push(graph.root);

    while (!nodes_to_visit.empty())
    {
      graph::Node *node = nodes_to_visit.front();
      nodes_to_visit.pop();
      std::cout << node->val << ", ";

      std::unordered_set<graph::Node *>::iterator it;
      for (it = node->childs.begin(); it != node->childs.end(); it++)
        nodes_to_visit.push(*it);
    }
    std::cout << std::endl;
  }
} // namespace utils
