#include "stdlib.h"
#include <iostream>

struct Node {
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int val) : data(val) {}
};

int main() {
    Node* n1 = new Node(1);
    std::cout << n1->data << std::endl;
}