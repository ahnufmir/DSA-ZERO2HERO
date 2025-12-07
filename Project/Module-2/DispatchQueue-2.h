#pragma once

#include "DispatchNode-1.h"

class DispatchQueue
{
private:
    CaseManagement* caseManagementPtr;
    LinkedQueue<DispatchNode> dispatchQueue;
    int size;
public:
    DispatchQueue();
    DispatchQueue(CaseManagement*);
    void addDispatch();
    DispatchNode sendDispath();
    DispatchNode viewDispatch();
    bool isDispatchEmpty();
    void emptyDispatchQueue();
    void displayQueue();
    void menu();
    LinkedQueue<DispatchNode>& getDispatchQueue();

   // LinkedQueue<DispatchNode> getDispatchQueue();
   // ~DispatchQueue();
};

