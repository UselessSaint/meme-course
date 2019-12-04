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

