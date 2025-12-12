#pragma once
#include "Point.h"
#include "../Module-1/CaseManagement-2.h"
#include "../Module-3/UnitPool.h"
#include "../Headers/MyArray.h"

class Map
{
private:
    Graph<int> map;
    MyArray<Point> pointNameList;
    int nextID;
   // Point P;
public:
    Map(/* args */);
    void addPoint(string name, string type);
    void setRoad(string point1, string point2, int time);
    void deleteRoad(string point1, string point2);
    void updateRoad(string oldpt1, string oldpt2, string newpt1, string newpt2, int time);
    string* getConnectedRoads(string point);
    int getTime(string pt1, string p2);
    int getConnectedRoadsNumber(string point);
    void getShortestPath(string pt1, string pt2);
    void displayMap();
    bool isPointValid(string);
    void sendUnitToIncidentPlace();

    void displayMenu();
   // bool checkValidPlace(string point1, string point2);
};
