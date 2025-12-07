#pragma once

#include "Case-1.h"
// class HistoryStack;

class CaseManagement
{
private:
    List<Case>CaseList;
   // int size;
    HistoryStack* hs;
public:
    
    CaseManagement();
    CaseManagement(HistoryStack*);
    void appendCase(int crimeID, string, string, int, string);
    void prependCase(int crimeID, string, string, int, string);
    void insertCaseAtAnyIndex(int index, int crimeID, string, string, int, string);
    void deleteCaseFromStart();
    void deleteCaseFromEnd();
    void updateCase(int index, int crimeID, string, string, int, string);
    Case* searchByIndex(int crimeID);
    void printCaseList();
    void CaseManagementMenu();
    int getSize();
    List<Case>& getCaseList();
    Case* getCaseByID(int id);
};