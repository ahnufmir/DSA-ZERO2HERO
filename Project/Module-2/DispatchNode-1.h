#ifndef DISPATCH_2_H
#define DISPATCH_2_H

#include <iostream>
#include "../Headers/Queue.h"
#include "../Module-1/CaseManagement-2.h"

class DispatchNode
{
private:
    int caseID;
    int severity;
    //int unitID;
    string caseType;
public:
    DispatchNode();
    DispatchNode(int caseID, int severity, string);
    void setCaseID(int);
    int getCaseID();
    void setSeverity(int);
    int getSeverity();
    // void setUnitID(int);
    // int getUnitID();
    void setCaseType(string);
    string getCaseType();
};



#endif