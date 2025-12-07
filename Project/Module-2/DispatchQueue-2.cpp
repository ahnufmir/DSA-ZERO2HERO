#include "DispatchQueue-2.h"

DispatchQueue::DispatchQueue()
{
    size = 0;
    caseManagementPtr = nullptr;
}

DispatchQueue::DispatchQueue(CaseManagement *ptr)
{
    caseManagementPtr = ptr;
}
void DispatchQueue::addDispatch()
{
    int maxSeverity = 0;
    Case *highSeveritycase = nullptr;

    for (int i = 0; i < caseManagementPtr->getSize(); i++)
    {
        Case *c = caseManagementPtr->searchByIndex(i);
        QueueNode<DispatchNode> *node = dispatchQueue.getFront();
        bool check = true;
        ;
        while (node != nullptr)
        {
            DispatchNode d = node->getData();
            if (d.getCaseID() == c->getCaseID())
            {
                check = false;
                break;
            }
            node = node->getNext();
        }

        if ((c->getSeverity() > maxSeverity) && (check))
        {
            maxSeverity = c->getSeverity();
            highSeveritycase = c;
        }
    }
    if (highSeveritycase)
    {
        int caseID = highSeveritycase->getCaseID();
        string caseType = highSeveritycase->getCaseType();
        // int unitID = 0;
        DispatchNode node(caseID, maxSeverity, caseType);
        dispatchQueue.enqueue(node);
        cout << "Case with Severity " << maxSeverity << " has been added to Dispatch Queue" << endl;
        size++;
        return;
    }
    else
    {
        cout << "No case Found! PEACEFUL COUNTRY :)" << endl;
        return;
    }

    // for (int i = 0; i < caseManagementPtr->getSize(); i++)
    // {
    //     case* case = caseManagementPtr->searchByIndex(i);
    //     {

    //         int severity = case->getSeverity();
    //         if (severity == 4)
    //         {
    //             int caseID = case->getcaseID();
    //             int unitID = 0;
    //             DispatchNode node(caseID, severity, unitID);
    //             dispatchQueue.enqueue(node);
    //             cout << "Case with Severity 4 has been added to Dispatch Queue" << endl;
    //             size++;
    //             return;
    //         }
    //         else if (severity == 3)
    //         {
    //             int caseID = case->getcaseID();
    //             int unitID = 0;
    //             DispatchNode node(caseID, severity, unitID);
    //             dispatchQueue.enqueue(node);
    //             cout << "Case with Severity 3 has been added to Dispatch Queue" << endl;
    //             size++;
    //             return;
    //         }
    //         else if (severity == 2)
    //         {
    //             int caseID = case->getcaseID();
    //             int unitID = 0;
    //             DispatchNode node(caseID, severity, unitID);
    //             dispatchQueue.enqueue(node);
    //             cout << "Case with Severity 2 has been added to Dispatch Queue" << endl;
    //             size++;
    //             return;
    //         }
    //         else if (severity == 1)
    //         {
    //             int caseID = case->getcaseID();
    //             int unitID = 0;
    //             DispatchNode node(caseID, severity, unitID);
    //             dispatchQueue.enqueue(node);
    //             cout << "Case with Severity 1 has been added to Dispatch Queue" << endl;
    //             size++;
    //             return;
    //         }
    //         else
    //         {
    //             cout << "No case Found! PEACEFUL COUNTRY :)" << endl;
    //             return;
    //         }
    //     }
    // }
}
DispatchNode DispatchQueue::sendDispath()
{
    DispatchNode d;
    if (!dispatchQueue.isEmpty())
    {
        d = dispatchQueue.dequeue();
        size--;
        return d;
    }
    else{
        d.setCaseID(-1);
        cout << "Dispatch Queue is empty!" << endl;
        return d;
    }
}

DispatchNode DispatchQueue::viewDispatch()
{
    // DispatchNode front = dispatchQueue.peek();
    // cout << "Dispatch Details : " << endl;
    // cout << "Case ID" << front.getcaseID() << endl;
    // cout << "Severity " << front.getSeverity() << endl;
    // cout << "Unit ID " << front.getUnitID() << endl;
    return (dispatchQueue.peek());
}
bool DispatchQueue::isDispatchEmpty()
{
    return dispatchQueue.isEmpty();
}

void DispatchQueue::emptyDispatchQueue()
{
    dispatchQueue.clear();
}
LinkedQueue<DispatchNode>& DispatchQueue::getDispatchQueue()
{
    return dispatchQueue;
}
void DispatchQueue::displayQueue()
{
    QueueNode<DispatchNode> *node = dispatchQueue.getFront();
    while (node != nullptr)
    {
        DispatchNode d = node->getData();
        cout << "case ID: " << d.getCaseID()
             //   << ", Unit ID: " << d.getUnitID()
             << ", Severity: " << d.getSeverity()
             << ", Case Type: " << d.getCaseType()
             << endl;
        node = node->getNext();
    }

    // dispatchQueue.printQueue();
}

void DispatchQueue::menu()
{
    cout << "============= Dispatch Queue Menu ============" << endl;
    cout << "1. Add Dispatch Case" << endl;
    cout << "2. Send Dispatch " << endl;
    cout << "3. View Dispatch" << endl;
    cout << "4. Check Pending Dispatch" << endl;
    cout << "5. Clear Dispatch Queue" << endl;
    cout << "6. Print Queue" << endl;
}

// LinkedQueue<DispatchNode> DispatchQueue:: getDispatchQueue(){
//     return dispatchQueue;
//  }