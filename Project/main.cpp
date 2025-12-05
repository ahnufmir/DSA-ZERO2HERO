#include "IncidentLog-1.h";
#include "DispatchCrime-2.h";

void menu()
{
    cout << "========================== Public-Safety-and-Crime-Monitoring ========================" << endl;
    cout << "1. Incident Log" << endl;
    cout << "2. Dispatch Case" << endl;
    cout << "--------------------" << endl;
}

int main()
{
    CrimeManagement c;
    DispatchQueue d(&c);
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
                c.CrimeManagementMenu();
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    int crimeID;
                    string crimeType;
                    string location;
                    int severnity;
                    string status;
                    cout << "Enter Crime ID" << endl;
                    cin >> crimeID;
                    cout << "Enter Crime Type" << endl;
                    cin >> crimeType;
                    cout << "Enter Crime Location" << endl;
                    cin >> location;
                    cout << "Enter Crime Severnity" << endl;
                    cin >> severnity;
                    cout << "Enter Crime Status" << endl;
                    cin >> status;
                    c.appendCrime(crimeID, crimeType, location, severnity, status);
                    break;
                }

                case 2:
                {
                    int crimeID;
                    string crimeType;
                    string location;
                    int severnity;
                    string status;
                    cout << "Enter Crime ID" << endl;
                    cin >> crimeID;
                    cout << "Enter Crime Type" << endl;
                    cin >> crimeType;
                    cout << "Enter Crime Location" << endl;
                    cin >> location;
                    cout << "Enter Crime Severnity" << endl;
                    cin >> severnity;
                    cout << "Enter Crime Status" << endl;
                    cin >> status;
                    c.prependCrime(crimeID, crimeType, location, severnity, status);
                    break;
                }

                case 3:
                {
                    int index;
                    int crimeID;
                    string crimeType;
                    string location;
                    int severnity;
                    string status;
                    cout << "Enter Index" << endl;
                    cin >> index;
                    cout << "Enter Crime ID" << endl;
                    cin >> crimeID;
                    cout << "Enter Crime Type" << endl;
                    cin >> crimeType;
                    cout << "Enter Crime Location" << endl;
                    cin >> location;
                    cout << "Enter Crime Severnity" << endl;
                    cin >> severnity;
                    cout << "Enter Crime Status" << endl;
                    cin >> status;
                    c.insertCrimeAtAnyIndex(index, crimeID, crimeType, location, severnity, status);
                    break;
                }

                case 4:
                    c.deleteCrimeFromStart();
                    break;

                case 5:
                    c.deleteCrimeFromEnd();
                    break;

                case 6:
                {
                    int index;
                    int crimeID;
                    string crimeType;
                    string location;
                    int severnity;
                    string status;
                    cout << "Enter Index" << endl;
                    cin >> index;
                    cout << "Enter Crime ID" << endl;
                    cin >> crimeID;
                    cout << "Enter Crime Type" << endl;
                    cin >> crimeType;
                    cout << "Enter Crime Location" << endl;
                    cin >> location;
                    cout << "Enter Crime Severnity" << endl;
                    cin >> severnity;
                    cout << "Enter Crime Status" << endl;
                    cin >> status;
                    c.updateCrime(index, crimeID, crimeType, location, severnity, status);
                    break;
                }

                case 7:
                {
                    int crimeID;
                    cout << "Enter Crime ID" << endl;
                    cin >> crimeID;
                    Crime *crime = c.searchByIndex(crimeID);
                    if (crime)
                    {
                        crime->display();
                    }
                    else
                        cout << "Crime doesnot Exist" << endl;
                    break;
                }

                case 8:
                    c.printCrimeList();
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
                    cout << "Case ID" << front.getCrimeID() << endl;
                    cout << "Severity " << front.getSeverity() << endl;
                    cout << "Unit ID " << front.getUnitID() << endl;
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
        }
    }
}