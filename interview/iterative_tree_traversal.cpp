#include "stdlib.h"
#include <iostream>
#include <stack>
#include <queue>

struct Node {
    int val;
    Node* left = NULL;
    Node* right = NULL;

    explicit Node(int data) : val(data) {}
};

void DFS_preorder(Node* root) {
    std::cout << "Preorder: ";
    std::stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* node = s.top();
        s.pop();
        std::cout << node->val << " ";
        if (node->right != NULL)
            s.push(node->right);
        if (node->left != NULL)
            s.push(node->left);
    }
    std::cout << std::endl;
}

void DFS_inorder(struct Node *root) {
    std::cout << "Postorder: ";
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

void DFS_postorder(struct Node *root) {
    std::cout << "Inorder: ";
    std::stack<Node*> s;
    Node *node = root;
    while (node != NULL || !s.empty()) {
        while (node !=  NULL) {  // If there is left subtree, explore it
            s.push(node);
            node = node->right;
        }
        node = s.top();  // Otherwise, go for the top of the list
        s.pop();
        std::cout << node->val << " ";
        node = node->left;
    }
    std::cout << std::endl;
}

void BFS(Node* root) {
    std::cout << "BFS: ";
    std::queue<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* node = s.front();
        s.pop();
        std::cout << node->val << " ";
        if (node->left != NULL)
            s.push(node->left);
        if (node->right != NULL)
            s.push(node->right);
    }
    std::cout << std::endl;
}

int main() {
    // Construct sample graph
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

    // Test traversals
    DFS_preorder(n1);
    DFS_inorder(n1);
    DFS_postorder(n1);
    BFS(n1);


    // Delete graph
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
}