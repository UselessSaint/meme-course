#include "renderer.h"

Renderer::Renderer(QPainter *painter): _painter(painter) {}

void Renderer::drawLine(Point &p1,Point &p2) {
	auto w = _painter->window().width() / 2;
	auto h = _painter->window().height() / 2;
	_painter->drawLine(w + std::round(p1.getX()), h - std::round(p1.getY()),
					   w + std::round(p2.getX()), h - std::round(p2.getY()));
}

void Renderer::drawPoint(QColor &color, int x, int y) {
	auto w = _painter->window().width() / 2;
	auto h = _painter->window().height() / 2;
	_painter->setPen(color);
    _painter->drawPoint(w + x , h - y);
}

std::pair<int, int> Renderer::getSize() {
	return {_painter->window().width(), _painter->window().height()};
}

void Renderer::render(Scene &scene)
{
	auto raytracer = new RayTrace(&scene);

	auto size = getSize();

	Point viewPos(0, 0, -800);

	for (int x = -size.second/2; x < size.first/2; x++)
	{
		for (int y = -size.second/2; y < size.second/2; y++)
		{
			Point dir(x, y, 0);
			dir = dir - viewPos;
			dir.norm();
			Point curColor = raytracer->traceRay(viewPos, dir, 3);
			if (curColor.getX() > 255)
				curColor.setX(255);
			if (curColor.getX() < 0)
				curColor.setX(0);

			if (curColor.getY() > 255)
				curColor.setY(255);
			if (curColor.getY() < 0)
				curColor.setY(0);

			if (curColor.getZ() > 255)
				curColor.setZ(255);
			if (curColor.getZ() < 0)
				curColor.setZ(0);
			QColor q_color(curColor.getX(), curColor.getY(), curColor.getZ());
			//std::cout << curColor.getX();

			drawPoint(q_color, x, y);
		}
	}
}
