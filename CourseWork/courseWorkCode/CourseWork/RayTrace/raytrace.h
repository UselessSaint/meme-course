#ifndef RAYTRACE_H
#define RAYTRACE_H

#include "../scene/scene.h"
#include "../math/point.h"
#include "../math/mesh.h"
#include "../math/face.h"
#include "../scene/light.h"
#include <iostream>

class RayTrace
{
public:
	RayTrace();
	RayTrace(Scene *scene);

	void setScene(Scene *scene);
	Point traceRay(Point &start, Point &direction, int depth);
	Point calcLight(Point &start, Point &objColor, Point &n, Point &view, Point &reflRay, const Object &curObj);
	bool isIntersecting(Point &start, Point &dir);
private:
	Scene *_scene;
};

#endif // RAYTRACE_H
