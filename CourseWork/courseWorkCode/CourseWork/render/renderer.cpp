#include "renderer.h"

Renderer::Renderer(QPainter *painter): _painter(painter) {}

void Renderer::drawPoint(QColor &color, int x, int y) {
	auto w = _painter->window().width() / 2;
	auto h = _painter->window().height() / 2;
	_painter->setPen(color);
    _painter->drawPoint(w + x , h - y);
}

std::pair<int, int> Renderer::getSize() {
	return {_painter->window().width(), _painter->window().height()};
}

void Renderer::renderRaytrace(Scene &scene, int depth, bool pflag, int thrd)
{
	auto raytracer = new RayTrace(&scene);
	auto size = getSize();

    Point viewPos(0, 0, -800);

	std::vector<std::thread> threads;
	int amountOfThreads = thrd;

	int deltaY = size.second / amountOfThreads;

	for (int i = 0; i < amountOfThreads ; i++)
	{
		std::pair<int, int> yEdges = {-size.second/2 + i*deltaY, -size.second/2 + (i+1)*deltaY};

		std::thread thread(
					[this](RayTrace rt, std::pair<int, int> yEdges, Point viewPos, int depth, bool pflag) { this->raytraceThreadRender(rt, yEdges, viewPos, depth, pflag); },
		*raytracer, yEdges, viewPos, depth, pflag);

		threads.push_back(std::move(thread));
	}

	for (auto &thr: threads)
	{
		if (thr.joinable())
		{
			thr.join();
		}
	}
}

void Renderer::raytraceThreadRender(RayTrace &raytracer, std::pair<int, int> yEdges, Point viewPos, int depth, bool pflag)
{
	auto size = getSize();

	for (int x = -size.first/2; x < size.first/2; x++)
	{
		for (int y = yEdges.first; y < yEdges.second; y++)
		{
			if (pflag)
			{
				viewPos.setX(x);
				viewPos.setY(y);
			}

			Point dir(x, y, 0);
			dir = dir - viewPos;
			dir.norm();
			Point curColor = raytracer.traceRay(viewPos, dir, depth);

			QColor q_color(curColor.getX(), curColor.getY(), curColor.getZ());

			_mutex.lock();
			drawPoint(q_color, x, y);
			_mutex.unlock();
		}
	}
}

void Renderer::renderZBuffer(Scene *scene, bool fl)
{
	auto zbuf = new zBuffer(scene);

	if (fl)
		zbuf->renderGouraud(_painter);
	else
		zbuf->renderPhong(_painter);
}





















