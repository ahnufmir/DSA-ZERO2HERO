#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

class Node
{
private:
    int data;   //The data stored in the node.
    Node *next;  //Pointer to the next node in the list.
public:
    Node();
    ~Node();
    void setNext(Node* val); //Sets the next pointer to the provided node.
    Node* getNext( ); //Returns the next node pointer.
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
    void append(int data); //Adds a new node with the given data at the end of the list.
    void insertAtIndex(int index, int data);  //Inserts a new node with the given data at the specified index in the list.
    void deleteFromIndex(int index); //Deletes the node located at the specified index in the list. 
    bool search(int value); //Searches the list for a node containing the specified value and returns true if found, otherwise returns false.
    void updateAtIndex(int index, int newValue); //Updates the data of the node at the specified index with the new value provided.
    int getAtIndex(int index); //Returns the data stored in the node at the given index.
    void reverse(); //Reverses the order of nodes in the list in-place.
    int countOccurrences(int value); //Counts and returns how many times the given value appears in the list.
    void printList( ); // Prints List
};



#endif
