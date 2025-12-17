#include "HistoryStack-2.h"
// void StackHistory::addStack(int caseID, string caseType, int severity, string caseStatus, int unitID, string unitType, string unitStatus)
// {
//     History s(caseID, caseType, severity, caseStatus, unitID, unitType, unitStatus);
// }
HistoryStack::HistoryStack()
{
}

void HistoryStack::addStack(int caseID, string caseType, int severity, string caseStatus, int unitID, string unitType, string unitStatus, int time)
{
    History h(caseID, caseType, severity, caseStatus, unitID, unitType, unitStatus, time);
    caseHistory.push(h);
    // writeHistoryToFile(h);
    cout << "Writing to DB: " << h << endl;
    Database::getInstance().writeHistory(h);
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

void HistoryStack::loadFromFile()
{
    MyArray<History> historyList;
    Database::getInstance().readHistory(historyList); // fills historyList

    for (int i = 0; i < historyList.get_size(); i++)
    {
        caseHistory.push(historyList.getValueAtIndex(i));
    }
}
void HistoryStack::menu()
{
    cout << "============== History Management Function ================" << endl;
    cout << "1. See Last History" << endl;
    cout << "2. Remove Last History" << endl;
    cout << "3. Print History" << endl;
    cout << "4. Clear History" << endl;
    cout << "5. Load from File into History Stack" << endl;
    cout << "------------------------" << endl;
}
