#ifndef NODE_H // here we ask if node.h was defined or not
#define NODE_H // if it wasnt define we define it

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

#endif
