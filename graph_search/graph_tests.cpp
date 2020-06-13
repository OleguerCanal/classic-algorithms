#include <stdlib.h>

#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_set>

#include "weighted_graph.hpp"

void DFS() {
  std::stack<weighted_graph::Node*> nodes_to_visit;
  nodes_to_visit.push(root);

  while (!nodes_to_visit.empty()) {
    weighted_graph::Node* node = nodes_to_visit.top();
    nodes_to_visit.pop();
    std::cout << node->val << ", ";

    std::unordered_set<weighted_graph::Node*>::iterator it;
    for (it = node->childs.begin(); it != node->childs.end(); ++it) {
      nodes_to_visit.push(*it);
    }
  }
  std::cout << std::endl;
}

  // BFS Cheking repetition
void noRepeatBFS() {
  std::queue<weighted_graph::Node*> nodes_to_visit;
  std::unordered_set<weighted_graph::Node*> visited_nodes;  // Make sure we dont repeat nodes
  nodes_to_visit.push(root);

  while (!nodes_to_visit.empty()) {
    weighted_graph::Node* node = nodes_to_visit.front();
    nodes_to_visit.pop();
    visited_nodes.insert(node);

    std::cout << node->val << ", ";
    for (auto it = node->childs.begin(); it != node->childs.end(); ++it) {
      auto finder = visited_nodes.find(*it);
      if (finder == visited_nodes.end())  // If node not in visited set
        nodes_to_visit.push(*it);
    }
  }
  std::cout << std::endl;
}


}

int main() {
  
}