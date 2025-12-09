#include "Map.h"

// void Map::setVertexName(int index, string name)
// {
//     pointNameList[index].setName(name);
// }
// string Map::getVertexName(int index)
// {
//     return pointNameList[index].getName();
// }
Map::Map()
{
    nextID = 1;
}
void Map::addPoint(string name, string type)
{
    Point P(name, type, nextID);
    pointNameList.append(P);
    map.expandMatrix();
    nextID++;
    //  map.setWeight(source, dest, time);
}

bool Map::isPointValid(string name)
{
    for (int i = 0; i < pointNameList.get_size(); i++)
    {
        if (pointNameList[i].getName() == name)
        {
            return true;
        }
    }
    return false;
}

void Map::setRoad(string point1, string point2, int time)
{
    //  Point *p = pointNameList.get_array();
    if (!isPointValid(point1) || !isPointValid(point2))
    {
        cout << "Invalid Location" << endl;
        return;
    }
    int index1;
    int index2;
    for (int i = 0; i < pointNameList.get_size(); i++)
    {
        if (pointNameList[i].getName() == point1)
        {
            index1 = i;
        }
        if (pointNameList[i].getName() == point2)
        {
            index2 = i;
        }
    }
    map.addEdge(index1, index2, time);
}
void Map::deleteRoad(string point1, string point2)
{
    if (!isPointValid(point1) || !isPointValid(point2))
    {
        cout << "Invalid Location" << endl;
        return;
    }
    int index1;
    int index2;
    for (int i = 0; i < pointNameList.get_size(); i++)
    {
        if (pointNameList[i].getName() == point1)
        {
            index1 = i;
        }
        if (pointNameList[i].getName() == point2)
        {
            index2 = i;
        }
    }
    map.deleteEdge(index1, index2);
}
void Map::updateRoad(string oldpt1, string oldpt2, string newpt1, string newpt2, int time)
{
    if (!isPointValid(oldpt1) || !isPointValid(oldpt2) || !isPointValid(newpt1) || !isPointValid(newpt2))
    {
        cout << "Invalid Location" << endl;
        return;
    }
    int index1, index2, index3, index4;
    for (int i = 0; i < pointNameList.get_size(); i++)
    {
        if (pointNameList[i].getName() == oldpt1)
        {
            index1 = i;
        }
        if (pointNameList[i].getName() == oldpt2)
        {
            index2 = i;
        }
        if (pointNameList[i].getName() == newpt1)
        {
            index3 = i;
        }
        if (pointNameList[i].getName() == newpt2)
        {
            index4 = i;
        }
        
    }

    //addPoint(newpt1)
    map.updateEdge(index1, index2, index3, index4, time);
    
}
string *Map::getConnectedRoads(string point)
{
    if (!isPointValid(point))
    {
        string *result = new string[1];
        result[0] = "Invalid Place";
        return result;
    }
    int index1 = -1;
    for (int i = 0; i < pointNameList.get_size(); i++)
    {
        if (pointNameList[i].getName() == point)
        {
            index1 = i;
            break;
        }
    }
    if (index1 == -1)
    {
        string *results = new string[1];
        results[0] = "No Connected Roads are Found";
        return results;
    }

    int count = 0;
    int *ptr = map.getNeighbours(index1, count);
    string *roads = new string[count];
    // for (int i = 0; i < count; i++)
    // {
    //     cout << ptr[i] << endl;
    // }
    int k = 0;
    for (int i = 0; i < count; i++)
    {
        roads[k] = pointNameList[ptr[i]].getName();
        k++;
    }
    roads[count] = "";
    delete[] ptr;
    return roads;
}
int Map::getTime(string pt1, string pt2)
{
    if (!isPointValid(pt1) || !isPointValid(pt2))
    {
        cout << "Invalid Location" << endl;
        return -1;
    }
    int index1;
    int index2;
    for (int i = 0; i < pointNameList.get_size(); i++)
    {
        if (pointNameList[i].getName() == pt1)
        {
            index1 = i;
        }
        if (pointNameList[i].getName() == pt2)
        {
            index2 = i;
        }
    }
    return (map.getWeight(index1, index2));
}
int Map::getConnectedRoadsNumber(string point)
{
    if (!isPointValid(point))
    {
        cout << "Invalid Location" << endl;
        return -1;
    }
    int index1 = -2;
    for (int i = 0; i < pointNameList.get_size(); i++)
    {
        if (pointNameList[i].getName() == point)
        {
            index1 = i;
            break;
        }
    }
    if (index1 == -2)
    {
        return -1;
    }
    
    return (map.getDegree(index1));
}
void Map::getShortestPath(string pt1, string pt2)
{
    // Left for dijekstra
}
void Map::displayMap()
{
    map.displayGraph();
}
void Map::sendUnitToIncidentPlace(string name1,string name2){
    if (!isPointValid(name1))
    {
        string t1,t2;
        cout << "Enter the type for first place" << endl;
        cin >> t1;
        addPoint(name1, t1);
        cout << "Enter the type for second place" << endl;
        addPoint(name2,t2);
    }
    getShortestPath(name1,name2);
    
}
void Map::displayMenu(){
    cout << "========================== Mapping City System ===================" << endl;
    cout << "1. Add a Place" << endl;
    cout << "2. Add a road between two places " << endl;
    cout << "3. Delete Road" << endl;
    cout << "4. Update Road" << endl;
    cout << "5. Get a list of Connected Roads" << endl;
    cout << "6. Get the number of connected roads with a place" << endl;
    cout << "7. Get time taken between two place" << endl;
    cout << "8. Display Maps" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "9. Get the shortest time taken path between Incident Place & Unit Place" << endl;
}