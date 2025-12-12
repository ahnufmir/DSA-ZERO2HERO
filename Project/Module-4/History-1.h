#pragma once
#include "../Headers/Stack.h"
// #include "../Module-1/CaseManagement-2.h"
// #include "../Module-3/UnitPool.h"
#include <iostream>

using namespace std;

class History
{
private:
    int caseID;
    string caseType;
    int severity;
    string caseStatus;

    int unitID;
    string unitType;
    string unitStatus;
    int ETA;
    friend class HistoryStack;
    friend ostream &operator<<(ostream &out, const History &h);

public:
    History();
    History(int, string, int, string, int, string, string,int);
};

inline ostream &operator<<(ostream &out, const History &h)
{
    out << "CaseID: " << h.caseID
        << ", Type: " << h.caseType
        << ", Severity: " << h.severity
        << ", Status: " << h.caseStatus
        << ", UnitID: " << h.unitID
        << ", UnitType: " << h.unitType
        << ", UnitStatus: " << h.unitStatus;
    return out;
}
