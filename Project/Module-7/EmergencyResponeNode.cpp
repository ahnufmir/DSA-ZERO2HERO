#include "EmergencyResponseNode.h"

EmergencyNode::EmergencyNode()
{
    name = "";
    type = "";
}
EmergencyNode::EmergencyNode(string name, string type)
{
    this->name = name;
    this->type = type;
}
void EmergencyNode::setName(string name)
{
    this->name = name;
}
string EmergencyNode::getName()
{
    return name;
}
void EmergencyNode::setType(string type)
{
    this->type = type;
}
string EmergencyNode::getType()
{
    return type;
}