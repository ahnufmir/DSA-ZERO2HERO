#ifndef DISPATCH_2_H
#define DISPATCH_2_H

#include <iostream>
#include "Queue.h"
#include "IncidentLog-1.h"

class DispatchNode
{
private:
    int crimeID;
    int severity;
    int unitID;
public:
    DispatchNode();
    DispatchNode(int crimeID, int severity, int unitID);
    void setCrimeID(int);
    int getCrimeID();
    void setSeverity(int);
    int getSeverity();
    void setUnitID(int);
    int getUnitID();
};

class DispatchQueue
{
private:
    CrimeManagement* crimeManagementPtr;
    LinkedQueue<DispatchNode> dispatchQueue;
    int size;
public:
    DispatchQueue();
    DispatchQueue(CrimeManagement*);
    void addDispatch();
    void sendDispath();
    DispatchNode viewDispatch();
    bool isDispatchEmpty();
    void emptyDispatchQueue();
    void displayQueue();
    void menu();
   // LinkedQueue<DispatchNode> getDispatchQueue();
   // ~DispatchQueue();
};


#endif