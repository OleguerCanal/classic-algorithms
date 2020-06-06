#include "stdlib.h"
#include <iostream>
#include <stack>
#include <queue>

#include "binnary_tree.hpp"

void DFS_preorder(binnary_tree::Node *node)
{
    if (node == NULL)
        return;
    std::cout << node->val << " ";
    DFS_preorder(node->left);
    DFS_preorder(node->right);
}

void DFS_inorder(binnary_tree::Node *node)
{
    if (node == NULL)
        return;
    DFS_inorder(node->left);
    std::cout << node->val << " ";
    DFS_inorder(node->right);
}

void DFS_postorder(binnary_tree::Node *node)
{
    if (node == NULL)
        return;
    DFS_postorder(node->left);
    DFS_postorder(node->right);
    std::cout << node->val << " ";
}


int main()
{
    // Construct sample graph
    binnary_tree::Tree tree = binnary_tree::buildExampleBinTree();

    // Test traversals
    std::cout << "Preorder: ";
    DFS_preorder(tree.root);
    std::cout << std::endl;

    std::cout << "Inorder: ";
    DFS_inorder(tree.root);
    std::cout << std::endl;

    std::cout << "Postorder: ";
    DFS_postorder(tree.root);
    std::cout << std::endl;
}