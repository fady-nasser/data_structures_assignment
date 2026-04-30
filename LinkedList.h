#ifndef LINKEDLIST_H // like in the Node.h file, here we ask if node.h was defined or not
#define LINKEDLIST_H // if it wasnt define we define it

#include "Node.h"
class LinkedList{
    Node* head;
    Node* tail;
    int length;
    public:
        LinkedList();
        //Defining the methods responsible for adding nodes
        void insertAtEnd(int val);
        void insertAtHead(int val);
        void add(int val, int index);
        //Defining the methods responsible for removing nodes
        void remove_first();
        void deleteValue(int index);
        void remove_last();
        int get_length();
};

#endif