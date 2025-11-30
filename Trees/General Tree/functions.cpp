#include "functions.h"

template <typename T>
Node<T>::Node()
{
    this->data = T{};
    this->next = nullptr;
} // Initializes the node with a given data value and next = nullptr.

template <typename T>
Node<T>::~Node()
{
    this->next = nullptr;
} // set the next to nullptr

template <typename T>
void Node<T>::setNext(Node<T> *val)
{
    next = val;
} // Sets the next pointer to the provided node.

template <typename T>
Node<T> *Node<T>::getNext()
{
    return next;
} // Returns the next node pointer.

template <typename T>
void Node<T>::setData(T data)
{
    this->data = data;
} // Sets the data of the node.

template <typename T>
T Node<T>::getData()
{
    return data;
} // Returns the data of the node.

// Implement the LinkedQueue Class for Queue Implementation

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
    front = rear = nullptr;
    size = 0;
} // Initializes front = nullptr, rear = nullptr, and size = 0.

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
} // Deallocates all nodes in the queue to prevent memory leaks.

template <typename T>
bool LinkedQueue<T>::isEmpty()
{
    return (size == 0 ? true : false);

} // Returns true if the queue is empty; otherwise, false.

template <typename T>
void LinkedQueue<T>::enqueue(T data)
{
    Node<T> *newNode = new Node<T>();
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
        T val = rear->getData();
        rear->setNext(nullptr);
        size++;
        // cout << val << " is ADDED!" << endl;
        return;
    }

} // Creates a new node and adds it to the rear of the queue.

template <typename T>
T LinkedQueue<T>::dequeue()
{
    Node<T> *toDelete = front;
    if (front == nullptr)
    {
        cout << "Linked Queue is Empty" << endl;
        return nullptr;
    }
    else if (size == 1)
    {
        front = rear = nullptr;
        T top = toDelete->getData();
        delete toDelete;
        size--;
        // cout << "Front Element (" << top << ") is removed!" << endl;
        return top;
    }
    else
    {
        T top = front->getData();
        front = front->getNext();
        toDelete->setNext(nullptr);
        delete toDelete;
        size--;
        // cout << "Front Element (" << top << ") is removed!" << endl;
        return top;
    }

} // Removes and returns the element from the front of the queue. If the queue is empty, print a message and return -1.

template <typename T>
T LinkedQueue<T>::peek()
{
    if (front == nullptr)
    {
        cout << "Linked Queue is Empty" << endl;
        return nullptr;
    }

    T top = front->getData();
    cout << "Front Element is " << top << endl;
    return top;
} // Returns the front element without removing it. If the queue is empty, print a message and return -1.

template <typename T>
int LinkedQueue<T>::getSize()
{
    return size;
} // Returns the number of elements currently in the queue.

template <typename T>
void LinkedQueue<T>::clear()
{
    Node<T> *toDelete = front;
    while (toDelete != nullptr)
    {
        if (size == 0)
        {
            cout << "Linked List is Empty in clear process" << endl;
            break;
        }
        dequeue();
        toDelete = toDelete->getNext();
    }

} // Removes all nodes and resets the queue.

template <typename T>
void LinkedQueue<T>::printQueue()
{
    Node<T> *node = front;
    while (node != nullptr)
    {
        cout << node->getData() << " ";
        node = node->getNext();
    }
    cout << endl;

} // Displays the queue’s contents from front to rear in order.

template <typename T>
Node<T> *LinkedQueue<T>::getFront()
{
    return front;
}

TreeNode::TreeNode(int value)
{
    data = value;
    left = nullptr;
    right = nullptr;
    // TreeNode* newNode = new TreeNode(value);
} // Constructor to initialize the node with a given value.

TreeNode *TreeNode::getLeftChild()
{
    return left;
} // Returns a pointer to the left child.

TreeNode *TreeNode::getRightChild()
{
    return right;
} // Returns a pointer to the right child.

int TreeNode::getData()
{
    return data;
} // Returns the data stored in the node.

void TreeNode::addLeftChild(TreeNode *node)
{
    left = node;
} // Adds a left child to the current node.

void TreeNode::addRightChild(TreeNode *node)
{
    right = node;
} // Adds a right child to the current node.

Tree::Tree()
{
    root = nullptr;
} // Constructor to initialize the tree.

Tree::~Tree()
{
}
// Inserts a node into the tree using level order traversal.
void Tree::insertNode(int value)
{
    TreeNode *newNode = new TreeNode(value);
    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    q1.clear();
    q1.enqueue(root);
    while (q1.getSize() > 0)
    {
        TreeNode *front = q1.dequeue();
        // cout << front->getData() << endl;
        if (front->getLeftChild() == nullptr)
        {
            front->addLeftChild(newNode);
            return;
        }
        else
        {
            q1.enqueue(front->getLeftChild());
        }

        if (front->getRightChild() == nullptr)
        {
            front->addRightChild(newNode);
            return;
        }
        else
        {
            q1.enqueue(front->getRightChild());
        }
    }
}

