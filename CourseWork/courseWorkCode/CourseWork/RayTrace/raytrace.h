#ifndef RAYTRACE_H
#define RAYTRACE_H

#include "../scene/scene.h"
#include "../math/point.h"
#include "../math/mesh.h"
#include "../math/face.h"

class RayTrace
{
public:
	RayTrace();
	RayTrace(Scene *scene);

	void setScene(Scene *scene);
	Point traceRay(Point &start, Point &direction, int depth);

private:
	Scene *_scene;
};

#endif // RAYTRACE_H
