#include "HistoryStack-2.h"
#include "History-1.h"
// void StackHistory::addStack(int caseID, string caseType, int severity, string caseStatus, int unitID, string unitType, string unitStatus)
// {
//     History s(caseID, caseType, severity, caseStatus, unitID, unitType, unitStatus);
// }
HistoryStack::HistoryStack(){

}

void HistoryStack::addStack(int caseID, string caseType, int severity, string caseStatus, int unitID, string unitType, string unitStatus){
    History h(caseID, caseType, severity, caseStatus, unitID, unitType, unitStatus);
    caseHistory.push(h);
}
void HistoryStack::removeStack()
{
    caseHistory.pop();
}
void HistoryStack::seekStack()
{
    caseHistory.seek();
}
void HistoryStack::printStack()
{
    caseHistory.printStack();
}
void HistoryStack::clearStack()
{
    caseHistory.clear();
}

void HistoryStack::menu(){
    cout << "============== History Management Function ================" << endl;
    cout << "1. See Last History" << endl;
    cout << "2. Remove Last History" << endl;
    cout << "3. Print History" << endl;
    cout << "4. Clear History" << endl;
    cout << "------------------------" << endl;
}


