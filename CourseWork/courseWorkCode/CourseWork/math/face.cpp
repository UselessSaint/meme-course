#include "face.h"

Face::Face(Point &v1, Point &v2, Point &v3)
{
	_vertices.push_back(v1);
	_vertices.push_back(v2);
	_vertices.push_back(v3);
}

std::vector<Point> Face::getFaceVertices()
{
	return _vertices;
}
