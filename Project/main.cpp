#include "../Module-1/CaseManagement-2.h"
#include "../Module-2/DispatchQueue-2.h"
#include "../Module-3/UnitPool.h"
#include "../Module-4/HistoryStack-2.h"
#include "../Module-5/Map.h"

void menu()
{
    cout << "========================== Public-Safety-and-case-Monitoring ========================" << endl;
    cout << "1. Incident Log" << endl;
    cout << "2. Dispatch Case" << endl;
    cout << "3. Send Unit" << endl;
    cout << "4. Check History" << endl;
    cout << "5. Perform Mapping" << endl;
    cout << "--------------------" << endl;
}

int main()
{
    HistoryStack *hs = new HistoryStack();
    CaseManagement c(hs);
    DispatchQueue d(&c);
    UnitPool u(&d, &c, hs);
    Map m;

    char mainCH = 'y';
    while (mainCH == 'y')
    {
        menu();
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            char ch = 'y';
            while (ch == 'y')
            {
                int choice;
                c.CaseManagementMenu();
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    int caseID;
                    string caseType;
                    string location;
                    int severnity;
                    string status;
                    cout << "Enter case ID" << endl;
                    cin >> caseID;
                    cout << "Enter case Type" << endl;
                    cin >> caseType;
                    cout << "Enter case Location" << endl;
                    cin >> location;
                    cout << "Enter case Severnity" << endl;
                    cin >> severnity;
                    cout << "Enter case Status" << endl;
                    cin >> status;
                    c.appendCase(caseID, caseType, location, severnity, status);
                    break;
                }

                case 2:
                {
                    int caseID;
                    string caseType;
                    string location;
                    int severnity;
                    string status;
                    cout << "Enter case ID" << endl;
                    cin >> caseID;
                    cout << "Enter case Type" << endl;
                    cin >> caseType;
                    cout << "Enter case Location" << endl;
                    cin >> location;
                    cout << "Enter case Severnity" << endl;
                    cin >> severnity;
                    cout << "Enter case Status" << endl;
                    cin >> status;
                    c.prependCase(caseID, caseType, location, severnity, status);
                    break;
                }

                case 3:
                {
                    int index;
                    int caseID;
                    string caseType;
                    string location;
                    int severnity;
                    string status;
                    cout << "Enter Index" << endl;
                    cin >> index;
                    cout << "Enter case ID" << endl;
                    cin >> caseID;
                    cout << "Enter case Type" << endl;
                    cin >> caseType;
                    cout << "Enter case Location" << endl;
                    cin >> location;
                    cout << "Enter case Severnity" << endl;
                    cin >> severnity;
                    cout << "Enter case Status" << endl;
                    cin >> status;
                    c.insertCaseAtAnyIndex(index, caseID, caseType, location, severnity, status);
                    break;
                }

                case 4:
                    c.deleteCaseFromStart();
                    break;

                case 5:
                    c.deleteCaseFromEnd();
                    break;

                case 6:
                {
                    int index;
                    int caseID;
                    string caseType;
                    string location;
                    int severnity;
                    string status;
                    cout << "Enter Index" << endl;
                    cin >> index;
                    cout << "Enter case ID" << endl;
                    cin >> caseID;
                    cout << "Enter case Type" << endl;
                    cin >> caseType;
                    cout << "Enter case Location" << endl;
                    cin >> location;
                    cout << "Enter case Severnity" << endl;
                    cin >> severnity;
                    cout << "Enter case Status" << endl;
                    cin >> status;
                    c.updateCase(index, caseID, caseType, location, severnity, status);
                    break;
                }

                case 7:
                {
                    int caseID;
                    cout << "Enter case ID" << endl;
                    cin >> caseID;
                    Case *casee = c.searchByIndex(caseID);
                    if (casee)
                    {
                        casee->display();
                    }
                    else
                        cout << "case doesnot Exist" << endl;
                    break;
                }

                case 8:
                    c.printCaseList();
                    break;

                default:
                    cout << "Invalid Option Selected" << endl;
                    break;
                }
                cout << "Do you want to add log again? " << endl;
                cin >> ch;
            }
        }
        break;

        case 2:
        {
            char ch = 'y';
            while (ch == 'y')
            {
                int choice;
                d.menu();
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    d.addDispatch();
                    break;
                }

                case 2:
                {
                    d.sendDispath();
                    break;
                }

                case 3:
                {
                    DispatchNode front = d.viewDispatch();
                    cout << "Dispatch Details : " << endl;
                    cout << "Case ID" << front.getCaseID() << endl;
                    cout << "Severity " << front.getSeverity() << endl;
                    // cout << "Unit ID " << front.getUnitID() << endl;
                    break;
                }

                case 4:
                {
                    if (d.isDispatchEmpty())
                    {
                        cout << "Dispatch Queue is Empty" << endl;
                    }
                    else
                        cout << "Dispatch Queue is not Empty" << endl;
                    break;
                }

                case 5:
                    d.emptyDispatchQueue();
                    break;

                case 6:
                    d.displayQueue();
                    break;

                default:
                    cout << "Invalid Option Selected" << endl;
                    break;
                }
                cout << "Do you want go to this submodule again? " << endl;
                cin >> ch;
            }
        }
        break;

        case 3:
        {
            char ch = 'y';
            while (ch == 'y')
            {
                int choice;
                u.menu();
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    // int index;
                    string location;
                    string caseType;
                    string status;
                    // cout << "Enter Index" << endl;
                    // cin >> index;
                    // cout << "Enter unit ID" << endl;
                    // cin >> caseID;
                    cout << "Enter unit type " << endl;
                    cin >> caseType;
                    cout << "Enter unit Location" << endl;
                    cin >> location;
                    // cout << "Enter case Severnity" << endl;
                    // cin >> severnity;
                    cout << "Enter unit Status" << endl;
                    cin >> status;
                    u.appendUnit(caseType, location, status);
                    break;
                }

                case 2:
                {
                    // int index;
                    string location;
                    string caseType;
                    string status;
                    // cout << "Enter Index" << endl;
                    // cin >> index;
                    // cout << "Enter unit ID" << endl;
                    // cin >> caseID;
                    cout << "Enter unit type " << endl;
                    cin >> caseType;
                    cout << "Enter unit Location" << endl;
                    cin >> location;
                    // cout << "Enter case Severnity" << endl;
                    // cin >> severnity;
                    cout << "Enter unit Status" << endl;
                    cin >> status;
                    u.prepandUnit(caseType, location, status);
                    break;
                }

                case 3:
                {
                    int index;
                    cout << "Enter the unit index" << endl;
                    cin >> index;
                    u.removeUnitAtIndex(index);
                    break;
                }

                case 4:
                {
                    string type;
                    cout << "Enter the unit type" << endl;
                    cin >> type;
                    u.findAvailableUnit(type);
                    if (u.findAvailableUnit(type))
                    {
                        cout << "Available" << endl;
                    }
                    else
                        cout << "NOT Available at this Moment!" << endl;

                    break;
                }

                case 5:
                {
                    u.displayUnits();
                    break;
                }

                case 6:
                    u.sendUnit();
                    break;

                default:
                    cout << "Invalid Option Selected" << endl;
                    break;
                }
                cout << "Do you want to send unit again? " << endl;
                cin >> ch;
            }
        }
        break;

        case 4:
        {
            char ch = 'y';
            while (ch == 'y')
            {
                int choice;
                hs->menu();
                cin >> choice;
                switch (choice)
                {
                case 1:
                    hs->seekStack();
                    break;

                case 2:
                    hs->removeStack();
                    break;

                case 3:
                    hs->printStack();
                    break;

                case 4:
                    hs->clearStack();
                    break;

                default:
                    cout << "Invalid Option Selected" << endl;
                    break;
                }
                cout << "Do you want to check history again? " << endl;
                cin >> ch;
            }
        }
        case 5:
        {
            char ch = 'y';
            while (ch == 'y')
            {
                int choice;
                m.displayMenu();
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    string name, type;
                    cout << "Enter place/point name and its type" << endl;
                    cin >> name >> type;
                    m.addPoint(name, type);
                    break;
                }
                case 2:
                {
                    string name, type;
                    int timing;
                    cout << "Enter Source and Destination" << endl;
                    cin >> name >> type;
                    cout << "Enter the time taken" << endl;
                    cin >> timing;
                    m.setRoad(name, type, timing);
                    break;
                }

                case 3:
                {
                    string name, type;
                    // int timing;
                    cout << "Enter Source and Destination" << endl;
                    cin >> name >> type;
                    // cout << "Enter the time taken" << endl;
                    // cin >> timing;
                    m.deleteRoad(name, type);
                    break;
                }

                case 4:
                {
                    string name, type;
                    int weight;
                    cout << "Enter Old Source and Destination" << endl;
                    cin >> name >> type;
                    string name1, type1;
                    cout << "Enter New Source and Destination" << endl;
                    cin >> name1 >> type1;
                    cout << "Enter the timing between new two roads" << endl;
                    cin >> weight;
                    m.updateRoad(name, type, name1, type1, weight);
                    break;
                }

                case 5:
                {
                    string name;
                    cout << "Enter Place" << endl;
                    cin >> name;
                    //          int* ptr= g.getNeighbours(source, neighbourCount);
                    // for (int i = 0; i < neighbourCount; i++)
                    // {
                    //     cout << ptr[i] << endl;
                    // }
                    string *s = m.getConnectedRoads(name);
                    int i = 0;
                    while (s[i] != "")
                    {
                        cout << s[i] << endl;
                        i++;
                    }
                    break;
                }

                case 6:
                {
                    string name;
                    cout << "Enter Place" << endl;
                    cin >> name;

                    int n = m.getConnectedRoadsNumber(name);
                    cout << "Road Connected with " << name << " are " << n << endl;
                    break;
                }
                case 7:
                {
                    string name, name1;
                    cout << "Enter Source and Destination" << endl;
                    cin >> name >> name1;

                    int n = m.getTime(name, name1);
                    cout << "Time to get to " << name1 << " from " << name << " is " << n << endl;
                    break;
                }

                case 8:
                {
                    m.displayMap();
                    break;
                }

                default:
                {
                    cout << "Invalid Option Selected" << endl;
                    break;
                }
                }
                cout << "Do you want to do mapping again? " << endl;
                cin >> ch;
            }
        }
        }
    }
}