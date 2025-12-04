#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

//Implement the TreeNode class
//Data Members:

class TreeNode
{
private:
    int data; //The value stored in the node.
    TreeNode** children; //Dynamic array pointer.
    int childrenCount; //Current children count.
    int capacity;
public:
    
TreeNode(int value); //Constructor to initialize the node with a given value.
TreeNode* getChild(int index); //Returns a pointer to the child.
void TreeNode::setChild(int index, TreeNode *desiredNode);
int getData(); //eturns the data stored in the node.
void setData(int d);
void addChild(TreeNode* node); //Adds a new child. Must handle array **resizing** (doubling capacity) if childrenCount reaches capacity.
int getChildrenCount();
void setChildrenCount(int n);
friend class Tree;
};

class Tree
{
private:
   // Data Members:

TreeNode* root; //Pointer to the root node of the tree.

public:

   // Member Functions to Implement:

Tree(); //Constructor to initialize the tree.
void insertNode(int parentData, int value); //Finds parent node, and adds the new node as its last child.
TreeNode* findNode(int data); //Finds and returns the node with the data otherwise return nullptr.
TreeNode* getRoot(); //Returns the root node of the tree.
int getHeight(int data); //Returns the height (the length of the longest path from this node to a leaf) of the node containing the given data.
int getDegree(int data); // Returns the degree (the number of children) of the node containing the given data.
void deleteNode(int data); // Deletes the node containing the given data while maintaining the tree structure (e.g., using predecessor/successor replacement or promoting a child).
void print_pre0rder(); // Prints the tree nodes' data using pre-order traversal (Root, Left, Right).
void print_in0rder(); // Prints the tree nodes' data using an in-order traversal (Left, Root, Right).
void print_post0rder(); // Prints the tree nodes' data using the post-order traversal (Left, Right, Root).
bool deleteNodeHelperFn(TreeNode *&root, int data);
TreeNode *findParent(int data);
};



#endif
