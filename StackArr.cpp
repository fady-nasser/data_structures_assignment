using namespace std;
#include <iostream>
#include"LinkedList.h"
#include"Node.h"
#include"Stack.h"
class StackArr{
    int head=-1;
    public:
        void push(int val){
            if(head==arr.length -1){
                cout<<"Array is full";
            }
            else{
                head++;
                arr[head]=val;
            }
        }
        int pop(){
            if(head==-1){
                cout<<"There isn't any element in the array";
                return 0;
            }
            else{
                int value = arr[head];
                head--;
                return value;
            }
        }
        int peek(){
            if(head==-1){
                cout<<"There isn't any element in the array";
                return 0;
            }
            else
                return arr[head];
        }
        bool isEmpty(){
            if(head==-1)
                return true;
            else
                return false;
        }
};