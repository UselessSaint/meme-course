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

std::vector<Point> Face::getFaceVertices() const
{
	return _vertices;
}

Point Face::getNormal() { return _normal; }

void Face::operator=(const Face &other)
{
	_vertices.clear();
	auto v = other.getFaceVertices();

	_vertices.push_back(v[0]);
	_vertices.push_back(v[1]);
	_vertices.push_back(v[2]);

	Point n = (_vertices[1] - _vertices[0]).vecMult(_vertices[2] - _vertices[0]);

	n.norm();

	_normal = n;
}

void Face::changeNormalDir()
{
	_normal.setX(_normal.getX()*(-1));
	_normal.setY(_normal.getY()*(-1));
	_normal.setZ(_normal.getZ()*(-1));
}
