#ifndef RENDERER_H
#define RENDERER_H

#include <QPainter>
#include <cmath>
#include "../math/point.h"
#include "../scene/scene.h"

class Renderer
{
public:
	Renderer(QPainter *painter);

	void drawLine(Point &p1,Point &p2);
	std::pair<int, int> getSize();
	void drawPoint(QColor &color, int x, int y);

	void render(Scene &scene);
private:
	QPainter *_painter;

	// подкрючить рейтрейсер тута
	// подключить збуффер тута
};

#endif // RENDERER_H
