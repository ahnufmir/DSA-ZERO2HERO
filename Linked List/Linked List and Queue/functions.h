#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

class Queue{
//Data Members:
    int* array; //Pointer to the dynamic array storing the queue elements.
    int front; //Index of the front element in the queue.
    int rear; //Index where the next element will be inserted.
    int size; //The current number of elements in the queue.
    int capacity; //The current capacity of the queue.

    public:
    Queue(); //Initializes the queue with an initial capacity of 10.
    ~Queue(); //Deallocates the dynamic array to prevent memory leaks.
    bool isEmpty(); //Returns true if the queue is empty; otherwise, false.
    bool isFull(); //Returns true if the queue is full; otherwise, false.
    void enqueue(int data); //Adds an element to the rear of the queue. If the queue is full, resize it by doubling its capacity (use a dynamic array regrow operation). Update rear and size accordingly
    int dequeue(); //Removes and returns the front element of the queue. If the queue is empty, print an error message and return -1.
    int peek(); //Returns the front element of the queue without removing it. If the queue is empty, print a message and return -1.
    int getSize(); //Returns the number of elements currently in the queue.
    void clear(); //Removes all elements from the queue and resets front, rear, and size.
    void printQueue(); //Prints all elements from front to rear in order.
};

class Node 
{
    //Data Members:
    int data; //The data stored in the node.
    Node* next; //Pointer to the next node in the list.

//Member Functions to Implement:
    public:
    Node(); //Initializes the node with a given data value and next = nullptr.
    ~Node(); //set the next to nullptr
    void setNext(Node *val); //Sets the next pointer to the provided node.
    Node* getNext();// Returns the next node pointer.
    void setData(int data); //Sets the data of the node.
    int getData(); //Returns the data of the node.
};

class LinkedQueue
{
    //Data Members:
    Node* front; //Pointer to the first node (front of the queue).
    Node* rear; //Pointer to the last node (rear of the queue).
    int size; //Stores the number of elements currently in the queue.

//Member Functions to Implement:
    public:
    LinkedQueue(); //Initializes front = nullptr, rear = nullptr, and size = 0.
    ~LinkedQueue(); //Deallocates all nodes in the queue to prevent memory leaks.
    bool isEmpty(); //Returns true if the queue is empty; otherwise, false.
    void enqueue(int data); //Creates a new node and adds it to the rear of the queue.
    int dequeue(); //Removes and returns the element from the front of the queue. If the queue is empty, print a message and return -1.
    int peek(); //Returns the front element without removing it. If the queue is empty, print a message and return -1.
    int getSize(); //Returns the number of elements currently in the queue.
    void clear(); //Removes all nodes and resets the queue.
    void printQueue(); //Displays the queue’s contents from front to rear in order.
};

#endif
