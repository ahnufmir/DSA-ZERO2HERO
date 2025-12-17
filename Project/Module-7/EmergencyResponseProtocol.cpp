#include "EmergencyResponseProtocol.h"

EmergencyProtocolTree::EmergencyProtocolTree()
{
}
EmergencyProtocolTree::EmergencyProtocolTree(EmergencyNode current)
{
    currentNode = current;
}
void EmergencyProtocolTree::appendNode(string parentName, string childName, string type)
{
    if (!isAdmin)
    {
        cout << "Permission Denied" << endl;
        return;
    }

    EmergencyNode childNode(childName, type);
    EmergencyNode parentKey(parentName, "");
    tree.insertNode(parentKey, childNode);
}
void EmergencyProtocolTree::findNode(string name)
{
    if (!isAdmin)
    {
        cout << "Permission Denied" << endl;
        return;
    }
    currentNode.setName(name);
    TreeNode<EmergencyNode> *node = tree.findNode(currentNode);
    cout << "Detail :" << endl;
    if (node->getChildrenCount() >= 1)
    {
        cout << "Child Details: " << endl;
        for (int i = 0; i < node->getChildrenCount(); i++)
        {
            cout << "Child Name " << i+1 << " " << node->getChild(i)->getData().getName() << endl;
            cout << "Child Type " << i+1 << " " << node->getChild(i)->getData().getType() << endl;
        }
    }
}
int EmergencyProtocolTree::findTreeHeight(string s)
{
    if (!isAdmin)
    {
        cout << "Permission Denied" << endl;
        return -1;
    }
    currentNode.setName(s);
    int height = tree.getHeight(currentNode);
    if (height >= 0)
    {
        return height;
    }
    else
    {
        cout << "Didnot found Height" << endl;
        return -1;
    }
}
void EmergencyProtocolTree::findParent(string s)
{
    if (!isAdmin)
    {
        cout << "Permission Denied" << endl;
        return;
    }
    currentNode.setName(s);
    TreeNode<EmergencyNode> *node = tree.findParent(currentNode);
    if (node == nullptr)
    {
        cout << "Parent not Found" << endl;
        return;
    }
    cout << "Parent of this child is ' " << node->getData().getName() << " '" << endl;
}
Tree<EmergencyNode> EmergencyProtocolTree::getTree()
{
    return tree;
}
bool EmergencyProtocolTree::checkAdmin(int pass)
{
    if (pass == 123)
    {
        this->isAdmin = true;
        return true;
    }
    return false;
}

void EmergencyProtocolTree:: display(){
    tree.print_pre0rder();
}

void EmergencyProtocolTree::menu()
{
    cout << "-------------------- Emergency Response Protocol -------------------" << endl;
    cout << "For Admin Only : " << endl;
    cout << "1. Approve as Admin to operate below functions" << endl;
    cout << "2. Add Node " << endl;
    cout << "3. Find Node" << endl;
    cout << "4. Find Height" << endl;
    cout << "5. Find Parent" << endl;
    cout << "6. Display " << endl;
    cout << "------------------" << endl;
}