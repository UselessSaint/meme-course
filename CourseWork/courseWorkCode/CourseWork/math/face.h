#ifndef EDGE_H
#define EDGE_H

#include <vector>
#include "point.h"

class Face
{
public:
    Face() = default;
	Face(Point &v1, Point &v2, Point &v3);

	std::vector<Point> getFaceVertices() const;
	Point getNormal();
	void changeNormalDir();

	void operator=(const Face&);
private:
	std::vector<Point> _vertices;
	Point _normal;
};

#endif // EDGE_H
