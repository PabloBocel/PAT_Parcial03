#pragma once

template<typename T>
struct Node
{
    T value;
    Node* next;

    Node(T val, Node* nxt = nullptr) : value(val), next(nxt) {}
};


