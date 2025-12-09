#include "Point.h"

Point::Point()
{
    this->name = "";
    this->type = "";
    this->id = 0;
}

Point::Point(string name, string type, int id)
{
    this->name = name;
    this->type = type;
    this->id = id;
}

void Point::setName(string name)
{
    this->name = name;
}
string Point::getName()
{
    return name;
}
void Point::setPointType(string type)
{
    this->type = type;
}
string Point::getPointType()
{
    return type;
}
void Point::setID(int ID)
{
    this->id = id;
}
int Point::getID()
{
    return id;
}