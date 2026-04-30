#include "Stack.h"
#include <iostream>
using namespace std;


StackArray::StackArray(int size)
{
    capacity = size;
    arr = new int[capacity];
    head = -1;
}

StackArray::~StackArray()
{
    delete[] arr;
}

void StackArray::push(int val)
{
    if (head == capacity - 1)
    {
        cout << "Array is full" << endl;
    }
    else
    {
        head++;
        arr[head] = val;
    }
}

int StackArray::pop()
{
    if (head == -1)
    {
        cout << "There isn't any element in the array" << endl;
        return 0;
    }
    else
    {
        int value = arr[head];
        head--;
        return value;
    }
}

int StackArray::peek()
{
    if (head == -1)
    {
        cout << "There isn't any element in the array" << endl;
        return 0;
    }
    else
    {
        return arr[head];
    }
}

bool StackArray::isEmpty()
{
    return head == -1;
}