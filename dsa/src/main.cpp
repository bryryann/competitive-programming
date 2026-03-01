#include <iostream>
#include "./BinaryTree.cpp"

using namespace BinaryTree;

int main() {
    Node *head = new_node(0);

    std::cout << head->key << std::endl;

    return 0;
}

