#include <stdlib.h>

#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_set>


// Define a node of the graph
struct Node {
  int val;
  std::unordered_set<Node*> childs;

  Node(const int v) : val(v){};  // Member initialization
};

// Define a graph as the root node
struct Graph {
  Node* root;
  explicit Graph(Node* node) : root(node) {}

  void BFS() {
    std::queue<Node*> nodes_to_visit;  // Push nodes to list
    nodes_to_visit.push(root);

    while (!nodes_to_visit.empty()) {
      Node* node = nodes_to_visit.front();
      nodes_to_visit.pop();
      std::cout << node->val << ", ";

      std::unordered_set<Node*>::iterator it;
      for (it = node->childs.begin(); it != node->childs.end(); it++)
        nodes_to_visit.push(*it);
    }
    std::cout << std::endl;
  }

  void DFS() {
    std::stack<Node*> nodes_to_visit;
    nodes_to_visit.push(root);

    while (!nodes_to_visit.empty()) {
      Node* node = nodes_to_visit.top();
      nodes_to_visit.pop();
      std::cout << node->val << ", ";

      std::unordered_set<Node*>::iterator it;
      for (it = node->childs.begin(); it != node->childs.end(); ++it) {
        nodes_to_visit.push(*it);
      }
    }
    std::cout << std::endl;
  }

  // BFS Cheking repetition
  void noRepeatBFS() {
    std::queue<Node*> nodes_to_visit;
    std::unordered_set<Node*> visited_nodes;  // Make sure we dont repeat nodes
    nodes_to_visit.push(root);

    while (!nodes_to_visit.empty()) {
      Node* node = nodes_to_visit.front();
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
};

// Builds a graph to test the algorithms
Graph constructExampleGraph() {
  // OBS: Allocate nodes in heap so we can keep them instantiated
  // Not sure if its the best option (slower)
  Node* root = new Node(0);
  Node* n1 = new Node(1);
  Node* n2 = new Node(2);
  Node* n3 = new Node(3);
  Node* n4 = new Node(4);
  Node* n5 = new Node(5);
  Node* n6 = new Node(6);
  Node* n7 = new Node(7);
  Node* n8 = new Node(8);
  Node* n9 = new Node(9);

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

int main() {
  // Idea, define a graph and implement BFS
  Graph graph = constructExampleGraph();
  graph.BFS();  // Performs a BFS traversal of the graph, printing node values
  graph.DFS();  // Performs a DFS traversal of the graph, printing node values
  graph.noRepeatBFS();  // Performs a BFS traversal of the graph without
                        // repetitions, printing node values
}