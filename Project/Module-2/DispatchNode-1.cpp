#include "DispatchNode-1.h"

DispatchNode::DispatchNode()
{
    caseID = 0;
    severity = 0;
  //  unitID = 0;
    caseType = "";
}
DispatchNode::DispatchNode(int caseID, int severity, string caseType)
{
    this->caseID = caseID;
    this->severity = severity;
    //this->unitID = unitID;
    this->caseType = caseType;
}
void DispatchNode::setCaseID(int c)
{
    caseID = c;
}
int DispatchNode::getCaseID()
{
    return caseID;
}
void DispatchNode::setSeverity(int s)
{
    severity = s;
}
int DispatchNode::getSeverity()
{
    return severity;
}
// void DispatchNode::setUnitID(int unit)
// {
//     unitID = unit;
// }
// int DispatchNode::getUnitID()
// {
//     return unitID;
// }
void DispatchNode::setCaseType(string caseTypeValue)
{
    caseType = caseTypeValue;
}
string DispatchNode::getCaseType(){
    return caseType;
}
