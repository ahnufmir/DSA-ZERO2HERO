#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    T data;        // The data stored in the node.
    Node<T> *next; // Pointer to the next node in the list.
public:
    Node()
    {
        this->data = T{};
        this->next = nullptr;
    }
    ~Node() {}
    void setNext(Node<T> *val)
    {
        this->next = val;
    } // Sets the next pointer to the provided node.
    Node<T> *getNext()
    {
        return next;
    } // Returns the next node pointer.
    void setData(T data)
    {
        this->data = data;
    } // Sets the data of the node.
    T& getData()
    {
        return data;
    } // Returns the data of the node.
};

template <typename T>
class List
{
private:
    Node<T> *head; // Pointer to the first node in the list.
    Node<T> *tail; // Pointer to the last node in the list.
    int count;     // The number of elements in the list.
public:
    List()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    } // Initializes the linked list with head, tail, and count set to nullptr or 0.
    ~List()
    {
        while (head != nullptr)
        {
            Node<T> *temp = head;
            head = head->getNext();
            delete temp;
        }
        tail = nullptr;
        count = 0;
    } // Ensures all nodes are properly deleted when the list is destroyed.
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    } // Returns true if the list is empty, otherwise false.
    void append(T data)
    {
        Node<T> *newNode = new Node<T>();
        newNode->setData(data);
        if (head == nullptr)
        {
            head = tail = newNode;
            count++;
        }
        else
        {
            tail->setNext(newNode);
            tail = newNode;
            count++;
        }
    } // Adds a new node with the given data at the end of the list.
    void prepend(T data)
    {
        Node<T> *newNode = new Node<T>();
        newNode->setData(data);
        if (head == nullptr)
        {
            head = tail = newNode;
            count++;
        }
        else
        {
            newNode->setNext(head);
            head = newNode;
            count++;
        }
    } // Adds a new node with the given data at the start of the list.
    void deleteFromEnd()
    {
        Node<T> *temp = head;
        if (head == nullptr)
        {
            cout << "No Elements in the linked list" << endl;
            return;
        }
        else if (count == 1)
        {
            delete head;
            head = tail = nullptr;
            count--;
            return;
        }

        else
        {
            while (temp->getNext() != tail)
            {
                temp = temp->getNext();
            }
            delete tail;
            tail = temp;
            tail->setNext(nullptr);
            count--;
        }
    } // Deletes the last node in the list.
    void deleteFromStart()
    {
        if (head == nullptr)
        {
            cout << "No Elements in the linked list" << endl;
            return;
        }
        else
        {
            Node<T> *temp = head;
            head = head->getNext();
            temp->setNext(nullptr);
            delete temp;
            count--;
            if (head == nullptr)
            {
                tail = nullptr;
            }
            return;
        }
    } // Deletes the first node in the list.
    Node<T> *getHead()
    {
        return head;
    } // Returns head pointer
    Node<T> *getTail()
    {
        return tail;
    } // Returns tail pointer
    void printList()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->getData() << endl;
            temp = temp->getNext();
        }
        cout << endl;
    } // Prints List
    void insertAtIndex(int index, T data)
    {
        // Chcking index validation
        if (index < 0 || index > count)
        {
            cout << "Invalid Index" << endl;
            return;
        }

        // creating new node
        Node<T> *new_node = new Node<T>();
        new_node->setData(data);
        new_node->setNext(nullptr);

        // empty list
        if (head == nullptr)
        {
            head = tail = new_node;
            count++;
            return;
        }

        // inserting at head
        if (index == 0)
        {
            new_node->setNext(head);
            head = new_node;
            count++;
            return;
        }

        // inserting at tail
        if (index == count)
        {
            tail->setNext(new_node);
            tail = new_node;
            count++;
            return;
        }

        // inserting in middle
        Node<T> *previous = head;
        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->getNext();
        }
        new_node->setNext(previous->getNext());
        previous->setNext(new_node);
        count++;
    } // Inserts a new node with the given data at the specified index in the list.

    T search(T value)
    {
        if (head == nullptr)
        {
            cout << "List is Empty" << endl;
        }
        bool check = false;
        Node<T> *tempNode = head;
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
            return false;
    } // Searches the list for a node containing the specified value and returns true if found, otherwise returns false.
    void updateAtIndex(int index, T newValue)
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

        Node<T> *tempNode = head;
        for (int i = 0; i < index; i++)
        {
            tempNode = tempNode->getNext();
        }
        tempNode->setData(newValue);
    } // Updates the data of the node at the specified index with the new value provided.
    Node<T> *getNodeAtIndex(int index)
    {
        if (index < 0 || index >= count)
            return nullptr; // safe to return nullptr
        Node<T> *temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->getNext();
        return temp;
    }
    int countOccurrences(int value)
    {
        if (head == nullptr)
        {
            cout << "List is Empty" << endl;
        }
        int countCheck = 0;
        Node<T> *tempNode = head;
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
};

#endif
