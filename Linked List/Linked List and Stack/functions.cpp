#include "functions.h"

Stack::Stack()
{
    capacity = 10;
    size = 0;
    array = new int[10];
} // Initializes the stack with an initial capacity 10, allocates the dynamic array with the initial capacity, sets size to 0.
Stack::~Stack()
{
    delete array;
} // Deallocates the dynamic array to prevent memory leaks.
bool Stack::isEmpty()
{
    if (size == 0)
    {
        return true;
    }
    else
        return false;

} // Returns true if the stack is empty; otherwise, false.
void Stack::push(int data)
{
    if (size == capacity)
    {
        capacity *= 2;
        int *temp = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = array[i];
        }
        delete array;
        array = temp;
    }
    array[size] = data; // Top
    size += 1;

} // If the array is full, resizes it by doubling its capacity. Updates top and size accordingly.
int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    int top = array[size - 1];
    size--;
    cout << "Top ( " << top << " ) is REMOVED! " << endl;
    return top;
} // Remove and return the top element of the stack. If the stack is empty, print an error message and return -1.
int Stack::seek()
{
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    int top = array[size - 1];
    cout << "Top element of the stack is " << top << endl;
    return top;
} // Returns the top element of the stack, don’t remove it from the stack. If the stack is empty, print a message and return -1.
int Stack::getSize()
{
    return size;
} // Returns the number of elements in the stack.
void Stack::clear()
{
    int s = size;
    for (int i = 0; i < s; i++)
    {
        size--;
    }
    cout << "Size of Stack is " << size << endl;

} // Removes all elements from the stack.
void Stack::printStack()
{
    cout << "Stack :" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
} // Prints all the elements in the stack from top to bottom.

//                  TASK 2

Node::Node()
{
    data = 0;
    next = nullptr;
}
Node::~Node()
{
}
void Node::setNext(Node *val)
{
    next = val;
} // Sets the next pointer to the provided node.
Node *Node::getNext()
{
    return next;
} // Returns the next node pointer.
void Node::setData(int data)
{
    this->data = data;
} // Sets the data of the node.
int Node::getData()
{
    return data;
} // Returns the data of the node.

LinkedStack::LinkedStack()
{
    head = nullptr;
    size = 0;

} // Initializes head to nullptr and size to 0.
LinkedStack::~LinkedStack()
{

} // Deallocates the dynamic array to prevent memory leaks.
bool LinkedStack::isEmpty()
{
    if (size == 0)
    {
        return true;
    }
    else
        return false;

} // Returns true if the stack is empty; otherwise, false.
void LinkedStack::push(int data)
{
    Node *node = new Node();
    node->setData(data);
    if (head == nullptr)
    {
        head = node;
        size++;
        return;
    }
    else
    {
        node->setNext(head);
        head = node;
        size++;
        return;
    }

} // Adds a new element on the top of the stack.
int LinkedStack::pop()
{
    if (head == nullptr)
    {
        cout << "Linked List is Empty" << endl;
        return -1;
    }
    else
    {
        Node *toDelete = head;
        head = head->getNext();
        int top = toDelete->getData();
        toDelete->setNext(nullptr);
        delete toDelete;
        size --;
        cout << "Top Element (" << top << ") is REMOVED!" << endl;
        return top;
    }

} // Remove and return the element from the top of the stack (if any). Return -1 if the stack is empty.
int LinkedStack::seek()
{
    if (isEmpty())
    {
        cout << "List is Empty" << endl;
        return -1;
    }
    int top = head->getData();
    cout << "Top Element is " << top << endl;
    return top;
} // Return the top element of the stack, don’t remove it from the stack. If the stack is empty, print a message and return -1.
int LinkedStack::getSize()
{
    return size;
} // Returns the total number of elements currently in the stack.
void LinkedStack::printStack()
{
    Node *node = head;
    int c = 0;
    while (c<size)
    {
        cout << node->getData() << " ";
        node = node->getNext();
        c++;
    }
    cout <<  endl;
} // Displays the stack’s contents in order.
