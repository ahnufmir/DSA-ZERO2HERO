#include "CaseManagement-2.h"

CaseManagement::CaseManagement()
{
    size = 0;
}

CaseManagement::~CaseManagement()
{
}

void CaseManagement::appendCase(int caseID, string caseType, string location, int severnity, string status)
{
    Case newCase(caseID, caseType, location, severnity, status);
    CaseList.append(newCase);
    size++;
}

void CaseManagement::prependCase(int caseID, string caseType, string location, int severnity, string status)
{
    Case newCase(caseID, caseType, location, severnity, status);
    CaseList.prepend(newCase);
    size++;
}

void CaseManagement::insertCaseAtAnyIndex(int index, int caseID, string caseType, string location, int severnity, string status)
{
    Case newCase(caseID, caseType, location, severnity, status);
    CaseList.insertAtIndex(index, newCase);
    size++;
}
void CaseManagement::deleteCaseFromStart()
{
    CaseList.deleteFromStart();
    size--;
}
void CaseManagement::deleteCaseFromEnd()
{
    CaseList.deleteFromEnd();
    size--;
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
Case *CaseManagement::searchByIndex(int caseID)
{
    Node<Case> *node = CaseList.getNodeAtIndex(caseID);
    Case *casePtr =  &(node->getData());
    return casePtr;
}
int CaseManagement:: getSize(){
    return size;
}

List<Case> CaseManagement:: getCaseList(){
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
