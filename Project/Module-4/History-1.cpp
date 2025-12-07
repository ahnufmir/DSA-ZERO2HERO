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

History::History(int caseID, string caseType, int severity, string caseStatus, int unitID, string unitType, string unitStatus)
{
    this->caseID = caseID;
    this->caseType = caseType;
    this->severity = severity;
    this->caseStatus = caseStatus;
    this->unitID = unitID;
    this->unitType = unitType;
    this->unitStatus = unitStatus;
}