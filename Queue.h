#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class QueueArray {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    QueueArray(int size);
    ~QueueArray();

    void enqueue(int val);
    int dequeue();
    int peek();
    bool isFull();
    bool isEmpty();
    int get_length();
};

class QueueLinkedList {
private:
    Node* front; // pointer to the first node in the queue
    Node* rear;  // pointer to the last node in the queue
    int length;  // number of elements in the queue

public:
    QueueLinkedList();  // constructor initializes an empty queue
    ~QueueLinkedList(); // destructor frees queue nodes

    void enqueue(int val); // add an element to the end of the queue
    int dequeue();         // remove and return the front element
    int peek();            // return the front element without removing it
    bool isEmpty();        // check if the queue has no elements
    int get_length();      // get the number of elements in the queue
};

#endif