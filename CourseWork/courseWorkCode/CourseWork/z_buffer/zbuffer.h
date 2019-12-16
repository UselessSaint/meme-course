#ifndef ZBUFFER_H
#define ZBUFFER_H

#include "../scene/scene.h"
#include "../math/point.h"
#include "../math/mesh.h"
#include "../math/face.h"
#include "../scene/light.h"
#include <iostream>
#include <mutex>
#include <QPainter>
#include <cmath>

class zBuffer
{
public:
	zBuffer();
	zBuffer(Scene *scene);

	void renderGouraud(QPainter *painter);
	void renderPhong(QPainter *painter);
	void drawPoint(QPainter *painter, QColor &color, int x, int y);
private:
	Scene *_scene;

	Point calcLight(Point &pt, Point &normal, Point &objColor, const Object &curObj);
	Point findNormalToPoint(Point &pnt, Object &obj);
	bool isIntersecting(Point &start, Point &dir);
};

#endif // ZBUFFER_H
