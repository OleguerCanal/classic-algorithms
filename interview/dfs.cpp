#include <iostream>
#include <queue>
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
    std::queue<Node*> nodes_to_visit;
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

  root->childs.insert(n1);
  root->childs.insert(n2);
  root->childs.insert(n3);

  n1->childs.insert(n4);
  n3->childs.insert(n5);
  n4->childs.insert(n6);
  std::cout << "Tree built" << std::endl;
  return Graph(root);
}

int main() {
  // Idea, define a graph and implement BFS
  Graph graph = constructExampleGraph();
  graph.BFS();  // Performs a BFS traversal of the graph, printing node values
}