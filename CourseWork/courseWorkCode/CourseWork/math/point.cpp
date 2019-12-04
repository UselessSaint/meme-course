#include "point.h"

Point::Point(double x, double y, double z): _x(x), _y(y), _z(z) {}

Point::Point(const Point& p)
{
	_x = p.getX();
	_y = p.getY();
	_z = p.getZ();
}

void Point::setX(double x)
{
	_x = x;
}

void Point::setY(double y)
{
	_y = y;
}

void Point::setZ(double z)
{
	_z = z;
}

double Point::getX() const
{
	return _x;
}

double Point::getY() const
{
	return _y;
}

double Point::getZ() const
{
	return _z;
}

double Point::scalarMult(Point a)
{
	return a.getX()*getX() + a.getY()*getY() + a.getZ()*getZ();
}

Point Point::vecMult(Point b)
{
	Point res(getY()*b.getZ() - getZ()*b.getY(),
			  getZ()*b.getX() - getX()*b.getZ(),
			  getX()*b.getY() - getY()*b.getX());
	return res;
}

void Point::equal(const Point &other)
{
    setX(other.getX());
    setY(other.getY());
    setZ(other.getZ());
}

























