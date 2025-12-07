#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    T data;            // The data stored in the node.
    Node<T> *next;     // Pointer to the next node in the list.
    Node<T> *previous; // Pointer to the previous node in the list.
public:
    Node()
    {
        this->data = 0;
        this->next = nullptr;
        this->previous = nullptr;
    }
    ~Node()
    {
    }
    void setNext(Node<T> *val)
    {
        this->next = val;
    } // Sets the next pointer to the provided node.
    Node<T> *getNext()
    {
        return next;
    } // Returns the next node pointer.
    void setPrevious(Node<T> *val)
    {
        previous = val;
    } // Sets the previous pointer to the provided node.
    Node<T> *getPrevious()
    {
        return previous;
    } // Returns the previous node pointer.
    void setData(T data)
    {
        this->data = data;
    } // Sets the data of the node.
    T getData()
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
            newNode->setPrevious(tail);
            tail = newNode;
            count++;
        }
    } // Adds a new node with the given data at the end of the list.
    void insertAtIndex(T data, int index)
    {
        if (index < 0 || index > count)
        {
            cout << "Invalid Index" << endl;
            return;
        }

        if (index == 0)
        {
            prepend(data);
        }
        else if (index == count)
        {
            append(data);
        }
        else
        {
            Node<T> *newNode = new Node<T>();
            newNode->setData(data);
            Node<T> *prev = head;
            Node<T> *next;
            for (int i = 0; i < index - 1; i++)
            {
                prev = prev->getNext();
            }
            next = prev->getNext();
            newNode->setPrevious(prev);
            newNode->setNext(next);
            prev->setNext(newNode);
            next->setPrevious(newNode);
            count++;
            return;
        }
    } // Inserts a node with the given data at the specified index.
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
            head->setPrevious(newNode);
            head = newNode;
            count++;
        }
    } // Adds a new node with the given data at the start of the list.
    void deleteFromEnd()
    {
        Node<T> *temp = tail;
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
            // while (temp->getNext() != tail)
            // {
            //     temp = temp->getNext();
            // }
            // delete tail;
            // tail = temp;
            // tail->setNext(nullptr);
            // count--;

            tail = tail->getPrevious();
            delete temp;
            tail->setNext(nullptr);
            count--;
            return;
        }
    } // Deletes the last node in the list.
    void deleteFromIndex(int index)
    {
        if (index < 0 || index >= count)
        {
            cout << "Invalid Index" << endl;
            return;
        }

        if (index == 0)
        {
            deleteFromStart();
        }
        else if (index == count - 1)
        {
            deleteFromEnd();
        }
        else
        {
            Node<T> *toDelete;
            Node<T> *prev = head;
            Node<T> *next;
            for (int i = 0; i < index - 1; i++)
            {
                prev = prev->getNext();
            }
            toDelete = prev->getNext();
            next = toDelete->getNext();
            prev->setNext(next);
            next->setPrevious(prev);
            delete toDelete;
            count--;
            return;
        }
    } // Deletes the node at the specified index.
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
            if (head != nullptr)
                head->setPrevious(nullptr);
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
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    } // Prints List
};

#endif