#include "functions.h"

TreeNode::TreeNode(int value)
{
    data = value;
    childrenCount = 0;
    capacity = 10;
    children = new TreeNode *[capacity];
} // Constructor to initialize the node with a given value.
void TreeNode::setChild(int index, TreeNode *desiredNode)
{
    children[index] = desiredNode;
}
TreeNode *TreeNode::getChild(int index)
{
    // for (int i = 0; i < childrenCount; i++)
    // {
    //     if (index == childrenCount)
    //     {

    //     }

    // }
    return children[index];
} // Returns a pointer to the child.
int TreeNode::getData()
{
    return data;
} // eturns the data stored in the node.
void TreeNode::setData(int n)
{
    data = n;
} // eturns the data stored in the node.
int TreeNode::getChildrenCount()
{
    return childrenCount;
} // eturns the data stored in the node.
void TreeNode::setChildrenCount(int n)
{
    childrenCount = n;
} // eturns the data stored in the node.
void TreeNode::addChild(TreeNode *node)
{
    if (childrenCount == capacity)
    {
        capacity *= 2;
        TreeNode **childrenTemp = new TreeNode *[capacity];
        for (int i = 0; i < childrenCount; i++)
        {
            childrenTemp[i] = children[i];
        }
        delete children;
        children = childrenTemp;
    }
    children[childrenCount] = node;
    childrenCount++;
} // Adds a new child. Must handle array **resizing** (doubling capacity) if childrenCount reaches capacity.

Tree::Tree()
{
    root = nullptr;
} // Constructor to initialize the tree.

TreeNode *insertNodeHelperFn(TreeNode *node, int parentData)
{
    if (node == nullptr)
    {
        return nullptr;
    }
   // cout << "hi1" << endl;
    if (node->getData() == parentData)
    {
        return node;
    }
   // cout << "hi" << endl;
    for (int i = 0; i < node->getChildrenCount(); i++)
    {
        TreeNode *searchNode = insertNodeHelperFn(node->getChild(i), parentData);
          if (searchNode != nullptr)
    {
        return searchNode;
    }
    }

   // cout << "hi2" << endl;
        return nullptr;

    // node->getChild(parentData);
}
void Tree::insertNode(int parentData, int value)
{
    TreeNode* parentNode;
    TreeNode *childNode= new TreeNode(value);
    if (root == nullptr)
    {
        parentNode = new TreeNode(parentData);
        root = parentNode;
    }
    parentNode = insertNodeHelperFn(root, parentData);
  //  cout << "hi3" << endl;
    if (parentNode == nullptr)
    {
        cout << "Parent Node not Found!" << endl;
        return;
    }
    //cout << "hi4" << endl;
    int parentIndex = parentNode->getChildrenCount();
    parentNode->addChild(childNode);
   // cout << "hi5" << endl;

    // else
    // {
    //     TreeNode* toFind = root;
    //     if (parentData == toFind->data)
    //     {
    //         toFind->children[root->childrenCount].data = value;
    //     }

    // }

} // Finds parent node, and adds the new node as its last child.

TreeNode *findNodeHelperFn(TreeNode *node, int parentData)
{
    if (node == nullptr)
    {
        return nullptr;
    }
   // cout << "hi1" << endl;
    if (node->getData() == parentData)
    {
        return node;
    }
   // cout << "hi" << endl;
    for (int i = 0; i < node->getChildrenCount(); i++)
    {
        TreeNode *searchNode = findNodeHelperFn(node->getChild(i), parentData);
          if (searchNode != nullptr)
    {
        return searchNode;
    }
    }

   // cout << "hi2" << endl;
        return nullptr;

    // node->getChild(parentData);
}

