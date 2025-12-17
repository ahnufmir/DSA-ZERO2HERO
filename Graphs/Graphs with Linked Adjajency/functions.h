#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

class Edge
{
    // Data Members:
    int destination; // The value of the destination node this edge points to.
    int cost;        // The cost associated with traversing this edge.
    Edge *next;      // A pointer to the next edge in the linked list of edges originating from the same source node.

    // Member Functions to Implement:
    public:
    Edge(int dest, int c);         // Constructor that initializes an edge with a destination and a cost.
    int getDestination();          // Returns the destination of the edge.
    int getCost();                 // Returns the cost of the edge.
    Edge *getNext();               // Returns the pointer to the next edge.
    void setNext(Edge *nextEdge);  // Sets the pointer to the next edge in the list.
    void setDestination(int dest); // Updates the destination of the edge.
    void setCost(int c);
};

class Node
{
    int data;      // The value of the node.
    Node *next;    // pointer to the next node in the linked list of nodes.
    Edge *edges;   // A pointer to the head of the linked list of edges connected to this node.
    int edgeCount; //; The number of edges connected to this node.

    // Member Function s t  o Implement:
    public:
    Node(int val);                  // Constructor that initializes a node with a specified value and sets the edges and next node pointers to nullptr while setting edgeCount to zero.
    int getData();                  // Returns the value stored in the node.
    Node *getNext();                // Returns the pointer to the next node in the linked list.
    Edge *&getEdges();               // Returns the pointer to the head of the edges list connected to this node.
    int getEdgeCount();             //; Returns the number of edges associated with the node.
    void setNext(Node *nextNode);   // Sets the pointer to the next node in the linked list.
    void setEdges(Edge *edgeList);  // Assigns a new linked list of edges to this node.
    void setData(int value);        // Updates the value stored in the node.
    void incrementEdgeCount();       // Increments the edge count by one, called when a new edge is added.
    void decrementEdgeCount(); // Decrements the edge count by one, called when an edge is removed.
};


class Graph
{
//Data Members:
Node* nodes;// A pointer to the head of the linked list of nodes in the graph.
int nodeCount;// The total number of nodes currently in the graph.

//Member Functions to Implement:
public:
Graph();// Constructor that initializes an empty graph by setting nodes to nullptr and nodeCount to zero.
~Graph();// Destructor that cleans up memory by deleting all nodes and their associated edges to prevent memory leaks.
void addNode(int nodeValue);// Adds a new node with the specified value to the graph, avoiding duplicates. It creates a new node and links it at the front of the list.
void addEdge(int source, int destination, int cost);// Adds a directed edge from the source node to the destination node with an associated cost, ensuring both nodes exist and no duplicate edge exists.
int getEdgeCost(int source, int destination);// Retrieves the cost of the edge from the source node to the destination node. Returns -1 if no such edge exists.
int getEdgeCountForNode(int nodeValue);// Returns the number of edges connected to the specified node. Returns -1 if no such node exists
int getNodeCount();// Returns the total number of nodes in the graph.
void updateNode(int oldValue, int newValue);// Updates the value of a node from oldValue to newValue only if newValue node doesn’t exist. It also updates any edges pointing to oldValue to point to newValue.
void deleteNode(int nodeValue);// Removes a node from the graph and deletes all edges connected to it, ensuring that the graph maintains integrity.
bool hasNode(int nodeValue);// Checks if a node with the specified value exists in the graph.
void deleteEdge(int source, int destination);// Removes the directed edge from the source node to the destination node, if it exists.
void display();// Displays the entire graph, including each node's value, its edges, and the costs associated with those edges.
bool deleteFromIndex(int value, int v, Edge* &head);
void deleteFromIndexNode(int index, int count, Node* &nodes);
};
#endif
