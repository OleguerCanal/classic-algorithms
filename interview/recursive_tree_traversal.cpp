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

void DFS_preorder(Node* node) {
    if (node == NULL)
        return;
    std::cout << node->val << " ";
    DFS_preorder(node->left);
    DFS_preorder(node->right);
}

void DFS_inorder(struct Node *node) {
    if (node == NULL)
        return;
    DFS_inorder(node->left);
    std::cout << node->val << " ";
    DFS_inorder(node->right);
}

void DFS_postorder(struct Node *node) {
    if (node == NULL)
        return;
    DFS_postorder(node->left);
    DFS_postorder(node->right);
    std::cout << node->val << " ";
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
    std::cout << "Preorder: ";
    DFS_preorder(n1);
    std::cout << std::endl;

    std::cout << "Inorder: ";
    DFS_inorder(n1);
    std::cout << std::endl;

    std::cout << "Postorder: ";
    DFS_postorder(n1);
    std::cout << std::endl;

    BFS(n1);


    // Delete graph
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
}