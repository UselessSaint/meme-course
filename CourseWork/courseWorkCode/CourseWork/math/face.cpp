#include "face.h"

Face::Face(Point &v1, Point &v2, Point &v3)
{
	_vertices.push_back(v1);
	_vertices.push_back(v2);
	_vertices.push_back(v3);

	Point n = (_vertices[1] - _vertices[0]).vecMult(_vertices[2] - _vertices[0]);

	n.norm();

	_normal = n;
}

std::vector<Point> Face::getFaceVertices()
{
	return _vertices;
}

Point Face::getNormal() { return _normal; }
