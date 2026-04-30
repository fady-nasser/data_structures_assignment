#ifndef STACK_H
#define STACK_H

#include "Node.h"

class StackArray {
private:
    int* arr;
    int capacity;
    int top;

public:
    StackArray(int capacity);
    ~StackArray();

    // Operations on the stack
    void push(int val);
    int pop();
    int peek();
    bool isEmpty();
};

class StackLinkedList {
private:
    Node* top;
    int length;

public:
    StackLinkedList();
    ~StackLinkedList();

    // Operations on the stack
    void push(int val);
    int pop();
    int peek();
    bool isEmpty();
};

#endif 