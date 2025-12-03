#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

template <typename T>
class Node 
{
    //Data Members:
    T data; //The data stored in the node.
    Node<T>* next; //Pointer to the next node in the list.

//Member Functions to Implement:
    public:
    Node(); //Initializes the node with a given data value and next = nullptr.
    ~Node(); //set the next to nullptr
    void setNext(Node<T>* val); //Sets the next pointer to the provided node.
    Node<T>* getNext();// Returns the next node pointer.
    void setData(T data); //Sets the data of the node.
    T getData(); //Returns the data of the node.
};

template <typename T>
class LinkedQueue
{
    //Data Members:
    Node<T>* front; //Pointer to the first node (front of the queue).
    Node<T>* rear; //Pointer to the last node (rear of the queue).
    int size; //Stores the number of elements currently in the queue.

//Member Functions to Implement:
    public:
    LinkedQueue(); //Initializes front = nullptr, rear = nullptr, and size = 0.
    ~LinkedQueue(); //Deallocates all nodes in the queue to prevent memory leaks.
    bool isEmpty(); //Returns true if the queue is empty; otherwise, false.
    void enqueue(T data); //Creates a new node and adds it to the rear of the queue.
    T dequeue(); //Removes and returns the element from the front of the queue. If the queue is empty, print a message and return -1.
    T peek(); //Returns the front element without removing it. If the queue is empty, print a message and return -1.
    int getSize(); //Returns the number of elements currently in the queue.
    void clear(); //Removes all nodes and resets the queue.
    Node<T>* getFront();
    void printQueue(); //Displays the queue’s contents from front to rear in order.
};

//Implement the TreeNode class

class TreeNode{
//Data Members:
int data; //The value stored in the node.
TreeNode* left; //Pointer to the left child.
TreeNode* right; //Pointer to the right child.

//Member Functions to Implement:
public:
TreeNode(int value); //Constructor to initialize the node with a given value.
TreeNode* getLeftChild(); //Returns a pointer to the left child.
TreeNode* getRightChild(); //Returns a pointer to the right child.
int getData(); //Returns the data stored in the node.
void addLeftChild(TreeNode* node); //Adds a left child to the current node.
void addRightChild(TreeNode* node); //Adds a right child to the current node.
friend class Tree;
};

//Implement the Tree class
class Tree{
//Data Members:
TreeNode* root; //Pointer to the root node of the tree.
LinkedQueue<TreeNode*> q1;

//Member Functions to Implement:
public:
Tree(); //Constructor to initialize the tree.
~Tree();
void insertNode(int value); //Inserts a node into the tree using level order traversal.
int getTreeHeight(); //Returns the height of the tree.
int getHeight(int data); //Returns the height of a given node.
TreeNode* getRoot(); //Returns the root node of the tree.
int getDegree(int data);  //Returns the degree of a given node (number of children).
TreeNode* findNode(int data);  //Finds and returns the node with the data otherwise return nullptr
bool isFull();  //Returns true if every node has either 0 or 2 child.
void deleteNode(int value);
bool deleteNodeHelperFn(TreeNode *root, int data);
TreeNode *findParent(int data);
};

#endif
