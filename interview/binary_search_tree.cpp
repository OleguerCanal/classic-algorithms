#include "stdlib.h"
#include <iostream>
#include <stack>

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

    void traverse() {
        std::cout << "Inorder: ";
        std::stack<Node*> s;
        Node *node = root;
        while (node != NULL || !s.empty()) {
            while (node !=  NULL) {  // If there is left subtree, explore it
                s.push(node);
                node = node->left;
            }
            node = s.top();  // Otherwise, go for the top of the list
            s.pop();
            std::cout << node->val << " ";
            node = node->right;
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
    bst.traverse();

    // Delete graph
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
}