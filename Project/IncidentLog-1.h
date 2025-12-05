#ifndef INCIDENTLOG_1_H
#define INCIDENTLOG_1_H

#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

struct Crime
{
    private:
    int crimeID;
    string crimeType;
    string location;
    int severnity;
    string status;

    public:
    Crime();
    Crime(int, string, string, int, string);
    void setCrimeID(int);
    int getCrimeID();
    void setCrimeType(string);
    string getCrimeType();
    void setLocation(string);
    string getLocation();
    void setSeverity(int);
    int getSeverity();
    void setStatus(string);
    string getStatus();
    void display();
    friend class CrimeManagement;
    
};

inline ostream& operator<<(ostream& out, Crime& c)
{
    out << "ID: " << c.getCrimeID() 
        << ", Type: " << c.getCrimeType()
        << ", Location: " << c.getLocation()
        << ", Severity: " << c.getSeverity()
        << ", Status: " << c.getStatus();
    return out;
}

class CrimeManagement
{
private:
    List<Crime>CrimeList;
    int size;
public:
    
    CrimeManagement();
    void appendCrime(int crimeID, string, string, int, string);
    void prependCrime(int crimeID, string, string, int, string);
    void insertCrimeAtAnyIndex(int index, int crimeID, string, string, int, string);
    void deleteCrimeFromStart();
    void deleteCrimeFromEnd();
    void updateCrime(int index, int crimeID, string, string, int, string);
    Crime* searchByIndex(int crimeID);
    void printCrimeList();
    void CrimeManagementMenu();
    int getSize();
    List<Crime> getCrimeList();

    ~CrimeManagement();
};


#endif 