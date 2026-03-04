#include <iostream>
#include "./LinkedList.cpp"

using namespace LinkedList;

int main() {
    Node *list = new_node(0);

    insert_ordered(&list, 1);
    insert_ordered(&list, 5);
    insert_ordered(&list, 2);
    insert_ordered(&list, 9);
    insert_ordered(&list, 7);
    insert_ordered(&list, 8);

    display(list);

    return 0;
}