// int treeHeightHelperFunction(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return 0;
//     }
//     // int leftTree = treeHeightHelperFunction(root->getLeftChild());
//     // int rightTree = treeHeightHelperFunction(root->getRightChild());
//     // return (leftTree + rightTree);
//     int size = size + 1;

//     return size;

//     // if ((root->getLeftChild() != nullptr) || (root->getRightChild() != nullptr))
//     // {

//     // }
// }

int Tree::getTreeHeight()
{
    // int size = 0;
    //    return(treeHeightHelperFunction(root));
    if (root == nullptr)
    {
        return 0;
    }
    q1.clear();
    q1.enqueue(root);
    int levelOrder = -1;
    while (q1.getSize() > 0)
    {
        int levelSize = q1.getSize();
        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *front = q1.dequeue();
            if (front->getLeftChild() != nullptr)
            {
                q1.enqueue(front->getLeftChild());
            }

            if (front->getRightChild() != nullptr)
            {
                q1.enqueue(front->getRightChild());
            }
        }
        levelOrder++;
    }
    return levelOrder;
} // Returns the height of the tree.
int Tree::getHeight(int data)
{
    if (root == nullptr)
    {
        return 0;
    }
    q1.clear();
    q1.enqueue(root);
    int levelOrder = 0;
    bool check = false;
    while (q1.getSize() > 0)
    {
        int levelSize = q1.getSize();
        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *front = q1.dequeue();
            if (data == front->getData())
            {
                check = true;
                break;
            }

            if (front->getLeftChild() != nullptr)
            {
                q1.enqueue(front->getLeftChild());
            }

            if (front->getRightChild() != nullptr)
            {
                q1.enqueue(front->getRightChild());
            }
        }
        if (check)
        {
            break;
        }
        else
            levelOrder++;
    }
    if (!check)
    {
        return -1;
    }

    int height = getTreeHeight();
    return (height - levelOrder);

} // Returns the height of a given node.
TreeNode *Tree::getRoot()
{
    return root;
} // Returns the root node of the tree.
void Tree::deleteNode(int value)
{

} // deletes the node with the given value by replacing it with the last leaf node and then deleting it.
// int getDegreeHelperFunc(TreeNode* root, int data){
//     if (root==nullptr)
//     {
//         return 0;
//     }
//     int left = getDegreeHelperFunc(root->getLeftChild(),data);
//     int right = getDegreeHelperFunc(root->getRightChild(),data);
//     if (root->getData()==data)
//     {
//         return (left+right);
//     }
//     return((left+right)+1);
// }
int Tree::getDegree(int data)
{
    //return getDegreeHelperFunc(this->root, data);
     if (root == nullptr)
    {
        return -1;
    }
    q1.clear();
    q1.enqueue(root);
    // int levelOrder = -1;
    bool validDataCheck = false; 
    int check = 0;
    while (q1.getSize() > 0)
    {
        TreeNode *front = q1.dequeue();
        if (front->getLeftChild() != nullptr)
        {
            q1.enqueue(front->getLeftChild());
            if (data == front->getData())
            {
                check++;
            }
            
        }

        if (front->getRightChild() != nullptr)
        {
            q1.enqueue(front->getRightChild());
               if (data == front->getData())
            {
                check++;
            }
        }

        if (front->getData()==data){
            validDataCheck = true;
        }
    }
    if (!validDataCheck)
    {
        return -1;
    }
    return check;
} // Returns the degree of a given node (number of children).
TreeNode *Tree::findNode(int data)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    q1.clear();
    q1.enqueue(root);
    // int levelOrder = -1;
    bool check = false;
    while (q1.getSize() > 0)
    {
        TreeNode *front = q1.dequeue();
        if (front->getLeftChild() != nullptr)
        {
            q1.enqueue(front->getLeftChild());
        }

        if (front->getRightChild() != nullptr)
        {
            q1.enqueue(front->getRightChild());
        }

        if (front->getData()==data){
            check = true;
            return front;
        }
    }
    if (!check)
    {
        return nullptr;
    }
    

} // Finds and returns the node with the data otherwise return nullptr
bool Tree::isFull()
{
    if (root == nullptr)
    {
        return true;
    }
    q1.clear();
    q1.enqueue(root);
    // int levelOrder = -1;
    bool check = true;
    while (q1.getSize() > 0)
    {
        TreeNode *front = q1.dequeue();
        if (front->getLeftChild() != nullptr)
        {
            q1.enqueue(front->getLeftChild());
        }

        if (front->getRightChild() != nullptr)
        {
            q1.enqueue(front->getRightChild());
        }

        if ((front->getLeftChild() == nullptr) != (front->getRightChild() == nullptr))
            check = false;
    }
    return check;
} // Returns true if every node has either 0 or 2 child.

void Tree:: deleteNode(int value){
    TreeNode *toDelete = root;
    if (root==nullptr)
    {
        cout << "Tree is Empty"<< endl;
        return;
    }
    while (q1.getSize()> 0)
    {
        
    }
    
    
}

