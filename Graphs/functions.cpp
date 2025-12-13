#include "functions.h"

Edge::Edge(int dest, int c)
{
    destination = dest;
    cost = c;
} // Constructor that initializes an edge with a destination and a cost.
int Edge::getDestination()
{
    return destination;
} // Returns the destination of the edge.
int Edge::getCost()
{
    return cost;
} // Returns the cost of the edge.
Edge *Edge::getNext()
{
    return next;
} // Returns the pointer to the next edge.
void Edge::setNext(Edge *nextEdge)
{
    next = nextEdge;
} // Sets the pointer to the next edge in the list.
void Edge::setDestination(int dest)
{
    destination = dest;
} // Updates the destination of the edge.
void Edge::setCost(int c)
{
    cost = c;
}

Node::Node(int val)
{
    data = val;
    next = nullptr;
    edges = nullptr;
    edgeCount = 0;
} // Constructor that initializes a node with a specified value and sets the edges and next node pointers to nullptr while setting edgeCount to zero.
int Node::getData()
{
    return data;
} // Returns the value stored in the node.
Node *Node::getNext()
{
    return next;
} // Returns the pointer to the next node in the linked list.
Edge *Node::getEdges()
{
    return edges;
} // Returns the pointer to the head of the edges list connected to this node.
int Node::getEdgeCount()
{
    return edgeCount;
} //; Returns the number of edges associated with the node.
void Node::setNext(Node *nextNode)
{
    next = nextNode;
} // Sets the pointer to the next node in the linked list.
void Node::setEdges(Edge *edgeList)
{
    edges = edgeList;
} // Assigns a new linked list of edges to this node.
void Node::setData(int value)
{
    data = value;
} // Updates the value stored in the node.
void Node::incrementEdgeCount()
{
    edgeCount++;
} // Increments the edge count by one, called when a new edge is added.
void Node::decrementEdgeCount()
{
    edgeCount--;
} // Decrements the edge count by one, called when an edge is removed.

