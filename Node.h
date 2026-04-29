#ifndef NODE_H // here we ask if node.h was defined or not
#define NODE_H // if it wasnt define we define it
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

#endif
