#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
    cout << "Linked List Tests" << endl;
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtHead(5);
    list.insertAtEnd(20);
    cout << "List after inserts: ";
    list.display();
    list.deleteValue(20);
    cout << "List after delete value 20: ";
    list.display();
    list.add(15, 1);
    cout << "List after add 15 at index 1: ";
    list.display();
    cout << "Length: " << list.get_length() << endl << endl;

    cout << "Stack Array Tests" << endl;
    StackArray sArr(3);
    sArr.push(1);
    sArr.push(2);
    sArr.push(3);
    cout << "Top: " << sArr.peek() << endl;
    cout << "Pop: " << sArr.pop() << endl;
    cout << "After pop top: " << sArr.peek() << endl;
    sArr.push(4);
    cout << "Push after pop, top: " << sArr.peek() << endl << endl;

    cout << "Stack Linked List Tests" << endl;
    StackLinkedList sLL;
    sLL.push(10);
    sLL.push(20);
    sLL.push(30);
    cout << "Top: " << sLL.peek() << endl;
    cout << "Pop: " << sLL.pop() << endl;
    cout << "New top: " << sLL.peek() << endl << endl;

    cout << "Queue Array Tests" << endl;
    QueueArray qArr(3);
    qArr.enqueue(100);
    qArr.enqueue(200);
    qArr.enqueue(300);
    cout << "Front: " << qArr.peek() << endl;
    cout << "Dequeue: " << qArr.dequeue() << endl;
    qArr.enqueue(400);
    cout << "Front after enqueue 400: " << qArr.peek() << endl;
    cout << "Queue isFull: " << (qArr.isFull() ? "true" : "false") << endl;
    cout << "Queue length: " << qArr.get_length() << endl << endl;

    cout << "Queue Linked List Tests" << endl;
    QueueLinkedList qLL;
    qLL.enqueue(500);
    qLL.enqueue(600);
    qLL.enqueue(700);
    cout << "Front: " << qLL.peek() << endl;
    cout << "Dequeue: " << qLL.dequeue() << endl;
    cout << "New front: " << qLL.peek() << endl;
    cout << "Queue length: " << qLL.get_length() << endl;

    return 0;
}