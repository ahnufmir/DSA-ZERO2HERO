#pragma once
// #include "../Headers/Trees.h"
#include <iostream>
using namespace std;

class EmergencyNode
{
    string name;
    // string parentName;
    string type;

public:
    EmergencyNode();
    EmergencyNode(string, string);
    void setName(string);
    void setType(string);
    string getName();
    string getType();
    bool operator==(const EmergencyNode &other) const
    {
        return name == other.name; // Can access other.name because it's the same class
    }

    bool operator!=(const EmergencyNode &other) const
    {
        return !(*this == other);
    }
    friend ostream &operator<<(ostream &os, const EmergencyNode &node)
    {
        os << node.name << " (" << node.type << ")";
        return os;
    }
};