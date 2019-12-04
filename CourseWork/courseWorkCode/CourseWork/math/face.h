#ifndef EDGE_H
#define EDGE_H

#include <vector>
#include "point.h"

class Face
{
public:
    Face() = default;
    Face(Point &v1, Point &v2, Point &v3);

    std::vector<Point> getFaceVertices();
private:
	std::vector<Point> _vertices;
};

#endif // EDGE_H