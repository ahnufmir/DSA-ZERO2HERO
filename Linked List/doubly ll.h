#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

class Node
{
private:
    int data;   //The data stored in the node.
    Node *next;  //Pointer to the next node in the list.
    Node * prev; //Pointer to the previous node in the list.
public:
    Node();
    ~Node();
    void setNext(Node* val); //Sets the next pointer to the provided node.
    Node* getNext( ); //Returns the next node pointer.
    void setPrev(Node* val); //Sets the previous pointer to the provided node.
    Node* getPrev( ); //Returns the previous node pointer.
    void setData(int data); //Sets the data of the node.
    int getData( ); //Returns the data of the node.
};

class List
{
private:
    Node* head; //Pointer to the first node in the list.
    Node* tail; //Pointer to the last node in the list.
    int count; //The number of elements in the list.
public:
    List();  //Initializes the linked list with head, tail, and count set to nullptr or 0.
    ~List();  //Ensures all nodes are properly deleted when the list is destroyed.
    bool isEmpty(); //Returns true if the list is empty, otherwise false.
    void append(int data); //Adds a new node with the given data at the end of the list.
    void prepend(int data); //Adds a new node with the given data at the start of the list.
    void deleteFromEnd(); //Deletes the last node in the list.
    void deleteFromStart(); //Deletes the first node in the list.
    Node* getHead( ); //Returns head pointer
    Node* getTail( ); //Returns tail pointer
    void printList( ); // Prints List
};
#endif