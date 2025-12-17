#include "History-1.h"

History::History()
{
    this->caseID = 0;
    this->caseType = "";
    this->severity = 0;
    this->caseStatus = "";
    this->unitID = 0;
    this->unitType = "";
    this->unitStatus = "";
}

History::History(int caseID, string caseType, int severity, string caseStatus, int unitID, string unitType, string unitStatus, int time)
{
    this->caseID = caseID;
    this->caseType = caseType;
    this->severity = severity;
    this->caseStatus = caseStatus;
    this->unitID = unitID;
    this->unitType = unitType;
    this->unitStatus = unitStatus;
    this->ETA = time;
}
int History::getCaseID() const
{
    return caseID;
}
string History::getCaseType() const
{
    return caseType;
}
int History::getSeverity() const
{
    return severity;
}
string History::getCaseStatus() const
{
    return caseStatus;
}
int History::getUnitID() const
{
    return unitID;
}
string History::getUnitType() const
{
    return unitType;
}
string History::getUnitStatus() const
{
    return unitStatus;
}
int History::getETA() const
{
    return ETA;
}

void History::setCaseID(int id)
{
    caseID = id;
}
void History::setCaseType(string type)
{
    caseType = type;
}
void History::setCaseStatus(string status)
{
    caseStatus = status;
}
void History::setSeverity(int s)
{
    severity = s;
}
void History::setunitID(int u)
{
    unitID = u;
}
void History::setUnitType(string type)
{
    unitType = type;
}
void History::setUnitStatus(string status)
{
    unitStatus = status;
}
void History::setETA(int t)
{
    ETA = t;
}