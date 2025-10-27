#include "ll.h"

Node ::Node()
{
    this->data = 0;
    this->next = nullptr;
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
} // Returns the next node pointer.
void Node ::setData(int data)
{
    this->data = data;
} // Sets the data of the node.
int Node ::getData()
{
    return data;
} // Returns the data of the node.

// List Class Implementation

List::List()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
} // Initializes the linked list with head, tail, and count set to nullptr or 0.
List::~List()
{
    for (int i = 1; i <= count; i++)
    {
        Node *temporaryNode = head;
        head = head->getNext();
        temporaryNode->setNext(nullptr);
        delete temporaryNode;
    }

} // Ensures all nodes are properly deleted when the list is destroyed.

void List::insertAtIndex(int index, int data)
{
    if (index <0 && index > count)
    {
        cout << "Invalid Index" << endl;
        return;
    }

    Node *new_node = new Node();
     new_node->setData(data);
     new_node->setNext(nullptr);

    // Checking whether linked list is empty or not
    if (head == nullptr)
    {
        head = tail =  new_node;
        count++;
        return;
    }

    //Inserting at head
    if (index == 0)
    {
        new_node->setNext(head);
        head = new_node;
        count++;
        return;
    }

    // Inserting at tail
    if (index == count)
    {
        tail->setNext(new_node);
        tail = new_node;
        count++;
        return;
    }

    // Inserting at the middle
    Node* temp = head;
    for (int i = 0; i < index-1; i++)
    {
        temp = temp->getNext();
    }
    new_node->setNext(temp->getNext());
    temp->setNext(new_node);
    count++;   
}
 // Inserts a new node with the given data at the specified index in the list.
// void List::deleteFromIndex(int index)
// {

// } // Deletes the node located at the specified index in the list.
void List::append(int data)
{
    Node *fresh_node = new Node();
    fresh_node->setData(data);
    if (head == nullptr)
    {
        head = tail = fresh_node;
        count++;
    }
    else
    {
        tail->setNext(fresh_node);
        tail = fresh_node;
        count++;
    }

} // Adds a new node with the given data at the end of the list.
bool List::search(int value)
{
    if (head == nullptr)
    {
        cout << "List is Empty" << endl;
    }
    bool check = false;
    Node *tempNode = head;
    for (int i = 0; i < count; i++)
    {
        if (tempNode->getData() == value)
        {
            check = true;
        }
        tempNode = tempNode->getNext();
    }
    if (check)
    {
        return true;
    }
    else
    {
        return false;
    }
} // Searches the list for a node containing the specified value and returns true if found, otherwise returns false.
void List::updateAtIndex(int index, int newValue)
{
    if (index < 0 || index >= count)
    {
        cout << "Invalid Index" << endl;
        return;
    }
    if (head == nullptr)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    Node *tempNode = head;
    for (int i = 0; i < index; i++)
    {
        tempNode = tempNode->getNext();
    }
    tempNode->setData(newValue);
} // Updates the data of the node at the specified index with the new value provided.
int List::getAtIndex(int index)
{
    if (index < 0 || index >= count)
    {
        cout << "Invalid Index" << endl;
        return -1;
    }
    if (head == nullptr)
    {
        cout << "Linked List is Empty" << endl;
        return -1;
    }
    Node *tempNode = head;
    for (int i = 0; i < index; i++)
    {
        tempNode = tempNode->getNext();
    }
    return (tempNode->getData());
} // Returns the data stored in the node at the given index.
// void List::reverse()
// {

// } // Reverses the order of nodes in the list in-place.
int List::countOccurrences(int value)
{
    if (head == nullptr)
    {
        cout << "List is Empty" << endl;
    }
    int countCheck = 0;
    Node *tempNode = head;
    for (int i = 0; i < count; i++)
    {
        if (tempNode->getData() == value)
        {
            countCheck++;
        }
        tempNode = tempNode->getNext();
    }
    return countCheck;
} // Counts and returns how many times the given value appears in the list.
void List::printList()
{
    Node *tempNode = head;
    if (head == nullptr)
    {
        cout << "Linked List is Empty" << endl;
    }

    int i = 0;
    while (tempNode->getNext() != nullptr)
    {
        cout << i << " " << tempNode->getData() << endl;
        tempNode = tempNode->getNext();
    }
    cout << endl;

} // Prints List