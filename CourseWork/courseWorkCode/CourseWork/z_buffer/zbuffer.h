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

class zBuffer
{
public:
	zBuffer();
	zBuffer(Scene *scene);

	void render(QPainter *painter);
	void drawPoint(QPainter *painter, QColor &color, int x, int y);
private:
	Scene *_scene;
};

#endif // ZBUFFER_H
