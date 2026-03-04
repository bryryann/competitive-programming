#include <iostream>
#include <stdlib.h>

namespace CircularLinkedList {

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
    Node *aux = *root;
    Node *node = new_node(key);

    if (*root == nullptr) {
        *root = node;
        node->next = node;
        return;
    }

    while (aux->next != *root) {
        aux = aux->next;
    }

    aux->next = node;
    node->next = *root;
}

void insert_ordered(Node **root, int key) {
    Node *node = new_node(key);

    if (*root == nullptr) {
        node->next = *root;
        *root = node;
        return;
    }

    if (key < (*root)->key) {
        Node *last = *root;

        while (last->next != *root) {
            last = last->next;
        }

        node->next = *root;
        last->next = node;
        *root = node;
        return;
    }

    Node *current = *root;
    while (current->next != *root && current->next->key < key) {
        current = current->next;
    }

    node->next = current->next;
    current->next = node;
}

void display(Node *root) {
    if (root == nullptr) {
        return;
    }

    Node *ptr = root;

    do {
        std::cout << ptr->key << " ";
        ptr = ptr->next;
    } while (ptr != root);

    std::cout << '\n';
}

}

