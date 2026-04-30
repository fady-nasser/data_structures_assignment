#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
class LinkedList{
    Node* head;
    Node* tail;
    int length;
    public:
        LinkedList();
        ~LinkedList();
        // Defining the methods responsible for adding nodes
        void insertAtEnd(int val);
        void insertAtHead(int val);
        void add(int val, int index);
        // Defining the methods responsible for removing nodes
        void remove_first();
        void deleteValue(int val);
        void remove_last();
        int get_length();
        void display();
};

#endif