#include "renderer.h"

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
	// do cool stuff
}
