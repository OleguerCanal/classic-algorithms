#include "stdlib.h"
#include <iostream>
#include <stack>
#include <queue>

#include "binnary_tree.hpp"

void DFS_preorder(const binnary_tree::Tree &tree) {
    std::cout << "Preorder: ";
    std::stack<binnary_tree::Node*> s;
    s.push(tree.root);
    while (!s.empty()) {
        binnary_tree::Node* node = s.top();
        s.pop();
        std::cout << node->val << " ";
        if (node->right != NULL)
            s.push(node->right);
        if (node->left != NULL)
            s.push(node->left);
    }
    std::cout << std::endl;
}

void DFS_inorder(const binnary_tree::Tree &tree) {
    std::cout << "Inorder: ";
    std::stack<binnary_tree::Node*> s;
    binnary_tree::Node *node = tree.root;
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

void BFS(const binnary_tree::Tree &tree) {
    std::cout << "BFS: ";
    std::queue<binnary_tree::Node*> s;
    s.push(tree.root);
    while (!s.empty()) {
        binnary_tree::Node* node = s.front();
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
    binnary_tree::Tree tree = binnary_tree::buildExampleBinTree();
    // Test traversals
    DFS_preorder(tree);
    DFS_inorder(tree);
    BFS(tree);
}