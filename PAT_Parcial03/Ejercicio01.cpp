#include "Ejercicio01.h"
#include <queue>

Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* lists)
{
    struct CompareNodes {
        bool operator()(const Node<int>* a, const Node<int>* b) {
            return a->value > b->value;
        }
    };

    std::priority_queue<Node<int>*, std::vector<Node<int>*>, CompareNodes> minHeap;

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
        Node<int>* minNode = minHeap.top();
        minHeap.pop();

        current->next = new Node<int>{ minNode->value, nullptr };
        current = current->next;

        if (minNode->next != nullptr) {
            minHeap.push(minNode->next);
        }
    }

    return dummy->next;
}







