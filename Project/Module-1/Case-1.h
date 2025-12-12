#pragma once

#include <iostream>
#include "../Headers/SinglyLinkedList.h"
#include "../Module-4/HistoryStack-2.h" 
#include "../Headers/Sorting.h"

using namespace std;

struct Case
{
    private:
    int caseID;
    string caseType;
    string location;
    int severnity;
    string status;

    public:
    Case();
    Case(int, string, string, int, string);
    void setCaseID(int);
    int getCaseID();
    void setCaseType(string);
    string getCaseType();
    void setLocation(string);
    string getLocation();
    void setSeverity(int);
    int getSeverity();
    void setStatus(string);
    string getStatus();
    void display();
    friend class CaseManagement;
    
};

inline ostream& operator<<(ostream& out, Case& c)
{
    out << "ID: " << c.getCaseID() 
        << ", Type: " << c.getCaseType()
        << ", Location: " << c.getLocation()
        << ", Severity: " << c.getSeverity()
        << ", Status: " << c.getStatus();
    return out;
}




