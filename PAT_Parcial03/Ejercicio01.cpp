#include "Ejercicio01.h"
#include "Node.h"  
#include <queue>

Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* lists)
{
    std::priority_queue<Node<int>*, std::vector<Node<int>*>, std::greater<Node<int>*>> minHeap;

    // Insertar el primer nodo de cada lista en el min heap
    while (lists != nullptr) {
        if (lists->value != nullptr) {
            minHeap.push(lists->value);
        }
        lists = lists->next;
    }

    // Crear un nodo ficticio para la lista resultante
    Node<int>* dummy = new Node<int>{};
    Node<int>* current = dummy;

    // Mezclar las listas
    while (!minHeap.empty()) {
        Node<int>* minNode = minHeap.top();
        minHeap.pop();

        // Agregar el nodo mínimo a la lista resultante
        current->next = minNode;
        current = current->next;

        // Insertar el siguiente nodo de la lista de donde se extrajo el nodo mínimo
        if (minNode->next != nullptr) {
            minHeap.push(minNode->next);
        }
    }

    return dummy->next;
}
