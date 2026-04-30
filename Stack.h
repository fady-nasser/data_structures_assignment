#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"
#include "Node.h"

class StackArray {
    private:
        int size;
        int* arr =  new int[capacity];
        int capacity;
        int head;

    public:
        StackArray();
        ~StackArray();
        //Operation on the stack
        void push(int val);
        int pop();
        int peek();
        bool isEmpty();
};

class StackLinkedList {
    LinkedList ll;
    private:
        Node* top;

    public:
        Node* getTop();
        //Operations on the stack
        void push(int val);
        int pop();
        int peek();
        bool isEmpty();
};

#endif 