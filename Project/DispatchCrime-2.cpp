#include "DispatchCrime-2.h"

DispatchNode::DispatchNode()
{
    crimeID = 0;
    severity = 0;
    unitID = 0;
}
DispatchNode::DispatchNode(int crimeID, int severity, int unitID)
{
    this->crimeID = crimeID;
    this->severity = severity;
    this->unitID = unitID;
}
void DispatchNode::setCrimeID(int c)
{
    crimeID = c;
}
int DispatchNode::getCrimeID()
{
    return crimeID;
}
void DispatchNode::setSeverity(int s)
{
    severity = s;
}
int DispatchNode::getSeverity()
{
    return severity;
}
void DispatchNode::setUnitID(int unit)
{
    unitID = unit;
}
int DispatchNode::getUnitID()
{
    return unitID;
}

DispatchQueue::DispatchQueue()
{
    size = 0;
    crimeManagementPtr = nullptr;
}

DispatchQueue::DispatchQueue(CrimeManagement *ptr)
{
    crimeManagementPtr = ptr;
}
void DispatchQueue::addDispatch()
{
    int maxSeverity = 0;
    Crime *highSeveritycrime = nullptr;
    for (int i = 0; i < crimeManagementPtr->getSize(); i++)
    {
        Crime *crime = crimeManagementPtr->searchByIndex(i);
        {
            if (crime->getSeverity() > maxSeverity)
            {
                maxSeverity = crime->getSeverity();
                highSeveritycrime = crime;
            }
        }
    }
    if (highSeveritycrime)
    {
        int crimeID = highSeveritycrime->getCrimeID();
        int unitID = 0;
        DispatchNode node(crimeID, maxSeverity, unitID);
        dispatchQueue.enqueue(node);
        cout << "Case with Severity " << maxSeverity << " has been added to Dispatch Queue" << endl;
        size++;
        return;
    }
    else
    {
        cout << "No Crime Found! PEACEFUL COUNTRY :)" << endl;
        return;
    }

    // for (int i = 0; i < crimeManagementPtr->getSize(); i++)
    // {
    //     Crime* crime = crimeManagementPtr->searchByIndex(i);
    //     {

    //         int severity = crime->getSeverity();
    //         if (severity == 4)
    //         {
    //             int crimeID = crime->getCrimeID();
    //             int unitID = 0;
    //             DispatchNode node(crimeID, severity, unitID);
    //             dispatchQueue.enqueue(node);
    //             cout << "Case with Severity 4 has been added to Dispatch Queue" << endl;
    //             size++;
    //             return;
    //         }
    //         else if (severity == 3)
    //         {
    //             int crimeID = crime->getCrimeID();
    //             int unitID = 0;
    //             DispatchNode node(crimeID, severity, unitID);
    //             dispatchQueue.enqueue(node);
    //             cout << "Case with Severity 3 has been added to Dispatch Queue" << endl;
    //             size++;
    //             return;
    //         }
    //         else if (severity == 2)
    //         {
    //             int crimeID = crime->getCrimeID();
    //             int unitID = 0;
    //             DispatchNode node(crimeID, severity, unitID);
    //             dispatchQueue.enqueue(node);
    //             cout << "Case with Severity 2 has been added to Dispatch Queue" << endl;
    //             size++;
    //             return;
    //         }
    //         else if (severity == 1)
    //         {
    //             int crimeID = crime->getCrimeID();
    //             int unitID = 0;
    //             DispatchNode node(crimeID, severity, unitID);
    //             dispatchQueue.enqueue(node);
    //             cout << "Case with Severity 1 has been added to Dispatch Queue" << endl;
    //             size++;
    //             return;
    //         }
    //         else
    //         {
    //             cout << "No Crime Found! PEACEFUL COUNTRY :)" << endl;
    //             return;
    //         }
    //     }
    // }
}
void DispatchQueue::sendDispath()
{
    if (!dispatchQueue.isEmpty())
    {
        dispatchQueue.dequeue();
        size--;
    }
    else
    {
        cout << "Dispatch Queue is empty!" << endl;
    }
}
DispatchNode DispatchQueue::viewDispatch()
{
    // DispatchNode front = dispatchQueue.peek();
    // cout << "Dispatch Details : " << endl;
    // cout << "Case ID" << front.getCrimeID() << endl;
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

void DispatchQueue::displayQueue()
{
    QueueNode<DispatchNode> *node = dispatchQueue.getFront();
    while (node != nullptr)
    {
        DispatchNode d = node->getData();
        cout << "Crime ID: " << d.getCrimeID()
             << ", Unit ID: " << d.getUnitID()
             << ", Severity: " << d.getSeverity()
             << endl;
        node = node->getNext();
    }
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