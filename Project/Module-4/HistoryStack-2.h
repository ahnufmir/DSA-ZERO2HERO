    #pragma once
    #include "History-1.h"
    #include <iostream>

    using namespace std;

    class HistoryStack
    {
    private:
        Stack<History> caseHistory;
    public:
        HistoryStack();
        void addStack(int caseID, string caseType, int severity, string caseStatus, int unitID, string unitType, string unitStatus);
        void removeStack();
        void seekStack();
        void printStack();
        void clearStack();
        void menu();
    // ~HistoryStack();
    };