Graph::Graph()
{
    nodes = nullptr;
    nodeCount = 0;
} // Constructor that initializes an empty graph by setting nodes to nullptr and nodeCount to zero.
Graph::~Graph()
{

} // Destructor that cleans up memory by deleting all nodes and their associated edges to prevent memory leaks.
void Graph::addNode(int nodeValue)
{
    if (nodes != nullptr)
    {
        Node *head = nodes;
        while (head != nullptr)
        {
            if (head->getData() == nodeValue)
            {
                cout << "Duplicate Found" << endl;
                return;
            }
            head = head->getNext();
        }
    }
    Node *newNode = new Node(nodeValue);
    if (nodes == nullptr)
    {
        nodes = newNode;
        nodeCount++;
        return;
    }
    newNode->setNext(nodes);
    nodes = newNode;
    nodeCount++;
} // Adds a new node with the specified value to the graph, avoiding duplicates. It creates a new node and links it at the front of the list.
void Graph::addEdge(int source, int destination, int cost)
{
    // int data = -1;
    Node *head = nodes;
    while (head != nullptr)
    {
        if (head->getData() == source)
        {

            if (head->getEdges() != nullptr)
            {
                Edge *edge = head->getEdges();
                while (edge != nullptr)
                {
                    if (edge->getDestination() == destination)
                    {
                        cout << "dest found" << endl;
                        return;
                    }
                    // nodes->setEdges(newEdge);
                    edge = edge->getNext();
                }
                Edge *newEdge = new Edge(destination, cost);
                // Edge * = head->getEdges();
                // newEdge->setNext(edge);
                // // head = newEdge;
                // head->setEdges(newEdge);
                edge->setNext(newEdge);
                head->incrementEdgeCount();
            }
            else
            {
                Edge *newEdge = new Edge(destination, cost);
                head->setEdges(newEdge);
                head->incrementEdgeCount();
            }
        }
        head = head->getNext();
    }

} // Adds a directed edge from the source node to the destination node with an associated cost, ensuring both nodes exist and no duplicate edge exists.
int Graph::getEdgeCost(int source, int destination)
{
    bool check = true;
    Node *head = nodes;
    while (head != nullptr)
    {
        if (head->getData() == source)
        {
            check = false;
            if (head->getEdges() != nullptr)
            {
                Edge *edge = head->getEdges();
                cout << edge->getDestination() << endl;
                while (edge != nullptr)
                {
                    if (edge->getDestination() == destination)
                    {
                        cout << "Cost : " << edge->getCost() << endl;
                        return edge->getCost();
                    }
                    // nodes->setEdges(newEdge);
                    edge = edge->getNext();
                }
                cout << "Destination not Found" << endl;
                // Edge *head = nodes->getEdges();
                // newEdge->setNext(head);
                // // head = newEdge;
                // nodes->setEdges(newEdge);
                // nodes->incrementEdgeCount();
            }
            else
            {
                cout << "It doesnot have link to any other node" << endl;
                return -1;
            }
        }
        head = head->getNext();
    }
    if (check)
    {
        cout << "Source not Found" << endl;
        return -1;
    }
} // Retrieves the cost of the edge from the source node to the destination node. Returns -1 if no such edge exists.
int Graph::getEdgeCountForNode(int nodeValue)
{
    int count = -1;
    Node *head = nodes;
    while (head != nullptr)
    {
        if (head->getData() == nodeValue)
        {
            // bool check = false;
            if (head->getEdges() != nullptr)
            {
                return (head->getEdgeCount());
            }
        }
        head = head->getNext();
    }
    if (count == -1)
    {
        cout << "node doesnot exits" << endl;
        return count;
    }

} // Returns the number of edges connected to the specified node. Returns -1 if no such node exists
int Graph::getNodeCount()
{
    return nodeCount;
} // Returns the total number of nodes in the graph.
void Graph::updateNode(int oldValue, int newValue)
{
    if (!hasNode(oldValue))
    {
        cout << "Node not found" << endl;
        return;
    }
    Node *c = nodes;
    while (c != nullptr)
    {
        if (c->getData() == newValue)
        {
            cout << "This node is already availble, cant update" << endl;
            return;
        }
        c = c->getNext();
    }

    bool check = false;
    Node *head = nodes;
    while (head != nullptr) // Updating the value of node only
    {
        if (head->getData() == oldValue)
        {
            // head->setData(newValue);
            check = true;
        }
        head = head->getNext();
    }
    if (check)
    {
        Node *n = nodes;
        while (n != nullptr)
        {
            Edge *edge = n->getEdges();
            while (edge != nullptr)
            {
                cout << "Dest :" << edge->getDestination() << endl;
                if (edge->getDestination() == oldValue)
                {
                    edge->setDestination(newValue);
                }
                edge = edge->getNext();
            }

            n = n->getNext();
        }
        Node *h = nodes;
        while (h != nullptr) // Updating the value of node only
        {
            if (h->getData() == oldValue)
            {
                h->setData(newValue);
            }
            h = h->getNext();
        }
    }

} // Updates the value of a node from oldValue to newValue only if newValue node doesn’t exist. It also updates any edges pointing to oldValue to point to newValue.
void Graph::deleteNode(int nodeValue)
{

} // Removes a node from the graph and deletes all edges connected to it, ensuring that the graph maintains integrity.
bool Graph::hasNode(int nodeValue)
{
    bool check = false;
    Node *head = nodes;
    while (head != nullptr) // Updating the value of node only
    {
        if (head->getData() == nodeValue)
        {
            check = true;
            return check;
        }
        head = head->getNext();
    }
    return check;
} // Checks if a node with the specified value exists in the graph.
void Graph::deleteEdge(int source, int destination)
{
    bool check = true;
    Node *head = nodes;
    while (head != nullptr)
    {
        if (head->getData() == source)
        {
            check = false;
            if (head->getEdges() != nullptr)
            {
                Edge *edge = head->getEdges();
                cout << edge->getDestination() << endl;
                while (edge != nullptr)
                {
                    if (edge->getDestination() == destination)
                    {
                        
                        
                    }
                    // nodes->setEdges(newEdge);
                    edge = edge->getNext();
                }
                cout << "Destination not Found" << endl;
                // Edge *head = nodes->getEdges();
                // newEdge->setNext(head);
                // // head = newEdge;
                // nodes->setEdges(newEdge);
                // nodes->incrementEdgeCount();
            }
            else
            {
                cout << "It doesnot have link to any other node" << endl;
                return -1;
            }
        }
        head = head->getNext();
    }
    if (check)
    {
        cout << "Source not Found" << endl;
        return -1;
    }
} // Removes the directed edge from the source node to the destination node, if it exists.
void Graph::display()
{
} // Displays the entire graph, including each node's value, its edges, and the costs associated with those edges.