#ifndef MESH_H
#define MESH_H

#include <vector>
#include "point.h"
#include "face.h"

class Mesh
{
public:
    Mesh() = default;
    Mesh(std::vector<Point> &p, std::vector<Face> &f);

    std::vector<Point> getVertices();

    std::vector<Face> getFaces();
private:
	std::vector<Point> _vertices;
	std::vector<Face> _faces;
};

#endif // MESH_H
