#include "Case-1.h"

Case::Case()
{
    caseID = 0;
    caseType = "";
    location = "";
    severnity = 0;
    status = "";
}

Case::Case(int id, string type, string l, int s, string stat)
{
    caseID = id;
    caseType = type;
    location = l;
    severnity = s;
    status = stat;
}

void Case::setCaseID(int id)
{
    caseID = id;
}
int Case::getCaseID()
{
    return caseID;
}
void Case::setCaseType(string type)
{
    caseType = type;
}
string Case::getCaseType()
{
    return caseType;
}
void Case::setLocation(string l)
{
    location = l;
}
string Case::getLocation()
{
    return location;
}
void Case::setSeverity(int s)
{
    severnity = s;
}
int Case::getSeverity()
{
    return severnity;
}
void Case::setStatus(string s)
{
    status = s;
}
string Case::getStatus()
{
    return status;
}
void Case::display()
{
    cout << "ID: " << caseID << ", Type: " << caseType
         << ", Location: " << location << ", Severity: " << severnity
         << ", Status: " << status << endl;
}

