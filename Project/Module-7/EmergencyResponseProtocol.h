#pragma once
#include "../Headers/Trees.h"
#include "EmergencyResponseNode.h"

class EmergencyProtocolTree
{
private:
    Tree<EmergencyNode> tree;
    bool isAdmin;
    EmergencyNode currentNode;

public:
    EmergencyProtocolTree();
    EmergencyProtocolTree(EmergencyNode);
    bool checkAdmin(int);
    void appendNode(string, string, string);
    void findNode(string);
    int findTreeHeight(string s);
    void findParent(string);
    Tree<EmergencyNode> getTree();
    void display();
    void menu();

};