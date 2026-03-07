#include <iostream>
#include <stdlib.h>

namespace CircularDoublyLinkedList {

struct Node {
    int key;
    Node *prev;
    Node *next;
};

Node* new_node(int key) {
    Node *node = (Node*) malloc(sizeof(Node));

    if (node) {
        node->key  = key;
        node->prev = nullptr;
        node->next = nullptr;
    }

    return node;
}

void insert_back(Node **root, int key) {
    Node *node = new_node(key);

    if (*root == nullptr) {
        *root = node;
        node->next = node;
        node->prev = node;
        return;
    }

    Node *tl = (*root)->prev;

    node->next = *root;
    node->prev = tl;
    tl->next = node;
    (*root)->prev = node;
}

void insert_ordered(Node **root, int key) {
    Node *node = new_node(key);

    if (*root == nullptr) {
        *root = node;
        node->next = node;
        node->prev = node;
        return;
    }

    if (key < (*root)->key) {
        Node *tl = (*root)->prev;

        node->next = *root;
        node->prev = tl;

        tl->next = node;
        (*root)->prev = node;
        *root = node;
        return;
    }

    Node *current = *root;
    while (current->next != *root && current->next->key < key) {
        current = current->next;
    }

    node->next = current->next;
    node->prev = current;
    current->next->prev = node;
    current->next = node;
}

}