TreeNode *Tree::findNode(int data)
{
    return findNodeHelperFn(root, data);
} // Finds and returns the node with the data otherwise return nullptr.
TreeNode *Tree::getRoot()
{
    return root;
} // Returns the root node of the tree.
TreeNode *findParentHelperFunction(TreeNode *node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    for (int i = 0; i < node->getChildrenCount(); i++)
    {
        if (node->getChild(i)->getData() == data)
        {
            return node;
        }
    }
    for (int i = 0; i < node->getChildrenCount(); i++)
    {
        TreeNode *parent = findParentHelperFunction(node->getChild(i), data);
        if (parent != nullptr)
        {
            return parent;
        }
    }
    return nullptr;
}
TreeNode *Tree::findParent(int data)
{

    return findParentHelperFunction(root, data);
}
bool Tree::deleteNodeHelperFn(TreeNode *&root, int data)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->getData() == data)
    {
        // Node with 0 childs
        if (root->getChildrenCount() == 0) // In this im finding parent and deleting the target node and then set respective child (target node) of parent to nullptr
        {
            TreeNode *parent = findParent(data);
            // if (parent->getLeftChild() == root)
            // {
            //     parent->addLeftChild(nullptr);
            // }
            // else
            // parent->addRightChild(nullptr);
            if (parent)
            {
                for (int i = 0; i < parent->getChildrenCount(); i++)
                {
                    if (parent->getChild(i) == root)
                    {
                        parent->setChild(i, nullptr);
                    }
                }
            }
            else
            {
                delete root;
                root = nullptr;
                return true;
            }

            parent->setChildrenCount((parent->getChildrenCount()) - 1);
            delete root;
            root = nullptr;
            return true;
        }

        // Node with 1 child
        else if ((root->getChildrenCount() == 1)) // In this, i found parent and child of target node and attach them to each other and delete target node
        {
            TreeNode *parent = this->findParent(data);
            if (parent)
            {
                // if (parent->getLeftChild() == root)
                //     parent->addLeftChild(root->getLeftChild());
                // else
                //     parent->addRightChild(nullptr);
                // parent->addRightChild(root->getLeftChild());
                parent->addChild(root->getChild(0));
            }
            else
            {
                TreeNode *child = root->getChild(0);
                root->setData(root->getChild(0)->getData());
                child = nullptr;
                delete root->getChild(0);
                root->setChild(0, nullptr);
                return true;
            }

            delete root;
            root = nullptr;
            return true;
        }

        // Node with many childs
        else if (root->getChildrenCount() >= 2) // In many children case  I set value of root equal to its first child value(at zero index) and attach all children's of its first child to root and then delete first child
        {
            TreeNode *child = root->getChild(root->getChildrenCount() - 1);
            int length = child->getChildrenCount();
            root->setChild(root->getChildrenCount() - 1, nullptr);
            // delete root->getChild(root->getChildrenCount()-1);
            root->setChildrenCount((root->getChildrenCount()) - 1);
            TreeNode *grandChilds[length];
            root->setData(child->getData());
            for (int i = 0; i < length; i++)
            {
                grandChilds[i] = child->getChild(i);
            }
            for (int i = 0; i < length; i++)
            {
                root->addChild(grandChilds[i]);
            }
            delete child;
            child = nullptr;
            return true;
        }
    }
    for (int i = 0; i < root->getChildrenCount(); i++)
    {
        deleteNodeHelperFn(root->children[i], data);
    }
    return false;
}
void Tree::deleteNode(int value)
{
    deleteNodeHelperFn(root, value);
} // deletes the node with the given value by replacing it with the last leaf node and then deleting it.
int Tree::getDegree(int data){
    TreeNode* node = findNode(data);
    return(node->getChildrenCount());
} // Returns the degree (the number of children) of the node containing the given data.

int getHeightHelperFn(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    //int maxHeight = 0;
    if (node->getChildrenCount() == 0) return 0;
    int maxHeight = 0;
    for (int i = 0; i < node->getChildrenCount(); i++)
    {
       int childHeight = getHeightHelperFn(node->getChild(i));
       if(childHeight>maxHeight)
       maxHeight = childHeight;
    }
    return (1+maxHeight);
}
int Tree::getHeight(int data)   
{
    TreeNode *node = findNode(data);
    return getHeightHelperFn(node);
} // Returns the height (the length of the longest path from this node to a leaf) of the node containing the given data.

void helperFunctionPreOrder(TreeNode* node){
    if (node ==nullptr)
    {
        return;
    }
    cout << node->getData() << endl;
    for (int i = 0; i < node->getChildrenCount(); i++)
    {
    helperFunctionPreOrder(node->getChild(i));
    }
    
}
void Tree::print_pre0rder(){
    helperFunctionPreOrder(root);
} // Prints the tree nodes' data using pre-order traversal (Root, Left, Right).
void helperFunctionInOrder(TreeNode* node){
   // cout << "entering in-order for " << node->getData() << endl;
    if (node ==nullptr)
    {
        return;
    }
    int child = (node->getChildrenCount())/2;
    //cout << "child of " << node->getData() << " are" << child << endl;
    for (int i = 0; i < child; i++)
    {
        helperFunctionInOrder(node->getChild(i));
    } 
    cout << node->getData() << endl;
    for (int i = child; i < node->getChildrenCount(); i++)
    {
        helperFunctionInOrder(node->getChild(i));
    }
    
}
void Tree::print_in0rder(){
    helperFunctionInOrder(root);
} // Prints the tree nodes' data using an in-order traversal (Left, Root, Right).
void helperFunctionPostOrder(TreeNode* node){
     if (node ==nullptr)
    {
        return;
    }
    int child = (node->getChildrenCount())/2;
    //cout << "child of " << node->getData() << " are" << child << endl;
    for (int i = 0; i < child; i++)
    {
        helperFunctionPostOrder(node->getChild(i));
        cout << node->getData() << endl;
    } 
    for (int i = child; i < node->getChildrenCount(); i++)
    {
        helperFunctionPostOrder(node->getChild(i));
    }
    
}
void Tree::print_post0rder(){
    helperFunctionPostOrder(root);
} // Prints the tree nodes' data using the post-order traversal (Left, Right, Root).
