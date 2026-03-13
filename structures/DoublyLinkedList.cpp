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

void sum_pairs(Node *root, int target) {
    int sum;

    Node *head = root;
    Node *tail = root;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    while (head != tail && head->prev != tail) {
        sum = head->key + tail->key;

        if (sum == target) {
            std::cout << "(" << head->key << "," << tail->key << ")\n";
            head = head->next;
            tail = tail->prev;
        }
        else if (sum < target) {
            head = head->next;
        }
        else if (sum > target) {
            tail = tail->prev;
        }
    }
}

Node* reverse_list(Node *ptr) {
    Node *tmp = nullptr;

    while (ptr != nullptr) {
        tmp = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = tmp;

        ptr = ptr->prev;
    }

    if (tmp != nullptr) {
        ptr = tmp->prev;
    }

    return ptr;
}

}
