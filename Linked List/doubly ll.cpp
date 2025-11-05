#include "doubly ll.h"

Node ::Node()
{
    this->data = 0;
    this->next = nullptr;
    this->prev = nullptr;
}
Node ::~Node()
{
}
void Node ::setNext(Node *val)
{
    this->next = val;
} // Sets the next pointer to the provided node.
Node *Node ::getNext()
{
    return next;
} // Returns the previous node pointer.
void Node ::setPrev(Node *val)
{
    this->prev = val;
} // Sets the previous pointer to the provided node.
Node *Node ::getPrev()
{
    return prev;
} // Returns the next node pointer.
void Node ::setData(int data)
{
    this->data = data;
} // Sets the data of the node.
int Node ::getData()
{
    return data;
} // Returns the data of the node.

// Double List Class Implementation

List ::List()
{
    head = tail = nullptr;
    count = 0;
}

List ::~List()
{
    for (int i = 1; i <= count; i++)
    {
        Node *temporaryNode = head;
        head = head->getNext();
        temporaryNode->setNext(nullptr);
        delete temporaryNode;
    }
}

void List ::append(int data)
{
    Node *newNode = new Node();
    newNode->setData(data);
    if (head == nullptr)
    {
        head = tail = newNode;
        count++;
    }
    else
    {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        newNode->setNext(nullptr);
        tail = newNode;
        count++;
    }
}

void List ::prepend(int data)
{
    Node *newNode = new Node();
    newNode->setData(data);
    if (head == nullptr)
    {
        head = tail = newNode;
        count++;
    }
    else
    {
        head->setPrev(newNode);
        newNode->setNext(head);
        newNode->setPrev(nullptr);
        head = newNode;
        count++;
    }
}

    void List ::deleteFromEnd()
    {
        Node *forDelete = nullptr;
        if (head == nullptr)
        {
            cout << "List is Empty" << endl;
            return;
        }
        else if (head == tail)
        {
            Node *forDelete = head;
            // head->setPrev(nullptr);
            // tail->setNext(nullptr);
            head = tail = nullptr;
            delete forDelete;
            count--;    
            return;
        }
        else
        {
            forDelete = tail;
            tail = tail->getPrev();
            tail->setNext(nullptr);
            delete forDelete;
            count--;
        }
    }
