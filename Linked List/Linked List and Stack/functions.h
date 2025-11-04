#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

class Stack{
    int* array; //Pointer to the dynamic array storing the stack elements.
    int size; //The current size of the stack.
    int capacity; //The current capacity of stack.

    public:
    Stack(); //Initializes the stack with an initial capacity 10, allocates the dynamic array with the initial capacity, sets size to 0.
    ~Stack(); //Deallocates the dynamic array to prevent memory leaks.
    bool isEmpty(); //Returns true if the stack is empty; otherwise, false.
    void push(int data); //If the array is full, resizes it by doubling its capacity. Updates top and size accordingly.
    int pop(); //Remove and return the top element of the stack. If the stack is empty, print an error message and return -1.
    int seek(); //Returns the top element of the stack, don’t remove it from the stack. If the stack is empty, print a message and return -1.
    int getSize(); //Returns the number of elements in the stack.
    void clear(); //Removes all elements from the stack.
    void printStack(); //Prints all the elements in the stack from top to bottom.
    
};

class Node{
    int data; //The data stored in the node.
    Node* next; //Pointer to the next node in the list.

    public:
    Node();
    ~Node();
    void setNext(Node* val); //Sets the next pointer to the provided node.
    Node* getNext( ); //Returns the next node pointer.
    void setData(int data); //Sets the data of the node.
    int getData( ); //Returns the data of the node.
};

class LinkedStack{
    Node* head; //Pointer to the first node in the list.
    int size; //Tracks the number of elements currently in the stack.

    public:
    LinkedStack(); //Initializes head to nullptr and size to 0.
    ~LinkedStack(); //Deallocates the dynamic array to prevent memory leaks.
    bool isEmpty(); // Returns true if the stack is empty; otherwise, false.
    void push(int data); // Adds a new element on the top of the stack.
    int pop(); // Remove and return the element from the top of the stack (if any). Return -1 if the stack is empty.
    int seek(); // Return the top element of the stack, don’t remove it from the stack. If the stack is empty, print a message and return -1.
    int getSize(); //Returns the total number of elements currently in the stack.
    void printStack(); //Displays the stack’s contents in order.
};

#endif
