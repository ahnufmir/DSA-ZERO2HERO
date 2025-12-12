#include "CaseManagement-2.h"
//#include "../Module-4/HistoryStack-2.h" 

CaseManagement::CaseManagement()
{
   // size = 0;
}

CaseManagement :: CaseManagement(HistoryStack *history){
    hs = history;
}


void CaseManagement::appendCase(int caseID, string caseType, string location, int severnity, string status)
{
    Case newCase(caseID, caseType, location, severnity, status);
    CaseList.append(newCase);
   // size++;
    hs->addStack(caseID, caseType, severnity, status, 0, "", "", 0);
}

void CaseManagement::prependCase(int caseID, string caseType, string location, int severnity, string status)
{
    Case newCase(caseID, caseType, location, severnity, status);
    CaseList.prepend(newCase);
  //  size++;
    hs->addStack(caseID, caseType, severnity, status, 0, "", "", 0);
}

void CaseManagement::insertCaseAtAnyIndex(int index, int caseID, string caseType, string location, int severnity, string status)
{
    Case newCase(caseID, caseType, location, severnity, status);
    CaseList.insertAtIndex(index, newCase);
    //size++;
    hs->addStack(caseID, caseType, severnity, status, 0, "", "", 0);
}
void CaseManagement::deleteCaseFromStart()
{
    CaseList.deleteFromStart();
    //size--;
}
void CaseManagement::deleteCaseFromEnd()
{
    CaseList.deleteFromEnd();
   // size--;
}
void CaseManagement::updateCase(int index, int caseID, string caseType, string location, int severnity, string status)
{
    Case updatedCase(caseID, caseType, location, severnity, status);
    CaseList.updateAtIndex(index, updatedCase);
}
void CaseManagement::printCaseList()
{
    CaseList.printList();
}
Case* CaseManagement::getCaseByID(int id)
{
    for (int i = 0; i < CaseList.getSize(); i++)
    {
        Node<Case>* node = CaseList.getNodeAtIndex(i);
        if (node && node->getData().getCaseID() == id)
            return &(node->getData());
    }
    return nullptr; // not found
}
Case *CaseManagement::searchByIndex(int caseID)
{
    Node<Case> *node = CaseList.getNodeAtIndex(caseID);
    Case *casePtr = &(node->getData());
    return casePtr;
}

int CaseManagement::getSize()
{
    return CaseList.getSize();
}

List<Case>& CaseManagement::getCaseList()
{
    return CaseList;
}

void CaseManagement::CaseManagementMenu()
{

    cout << "================== MENU ===================" << endl;
    cout << "1. Append Case" << endl;
    cout << "2. Prepend Case" << endl;
    cout << "3. Insert Case at any Place" << endl;
    cout << "4. Delete First Case" << endl;
    cout << "5. Delete Last Case" << endl;
    cout << "6. Update Case" << endl;
    cout << "7. Search Case  " << endl;
    cout << "8. Display Case" << endl;
    cout << "-----------------------------" << endl;
}
