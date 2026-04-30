#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        remove_first();
    }
}

// Implementing the methods responsible for adding nodes
void LinkedList::insertAtEnd(int val)
{
    Node* newNode = new Node(val);
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    length++;

}

void LinkedList::insertAtHead(int val)
{
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;

    if (tail == nullptr)
    {
        tail = newNode;
    }
    length++;

}

void LinkedList::add(int val, int index)
{
    if (index < 0 || index > length)
    {
        cout << "Index out of bounds";
        return;
    }

    if (index == 0)
    {
        insertAtHead(val);
        return;
    }

    if (index == length)
    {
        insertAtEnd(val);
        return;
    }

    Node* newNode = new Node(val);
    Node* tmp = head;
    for (int i = 0; i < index - 1; i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    length++;
}

// Implementing the methods responsible for removing nodes
void LinkedList::remove_first()
{
    if (head == nullptr)
    {
        return;
    }

    Node* new_head = head->next;
    delete head;
    head = new_head;

    if (head == nullptr)
    {
        tail = nullptr;
    }
    length--;
}

void LinkedList::deleteValue(int val)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (head->val == val)
    {
        remove_first();
        return;
    }

    Node* prev = head;
    Node* curr = head->next;
    while (curr != nullptr)
    {
        if (curr->val == val)
        {
            prev->next = curr->next;
            if (curr == tail)
            {
                tail = prev;
            }
            delete curr;
            length--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Value not found" << endl;
}

void LinkedList::remove_last()
{
    if (length <= 1)
    {
        remove_first();
        return;
    }
    deleteValue(length - 1);
}

int LinkedList::get_length()
{
    return length;
}

void LinkedList::display()
{
    Node* tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->val;
        if (tmp->next != nullptr)
        {
            cout << " -> ";
        }
        tmp = tmp->next;
    }
    cout << endl;
}

Node* LinkedList::getHead(){
    if(!(head)){
        cout<<"The isn't any node in the LinkedList";
        exit(1);
    }
    else 
        return head;
}
