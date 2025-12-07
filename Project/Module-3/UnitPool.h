#pragma once

#include "../Headers/MyArray.h"
#include "../Module-2/DispatchQueue-2.h"
#include "../Module-4/HistoryStack-2.h"
#include "../Module-1/CaseManagement-2.h"

class DispatchQueue;    // forward declaration
class CaseManagement;   // forward declaration
class HistoryStack;     // forward declaration

class UnitPool
{
private:
    struct Unit
    {
        int IDGenerator;
        int unitID;               // Unique ID for each unit
        string type;              // Ambulance, Patrol, Fire Brigade, etc.
        string currentLocation;   // Can be address
        string status;            // "available", "dispatched", "on-scene"
        int responseTimeEstimate; // Optional: estimated response time in minutes
        friend ostream &operator<<(std::ostream &out, const Unit &u)
        {
            out << "ID: " << u.unitID
                << ", Type: " << u.type
                << ", Location: " << u.currentLocation
                << ", Status: " << u.status
                << ", ETA: " << u.responseTimeEstimate;
            return out;
        }
    };

    MyArray<Unit> units;
    DispatchQueue *q;
    HistoryStack *hs;
    CaseManagement *c;
    int nextID;

public:
    UnitPool();
    ~UnitPool();
    UnitPool(DispatchQueue*, CaseManagement*c, HistoryStack* hs);
    void appendUnit(string, string, string);
    void prepandUnit(string, string, string);
    void removeUnitAtIndex(int);
    Unit makeUnitUnAvailable(string);
    bool findAvailableUnit(string type);
    void displayUnits();
    void sendUnit();
    void menu();
};
