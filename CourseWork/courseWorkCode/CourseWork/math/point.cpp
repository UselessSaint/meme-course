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

Point Point::operator= (const Point& a)
{
    this->equal(a);

    return *this;
}

Point Point::operator- (const Point& a)
{
    Point res;

    res.setX(getX() - a.getX());
    res.setY(getY() - a.getY());
    res.setZ(getZ() - a.getZ());

    return res;
}

void Point::norm()
{
    double vecLen = getX()*getX() + getY()*getY() + getZ()*getZ();
    vecLen = sqrt(vecLen);

    setX(getX()/vecLen);
    setY(getY()/vecLen);
    setZ(getZ()/vecLen);
}

Point Point::sign()
{
    Point res;

    if (round(getX()) < 0)
        res.setX(-1);
    else if (round(getX()) > 0)
        res.setX(1);
    else
        res.setX(0);

    if (round(getY()) < 0)
        res.setY(-1);
    else if (round(getY()) > 0)
        res.setY(1);
    else
        res.setY(0);

    if (round(getZ()) < 0)
        res.setZ(-1);
    else if (round(getZ()) > 0)
        res.setZ(1);
    else
        res.setZ(0);

    return res;
}






















