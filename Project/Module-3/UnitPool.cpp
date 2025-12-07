#include "UnitPool.h"

UnitPool::UnitPool()
{
    nextID = 1;
    // size = 0;
    // capacity = 10;
    // units = new nit[capacity];
}

UnitPool::UnitPool(DispatchQueue *dispatchPtr, CaseManagement *casee, HistoryStack *history)
{
    q = dispatchPtr;
    c = casee;
    hs = history;
    nextID = 1;
}

UnitPool::~UnitPool()
{
    // delete[] units;
}

void UnitPool::appendUnit(string typ, string loc, string statuss)
{
    Unit u;
    // cout << ' "ID Generator' << u << endl;
    // u.IDGenerator = units.get_size()+1;
    cout << "ID Generator now" << nextID << endl;
    ;
    u.unitID = nextID;
    u.type = typ;
    u.currentLocation = loc;
    u.status = statuss;
    u.responseTimeEstimate = 0;
    nextID++;
    units.append(u);

    hs->addStack(0, "", 0, "", u.unitID, u.type, u.status);
}

void UnitPool::prepandUnit(string typ, string loc, string statuss)
{
    Unit u;
    // cout << ' "ID Generator' << u << endl;
    // u.IDGenerator = units.get_size()+1;
    cout << "ID Generator now" << nextID << endl;
    ;
    u.unitID = nextID;
    u.type = typ;
    u.currentLocation = loc;
    u.status = statuss;
    u.responseTimeEstimate = 0;
    nextID++;
    units.prepend(u);
    hs->addStack(0, "", 0, "", u.unitID, u.type, u.status);
}

bool UnitPool::findAvailableUnit(string type)
{
    for (int i = 0; i < units.get_size(); i++)
    {

        if ((type == units[i].type))
        {
            if (units[i].status == "available")
            {
                return true;
            }
        }
    }
    return false;
}

UnitPool::Unit UnitPool::makeUnitUnAvailable(string caseType)
{
    for (int i = 0; i < units.get_size(); i++)
    {
        if (caseType == "injury")
        {
            if ((units[i].type == "Ambulance") && (units[i].status == "available"))
            {
                units[i].status = "unavailable"; // mark as dispatched
                return units[i];
            }
        }
        else if (caseType == "fire")
        {
            if ((units[i].type == "FireBrigade") && (units[i].status == "available"))
            {
                units[i].status = "unavailable"; // mark as dispatched
                return units[i];
            }
        }
        else if (caseType == "murder")
        {
            if ((units[i].type == "Police") && (units[i].status == "available"))
            {
                units[i].status = "unavailable"; // mark as dispatched
                return units[i];
            }
        }
    }
    cout << "Either unit is not created or is unavailable" << endl;
    Unit none{};
    none.unitID = -1;
    return none;
}

void UnitPool::removeUnitAtIndex(int index)
{
    units.removeAt(index);
}

void UnitPool::sendUnit()
{
    if (!q)
    {
        cout << "DispatchQueue pointer not set!" << endl;
        return;
    }
    DispatchNode n = q->sendDispath();

    if (n.getCaseID() == -1)
    {
        cout << "No dispatch available to send a unit." << endl;
        return;
    }
    string caseType = n.getCaseType();
    Unit u = makeUnitUnAvailable(caseType);
    Case* ptr = c->getCaseByID(n.getCaseID());
    string status;
    if (ptr)
    {
        status = ptr->getStatus();
    }
    else
    {
        cout << "Status lene wala ptr assign nhi howa" << endl;
        return;
    }
    
    if (u.unitID != -1)
    {
        cout << "Unit ID " << u.unitID << " dispatched for " << caseType << endl;
        hs->addStack(n.getCaseID(), n.getCaseType(), n.getSeverity(), status, u.unitID, u.type, u.status);
    }
    else
        cout << "No available unit for " << caseType << endl;
}

void UnitPool::displayUnits()
{
    units.display();
}

void UnitPool::menu()
{
    cout << "================== Unit Pool Menu =================" << endl;
    cout << "1. Append Unit" << endl;
    cout << "2. Prepend Unit" << endl;
    cout << "3. Remove Unit" << endl;
    cout << "4. Find Available Unit" << endl;
    cout << "5. Display Unit" << endl;
    // cout << "6. Make Unit Unavailable" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "6. SEND UNIT !!" << endl;
}