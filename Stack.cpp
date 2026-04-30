#include <iostream>
#include "Stack.h"
using namespace std;

// Array-based stack implementation
StackArray::StackArray(int capacity) : capacity(capacity), top(-1) {
    arr = new int[capacity];
}

StackArray::~StackArray() {
    delete[] arr;
}

void StackArray::push(int val) {
    if (top + 1 == capacity) {
        cout << "Stack overflow: cannot push " << val << endl;
        return;
    }
    arr[++top] = val;
}

int StackArray::pop() {
    if (isEmpty()) {
        cout << "Stack underflow: cannot pop" << endl;
        return 0;
    }
    return arr[top--];
}

int StackArray::peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return arr[top];
}

bool StackArray::isEmpty() {
    return top == -1;
}

// Linked-list-based stack implementation
StackLinkedList::StackLinkedList() : top(nullptr), length(0) {}

StackLinkedList::~StackLinkedList() {
    while (!isEmpty()) {
        pop();
    }
}

void StackLinkedList::push(int val) {
    Node* node = new Node(val);
    node->next = top;
    top = node;
    length++;
}

int StackLinkedList::pop() {
    if (isEmpty()) {
        cout << "Stack underflow: cannot pop" << endl;
        return 0;
    }
    int value = top->val;
    Node* temp = top;
    top = top->next;
    delete temp;
    length--;
    return value;
}

int StackLinkedList::peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return top->val;
}

bool StackLinkedList::isEmpty() {
    return top == nullptr;
}
