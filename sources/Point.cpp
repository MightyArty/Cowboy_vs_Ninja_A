#include "Point.hpp"

using namespace std;
using namespace ariel;

Point::Point(double x, double y) : _x(x), _y(y){};

Point::Point()
{
    this->_x = 0;
    this->_y = 0;
}

double Point::getX() const
{
    return this->_x;
}

double Point::getY() const
{
    return this->_y;
}

void Point::setX(double new_x)
{
    this->_x = new_x;
}

void Point::setY(double new_y)
{
    this->_y = new_y;
}

void Point::print()
{
    return;
}

double Point::distance(Point &other)
{
    return 0;
}

Point Point::moveTowards(Point &first, Point &second, double distance)
{
    Point p(0, 0);
    return p;
}