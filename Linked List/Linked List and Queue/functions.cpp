#include "functions.h"

Queue::Queue()
{
    size = front = rear = 0;
    capacity = 10;
    array = new int[capacity];

} // Initializes the queue with an initial capacity of 10.
Queue::~Queue()
{
    delete array;

} // Deallocates the dynamic array to prevent memory leaks.
bool Queue::isEmpty()
{
    return ((size == 0) ? true : false);
} // Returns true if the queue is empty; otherwise, false.
bool Queue::isFull()
{
    return ((size == capacity ? true : false));
} // Returns true if the queue is full; otherwise, false.
void Queue::enqueue(int data)
{
    if (isFull())
    {
        capacity *= 2;
        int *temp = new int[capacity];
        int j = 0;
        for (int i = front; i <= rear; i++)
        {
            temp[j] = array[i];
            j++;
        }
        front = rear = 0;
        delete array;
        array = temp;
    }
    if (size ==0)
    {
        front = 0;
    }
    array[(front+size)%capacity] = data;
    size++;
    rear = (front + size - 1) % capacity;
    cout << data << " is added at rear index " << rear << endl;

} // Adds an element to the rear of the queue. If the queue is full, resize it by doubling its capacity (use a dynamic array regrow operation). Update rear and size accordingly
int Queue::peek()
{
    if (size == 0)
    {
        cout << "Array is Empty (in peek)" << endl;
        return -1;
    }
    cout << "Front is " << array[front] << endl;
    return array[front];

} // Returns the front element of the queue without removing it. If the queue is empty, print a message and return -1.
int Queue::dequeue()
{
    if (size == 0)
    {
        cout << "Array is Empty" << endl;
        return -1;
    }
    int value = array[front];
    front = (front+1) % capacity;
    size--;
    cout <<"Front Element (" << value << ") is Removed!" << endl;
    return value;
} // Removes and returns the front element of the queue. If the queue is empty, print an error message and return -1.
int Queue::getSize()
{
    return size;
} // Returns the number of elements currently in the queue.
void Queue::clear()
{

    int c = front;
    while (c!=(rear +1))
    {
        dequeue();
        c++;
    }
     cout << "Queue is cleared in clear process" << endl;
    
} // Removes all elements from the queue and resets front, rear, and size.
void Queue::printQueue()
{
    int c = front;
    while (c!= rear+1)
    {
        cout << array[c] << " ";
        c++;
    }
    cout << endl;
} // Prints all elements from front to rear in order.

Node::Node()
{
    this->data = 0;
    this->next = nullptr;
} // Initializes the node with a given data value and next = nullptr.
Node::~Node()
{
    this->next = nullptr;
} // set the next to nullptr
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

// Implement the LinkedQueue Class for Queue Implementation

LinkedQueue::LinkedQueue()
{
    front = rear = nullptr;
    size = 0;
} // Initializes front = nullptr, rear = nullptr, and size = 0.
LinkedQueue::~LinkedQueue()
{
} // Deallocates all nodes in the queue to prevent memory leaks.
bool LinkedQueue::isEmpty()
{
    return (size == 0 ? true : false);

} // Returns true if the queue is empty; otherwise, false.
void LinkedQueue::enqueue(int data)
{
    Node *newNode = new Node();
    newNode->setData(data);
    if (front == nullptr)
    {
        front = rear = newNode;
        size++;
        return;
    }
    else
    {
        rear->setNext(newNode);
        rear = newNode;
        int val = rear->getData();
        rear->setNext(nullptr);
        size++;
        cout << val << " is ADDED!" << endl;
        return;
    }

} // Creates a new node and adds it to the rear of the queue.
int LinkedQueue::dequeue()
{
    Node *toDelete = front;
    if (front == nullptr)
    {
        cout << "Linked Queue is Empty" << endl;
        return -1;
    }
    else if (size == 1)
    {
        front = rear = nullptr;
        int top = toDelete->getData();
        delete toDelete;
        size--;
        cout << "Front Element (" << top << ") is removed!" << endl;
        return top;
    }
    else
    {
        int top = front->getData();
        front = front->getNext();
        toDelete->setNext(nullptr);
        delete toDelete;
        size--;
        cout << "Front Element (" << top << ") is removed!" << endl;
        return top;
    }

} // Removes and returns the element from the front of the queue. If the queue is empty, print a message and return -1.
int LinkedQueue::peek()
{
    if (front == nullptr)
    {
        cout << "Linked Queue is Empty" << endl;
        return -1;
    }

    int top = front->getData();
    cout << "Front Element is " << top << endl;
    return top;
} // Returns the front element without removing it. If the queue is empty, print a message and return -1.
int LinkedQueue::getSize()
{
    return size;
} // Returns the number of elements currently in the queue.
void LinkedQueue::clear()
{
    Node *toDelete = front;
    while (toDelete != nullptr)
    {
        if (size == 0)
        {
            cout << "Linked List is Empty in clear process" << endl;
            break;
        }
        dequeue();
    }

} // Removes all nodes and resets the queue.
void LinkedQueue::printQueue()
{
    Node *node = front;
    while (node != nullptr)
    {
        cout << node->getData() << " ";
        node = node->getNext();
    }
    cout << endl;

} // Displays the queue’s contents from front to rear in order.