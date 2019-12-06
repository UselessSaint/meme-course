#include "raytrace.h"

RayTrace::RayTrace(){}

RayTrace::RayTrace(Scene *scene): _scene(scene) {}
/*
void setScene(Scene *scene)
{
}
*/
Point RayTrace::traceRay(Point &start, Point &direction, int depth)
{
	auto sceneObjs = _scene->getObjects();

	double closestT = 0;
	Point closestColor;

	for (auto obj : sceneObjs)
	{
		auto curObjMesh = obj->getMesh();
		auto curObjFaces = curObjMesh->getFaces();

		for (auto face : curObjFaces)
		{
			auto verts = face.getFaceVertices();

			Point v1 = verts[1] - verts[0];
			Point v2 = verts[2] - verts[0];

			Point n = v1.vecMult(v2);
			n.norm();

			double div =
		}
	}
}
