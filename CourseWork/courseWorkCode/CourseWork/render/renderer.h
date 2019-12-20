#ifndef RENDERER_H
#define RENDERER_H

#include <QPainter>
#include <cmath>
#include "../math/point.h"
#include "../scene/scene.h"
#include "../RayTrace/raytrace.h"
#include <mutex>
#include <thread>
#include <functional>
#include "z_buffer/zbuffer.h"

class Renderer
{
public:
	Renderer(QPainter *painter);

	std::pair<int, int> getSize();
	void drawPoint(QColor &color, int x, int y);

	void renderRaytrace(Scene &scene, int depth, int thrd);
    void renderZBuffer(Scene *scene, bool fl);
private:
	QPainter *_painter;
	std::mutex _mutex;

	void raytraceThreadRender(RayTrace &raytracer, std::pair<int, int> yEdges, Point viewPos, int depth);
};

#endif // RENDERER_H
