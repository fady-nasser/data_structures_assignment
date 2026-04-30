#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}
//Implementing the methods responsible for adding nodes
void LinkedList::insertAtEnd(int val)
{
    Node *newNode = new Node;
    newNode->val = val;
    newNode->next = nullptr;
    tail->next = newNode;
    tail = newNode;
    length++;
    return;
}

void LinkedList::insertAtHead(int val)
{
    Node *newNode = new Node;
    newNode->val = val;
    newNode->next = head;
    head = newNode;
    length++;
    return;
}

void LinkedList::add(int val, int index)
{
    if(index >= length)
    {
        cout << "Index out of bounds";
        return;
    }
    //Checking if we can take an easier route
    else if(index == length - 1)
    {
        insertAtEnd(val);
        return;
    }
    else if(index == 0)
    {
        insertAtHead(val);
        return;
    }
    //Add the new Node
    Node *newNode = new Node;
    newNode->val = val;
    Node* tmp = head;
    for(int i=0; i<length; i++)
    {
        tmp = tmp->next;
        if(i == index-1)
        {
            newNode->next = tmp->next;
            tmp->next = newNode;
            length++;
            return;
        }
    }
}


//Implementing the methods responsible for removing nodes
void LinkedList::remove_first()
{
    Node* new_head = head->next;
    delete head;
    head = new_head;
    return;
}

void LinkedList::deleteValue(int index)
{
    if(index >= length)
    {
        cout << "Index out of bounds";
        return;
    }
    //Checking if we can take an easier route
    if(index == 0)
    {
        remove_first();
        return;
    }
    //Removing the node
    Node* tmp = head;
    Node* before_tmp = head;
    for(int i = 0; i < length; i++)
    {
        before_tmp = before_tmp->next;
        if(i == index-1)
        {
            tmp = before_tmp->next;
            before_tmp->next = tmp->next;
            delete tmp;
            length--;
            return;
        }
    }
}

void LinkedList::remove_last()
{
    deleteValue(length-1);
    return;
}

int LinkedList::get_length()
{
    return length;
}
