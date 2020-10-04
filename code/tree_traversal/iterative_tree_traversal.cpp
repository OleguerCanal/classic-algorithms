#include "stdlib.h"
#include <iostream>
#include <stack>
#include <queue>

#include "binnary_tree.hpp"

using namespace binnary_tree;

void DFS_preorder(const Tree &tree) {
    std::cout << "Preorder: ";
    std::stack<Node*> s;
    s.push(tree.root);
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

void DFS_inorder(const Tree &tree) {
    std::cout << "Inorder: ";
    std::stack<Node*> s;
    Node *node = tree.root;
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

void BFS(const Tree &tree) {
    std::cout << "BFS: ";
    std::queue<Node*> s;
    s.push(tree.root);
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
    Tree tree = buildExampleBinTree();
    // Test traversals
    DFS_preorder(tree);
    DFS_inorder(tree);
    BFS(tree);
}