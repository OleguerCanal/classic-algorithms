#include "stdlib.h"
#include <iostream>
#include <stack>
#include <vector>

struct Node {
    int val;
    Node* left = NULL;
    Node* right = NULL;

    explicit Node(int data) : val(data) {}
};

struct BST {
    Node* root = NULL;
    explicit BST(Node* node) : root(node) {}

    void insert(Node* node) {
        Node* current = root;
        while (current != NULL) {
            if (node->val <= current->val) {
                if (current->left == NULL) {
                    current->left = node;
                    return;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = node;
                    return;
                }
                current = current->right;
            }
        }
    }

    void remove(int val) {
        // Node* current = root;
        // while (current != NULL) {
        //     if (val < current->val) {
        //         if 
        //     }
        // }
    }

    std::vector<Node*> ordered_nodes() {
        std::vector<Node*> ordered;
        std::stack<Node*> s;
        Node *node = root;
        while (node != NULL || !s.empty()) {
            while (node !=  NULL) {  // If there is left subtree, explore it
                s.push(node);
                node = node->left;
            }
            node = s.top();  // Otherwise, go for the top of the list
            s.pop();
            ordered.push_back(node);
            node = node->right;
        }
        return ordered;
    }

    Node* build_balanced(const std::vector<Node*>& ordered_nodes, int begin, int end) {
        if (begin > end) {
            return NULL;
        }
        int mid_ind = (begin + end)/2;
        Node* mid_node = ordered_nodes[mid_ind];
        mid_node->left = build_balanced(ordered_nodes, begin, mid_ind-1);
        mid_node->right = build_balanced(ordered_nodes, mid_ind+1, end);
        return mid_node;
    }

    void balance() {
        // OBS: Self-balancing binary search trees are better for the job (red-black tree)
        // 1. Traverse in order to get sorted array of the nodes
        std::vector<Node*> nodes = ordered_nodes();

        // 2. Build balanced tree from sortted array
        root = build_balanced(nodes, 0, nodes.size()-1);
    }

    void print() {
        std::vector<Node*> nodes = ordered_nodes();
        std::cout << "Inorder: ";
        for (auto node : nodes) {
            std::cout << node->val << " ";
        }
        std::cout << std::endl;
    }

};

int main() {
    // Construct sample graph
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);

    BST bst(n3);
    bst.insert(n1);
    bst.insert(n4);
    bst.insert(n2);
    bst.print();
    bst.balance();
    bst.print();

    // Delete graph
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
}