#ifndef POINT_H
#define POINT_H

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

    void equal(const Point&);
private:
	double _x;
	double _y;
	double _z;
};

#endif // POINT_H
