#include "functions.h"

TreeNode::TreeNode(int value)
{
    data = value;
    childrenCount = 0;
    capacity = 10;
    children = new TreeNode *[capacity];
} // Constructor to initialize the node with a given value.
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
void Tree::deleteNode(int data){

} // Deletes the node containing the given data while maintaining the tree structure (e.g., using predecessor/successor replacement or promoting a child).
int Tree::getDegree(int data){
    TreeNode* node = findNode(data);
    return(node->getChildrenCount());
} // Returns the degree (the number of children) of the node containing the given data.

int getHeightHelperFn(TreeNode* node, int h){
    if (node==nullptr)
    {
        return h = 0;
    }
    for (int i = 0; i < node->getChildrenCount(); i++)
    {
        h = getHeightHelperFn(node->getChild(i), h);
    }
    
    return (1+h);
}
int Tree::getHeight(int data){
    TreeNode* node = findNode(data);
    getHeightHelperFn(node , 0);
}//Returns the height (the length of the longest path from this node to a leaf) of the node containing the given data.

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
