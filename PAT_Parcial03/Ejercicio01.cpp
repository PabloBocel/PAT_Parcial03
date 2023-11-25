#include "Ejercicio01.h"
#include <queue>

Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* lists)
{
    auto compare = [](const Node<int>* a, const Node<int>* b) {
        return a->value < b->value;
        };

    std::priority_queue<Node<int>*, std::vector<Node<int>*>, decltype(compare)> minHeap(compare);

    Node<Node<int>*>* currentList = lists;
    while (currentList != nullptr) {
        if (currentList->value != nullptr) {
            minHeap.push(currentList->value);
        }
        currentList = currentList->next;
    }

    Node<int>* dummy = new Node<int>(0);
    Node<int>* current = dummy;

    while (!minHeap.empty()) {
        Node<int>* node = minHeap.top();
        minHeap.pop();

        current->next = new Node<int>{ node->value, nullptr };
        current = current->next;

        if (node->next) {
            minHeap.push(node->next);
        }
    }

    current->next = nullptr;

    return dummy->next;
}







