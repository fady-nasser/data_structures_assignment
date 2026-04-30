using namespace std;
#include <iostream>
#include"LinkedList.h"
#include"Node.h"
#include"Stack.h"
class StackLL{

    public:
        void push(int val){
            if(isEmpty()){
                top = new Node(val);
                length++;
            }
            else{
                Node* ptr = new Node(val);
                ptr->next = top;
                top = ptr;
                length++;
                }
        }
        int pop(){
            if(length==1){
                Node* ptr = top;
                top = 0;
                int value = ptr->val;
                delete ptr;
                length--;
                return value;
            }
            else if(isEmpty()){
                cout<<"There isn't any node in the LinkedList";
                return 0;
            }
            Node* ptr = top;
            top = ptr->next;
            int value = ptr->val;
            delete ptr;
            length--;
            return value;
        }
        bool isEmpty(){
            if(top==0)
                return true;
            else
                return false;
        }
        int peek(){
            if(isEmpty()){
                cout<<"There isn't any node in the LinkedList";
                return 0;
            }
            return top->val;
        }
};