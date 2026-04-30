#ifndef STACK_H
#define STACK_H

#include "Node.h"

class StackArray {
private:
    int* arr;
    int capacity;
    int head;

public:
    StackArray(int size);
    ~StackArray();
    
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

    void push(int val);
    int pop();
    int peek();
    bool isEmpty();
};

#endif 