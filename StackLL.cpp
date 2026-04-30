#include "Stack.h"
#include <iostream>

using namespace std;

StackLinkedList::StackLinkedList()
{
    top = nullptr;
    length = 0;
}

StackLinkedList::~StackLinkedList()
{
    while (!isEmpty())
    {
        pop();
    }
}

void StackLinkedList::push(int val)
{
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
    length++;
}

int StackLinkedList::pop()
{
    if (isEmpty())
    {
        cout << "There isn't any node in the LinkedList" << endl;
        return 0;
    }
    Node* ptr = top;
    int value = ptr->val;
    top = ptr->next;
    delete ptr;
    length--;
    return value;
}

int StackLinkedList::peek()
{
    if (isEmpty())
    {
        cout << "There isn't any node in the LinkedList" << endl;
        return 0;
    }
    return top->val;
}

bool StackLinkedList::isEmpty()
{
    return top == nullptr;
}