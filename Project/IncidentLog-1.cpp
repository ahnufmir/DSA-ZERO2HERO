#include "IncidentLog-1.h"

Crime::Crime()
{
    crimeID = 0;
    crimeType = "";
    location = "";
    severnity = 0;
    status = "";
}

Crime::Crime(int id, string type, string l, int s, string stat)
{
    crimeID = id;
    crimeType = type;
    location = l;
    severnity = s;
    status = stat;
}

void Crime::setCrimeID(int id)
{
    crimeID = id;
}
int Crime::getCrimeID()
{
    return crimeID;
}
void Crime::setCrimeType(string type)
{
    crimeType = type;
}
string Crime::getCrimeType()
{
    return crimeType;
}
void Crime::setLocation(string l)
{
    location = l;
}
string Crime::getLocation()
{
    return location;
}
void Crime::setSeverity(int s)
{
    severnity = s;
}
int Crime::getSeverity()
{
    return severnity;
}
void Crime::setStatus(string s)
{
    status = s;
}
string Crime::getStatus()
{
    return status;
}
void Crime::display()
{
    cout << "ID: " << crimeID << ", Type: " << crimeType
         << ", Location: " << location << ", Severity: " << severnity
         << ", Status: " << status << endl;
}

CrimeManagement::CrimeManagement()
{
    size = 0;
}

CrimeManagement::~CrimeManagement()
{
}

void CrimeManagement::appendCrime(int crimeID, string crimeType, string location, int severnity, string status)
{
    Crime newCrime(crimeID, crimeType, location, severnity, status);
    CrimeList.append(newCrime);
    size++;
}

void CrimeManagement::prependCrime(int crimeID, string crimeType, string location, int severnity, string status)
{
    Crime newCrime(crimeID, crimeType, location, severnity, status);
    CrimeList.prepend(newCrime);
    size++;
}

void CrimeManagement::insertCrimeAtAnyIndex(int index, int crimeID, string crimeType, string location, int severnity, string status)
{
    Crime newCrime(crimeID, crimeType, location, severnity, status);
    CrimeList.insertAtIndex(index, newCrime);
    size++;
}
void CrimeManagement::deleteCrimeFromStart()
{
    CrimeList.deleteFromStart();
    size--;
}
void CrimeManagement::deleteCrimeFromEnd()
{
    CrimeList.deleteFromEnd();
    size--;
}
void CrimeManagement::updateCrime(int index, int crimeID, string crimeType, string location, int severnity, string status)
{
    Crime updatedCrime(crimeID, crimeType, location, severnity, status);
    CrimeList.updateAtIndex(index, updatedCrime);
}
void CrimeManagement::printCrimeList()
{
    CrimeList.printList();
}
Crime *CrimeManagement::searchByIndex(int crimeID)
{
    Node<Crime> *node = CrimeList.getNodeAtIndex(crimeID);
    Crime *crimePtr =  &(node->getData());
    return crimePtr;
}
int CrimeManagement:: getSize(){
    return size;
}

List<Crime> CrimeManagement:: getCrimeList(){
    return CrimeList;
}

void CrimeManagement::CrimeManagementMenu()
{

    cout << "================== MENU ===================" << endl;
    cout << "1. Append Crime" << endl;
    cout << "2. Prepend Crime" << endl;
    cout << "3. Insert Crime at any Place" << endl;
    cout << "4. Delete First Crime" << endl;
    cout << "5. Delete Last Crime" << endl;
    cout << "6. Update Crime" << endl;
    cout << "7. Search Crime  " << endl;
    cout << "8. Display Crime" << endl;
    cout << "-----------------------------" << endl;
}
