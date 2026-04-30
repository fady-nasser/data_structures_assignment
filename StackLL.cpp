#include <iostream>
#include "Stack.h"

using namespace std;

//Getter
Node* StackLinkedList::getTop(){
    return top;
}
void StackLinkedList::push(int val)
{
    top = ll.getHead();
    ll.insertAtHead(val);
}
int StackLinkedList::pop()
{
    ll.remove_first();
}
bool StackLinkedList::isEmpty()
{
    return !(ll.get_length());
}
int StackLinkedList::peek()
{
    if(!(getTop())){
        cout<<"There isn't any node in the LinkedList";
        exit(1);
    }
    else
    return getTop()->val;
}