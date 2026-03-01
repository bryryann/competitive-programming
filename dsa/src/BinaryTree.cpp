#include <iostream>
#include <stdlib.h>

namespace BinaryTree {

struct Node {
    int key;
    Node *left;
    Node *right;
};

enum Order {
    InOrder,
    PreOrder,
    PostOrder
};

Node* new_node(int key) {
    Node *node = (Node*) malloc(sizeof(Node));

    if (node) {
        node->key   = key;
        node->left  = nullptr;
        node->right = nullptr;
    }

    return node;
}

Node* insert(Node *root, int key) {
    if (root == nullptr) {
        return new_node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

Node* find_min(Node *root) {
    while (root && root->left) {
        root = root->left;
    }

    return root;
}

Node* remove(Node *root, int key) {
    if (!root) {
        return nullptr;
    }

    if (key < root->key) {
        root->left = remove(root->left, key);
    }
    else if (key > root->key) {
        root->right = remove(root->right, key);
    }
    else {
        // No children/Não há filhos
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }

        // One child/Um filho
        if (!root->left) {
            Node *tmp = root->right;
            delete root;
            return tmp;
        }
        else if (!root->right) {
            Node *tmp = root->left;
            delete root;
            return tmp;
        }

        // Two children/Dois filhos
        Node *next = find_min(root->right);
        root->key = next->key;
        root->right = remove(root->right, next->key);
    }

    return root;
}

void display(Node *root, Order order) {
    if (!root) return;

    if (order == Order::PreOrder) {
        std::cout << root->key << " ";
    }

    display(root->left, order);

    if (order == Order::InOrder) {
        std::cout << root->key << " ";
    }

    display(root->right, order);

    if (order == Order::PostOrder) {
        std::cout << root->key << " ";
    }
}

void delete_tree(Node *root) {
    if (!root) return;

    delete_tree(root->left);
    delete_tree(root->right);

    delete root;
}

}


