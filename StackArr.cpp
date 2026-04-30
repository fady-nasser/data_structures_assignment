using namespace std;
#include <iostream>
#include"Stack.h"

//Constructor
StackArray::StackArray(){
    head=-1;
    size=0;
    cout<<"Enter the size of the array";
    cin>>capacity;
}

void StackArray::push(int val){
    if(size==capacity){
        cout<<"Array is full";
    }
    else {
        head++;
        size++;
        arr[head]=val;
    }
}
int StackArray::pop(){
    if(head==-1){
    cout<<"There isn't any element in the array";
    exit(1);
    }
    else{
        int value = arr[head];
        head--;
        return value;
    }
}
int StackArray::peek(){
    if(head==-1){
        cout<<"There isn't any element in the array";
        exit(1);
    }
    else
        return arr[head];
}
bool StackArray::isEmpty(){
    if(size)
        return false;
    else
        return true;
}
StackArray::~StackArray()
{
    delete[] arr;
}
