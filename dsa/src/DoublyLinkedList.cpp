#include <iostream>
#include <stdlib.h>

namespace DoublyLinkedList {

struct Node {
    int key;
    Node *prev;
    Node *next;
};

Node *new_node(int key) {
    Node *node = (Node*) malloc(sizeof(Node));

    if (node) {
        node->key = key;
        node->prev = nullptr;
        node->next = nullptr;
    }

    return node;
}

void insert_back(Node **root, int key) {
    Node *node = new_node(key);

    if (*root == nullptr) {
        *root = node;
        return;
    }

    Node *current = *root;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = node;
    node->prev = current;
}

void insert_ordered(Node **root, int key) {
    Node *node = new_node(key);

    if (*root == nullptr) {
        *root = node;
        return;
    }

    if (key < (*root)->key) {
        node->next = *root;
        (*root)->prev = node;
        *root = node;
        return;
    }

    Node *current = *root;
    while (current->next != nullptr && current->next->key < key) {
        current = current->next;
    }

    if (current->next == nullptr) {
        current->next = node;
        node->prev = current;
        return;
    }

    node->next = current->next;
    node->prev = current;
    current->next->prev = node;
    current->next = node;
}

}
