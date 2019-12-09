#ifndef POINT_H
#define POINT_H

#include <cmath>

class Point
{
public:
    Point() = default;
	Point(double x, double y, double z);
    Point(const Point&);

	void setX(double x);
	void setY(double y);
	void setZ(double z);

    double getX() const;
    double getY() const;
    double getZ() const;

	double scalarMult(Point);
	Point vecMult(Point);
    Point sign();
	double len();

    void equal(const Point&);
    void norm();

    Point operator= (const Point&);
	Point operator- (const Point&);
private:
	double _x;
	double _y;
	double _z;
};

#endif // POINT_H
