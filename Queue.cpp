#include <iostream>
#include "Queue.h"
#include "Node.h"

using namespace std;

QueueArray::QueueArray(int size)
{
    capacity = size;
    arr = new int[capacity];
    front = 0;
    rear = capacity - 1;
    count = 0;
}

QueueArray::~QueueArray()
{
    delete[] arr;
}

void QueueArray::enqueue(int val)
{
    if (isFull())
    {
        cout << "Queue is full";
        return;
    }

    rear = (rear + 1) % capacity; // Circular increment for rear index
    arr[rear] = val;
    count++;
}

int QueueArray::dequeue()
{
    if (isEmpty())
    {
        cout << "There isn't any element in the Queue";
        return 0;
    }

    int value = arr[front];
    front = (front + 1) % capacity; // Circular increment for front index
    count--;
    return value;
}

int QueueArray::peek()
{
    if (isEmpty())
    {
        cout << "There isn't any element in the Queue";
        return 0;
    }
    return arr[front];
}

bool QueueArray::isFull()
{
    return count == capacity;
}

bool QueueArray::isEmpty()
{
    return count == 0;
}

int QueueArray::get_length()
{
    return count;
}

QueueLinkedList::QueueLinkedList()
{
    front = nullptr;
    rear = nullptr;
    length = 0;
}

QueueLinkedList::~QueueLinkedList()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

void QueueLinkedList::enqueue(int val)
{
    Node* newNode = new Node(val);
    newNode->next = nullptr;

    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    length++;
}

int QueueLinkedList::dequeue()
{
    if (isEmpty())
    {
        cout << "There isn't any element in the Queue";
        return 0;
    }

    Node* tmp = front;
    int value = tmp->val;
    front = front->next;
    if (front == nullptr)
    {
        rear = nullptr;
    }
    delete tmp;
    length--;
    return value;
}

int QueueLinkedList::peek()
{
    if (isEmpty())
    {
        cout << "There isn't any element in the Queue";
        return 0;
    }
    return front->val;
}

bool QueueLinkedList::isEmpty()
{
    return front == nullptr;
}

int QueueLinkedList::get_length()
{
    return length;
}

