#pragma once
#include "iostream"
#include "../Headers/Graphs.h"
#include "../Headers/MyArray.h"

using namespace std;

class Point
{
private:
    string name;
    string type;
    int id;
public:
    Point();
    Point(string name, string type, int id );
    void setName(string);
    string getName();
    void setPointType(string);
    string getPointType();
    void setID(int);
    int getID();
    friend class Map;
};


