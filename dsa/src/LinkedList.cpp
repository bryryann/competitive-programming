#include <iostream>
#include <stdlib.h>

namespace LinkedList {

struct Node {
    int key;
    Node *next;
};

Node* new_node(int key) {
    Node *node = (Node*) malloc(sizeof(Node));

    if (node) {
        node->key  = key;
        node->next = nullptr;
    }

    return node;
}

void insert_back(Node **root, int key) {
    if (*root == nullptr) {
        *root = new_node(key);
        return;
    }

    Node *aux = *root;
    while (aux->next != nullptr) {
        aux = aux->next;
    }

    aux->next = new_node(key);
}

void insert_ordered(Node **root, int key) {
    Node *node = new_node(key);

    if (root == nullptr || key < (*root)->key) {
        node->next = *root;
        *root = node;
        return;
    }

    Node *current = *root;
    while (current->next != nullptr && current->next->key < key) {
        current = current->next;
    }

    node->next = current->next;
    current->next = node;
}

void display(Node *node) {
    if (node != nullptr) {
        std::cout << node->key << " ";
        display(node->next);
    }

    std::cout << '\n';
}

}

