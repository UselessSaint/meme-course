#include "mesh.h"

Mesh::Mesh(std::vector<Point> &verts, std::vector<Face> &faces):
    _vertices(verts),
    _faces(faces) {};

std::vector<Point> Mesh::getVertices()
{
    return _vertices;
}

std::vector<Face> Mesh::getFaces()
{
	return _faces;
}

void Mesh::setVertice(size_t i, Point &other)
{
	if (i < _vertices.size())
		_vertices[i] = other;
}

void Mesh::setFace(size_t i, Face &other)
{
	if (i < _faces.size())
		_faces[i] = other;
}
