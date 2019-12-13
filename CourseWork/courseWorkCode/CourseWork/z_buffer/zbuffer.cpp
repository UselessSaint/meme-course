#include "zbuffer.h"

zBuffer::zBuffer(Scene *scene): _scene(scene) {}

void zBuffer::drawPoint(QPainter *painter, QColor &color, int x, int y)
{
	auto w = painter->window().width() / 2;
	auto h = painter->window().height() / 2;
	painter->setPen(color);
	painter->drawPoint(w + x , h - y);
}

void zBuffer::render(QPainter *painter)
{
	auto sceneObjs = _scene->getObjects();

	Point bgColor(255, 255, 255);
	std::vector<std::vector<std::pair<double, Point>>> screenInfo;

	std::pair<int, int> size = {painter->window().width(), painter->window().height()};
	std::pair<double, Point> info = {2000000, bgColor};

	for (int i = 0; i < size.first; i++)
	{
		std::vector<std::pair<double, Point>> tmp;
		for (int j = 0; j < size.second; j++)
		{
			tmp.push_back(info);
		}
		screenInfo.push_back(tmp);
	}

	for (auto obj : sceneObjs)
	{
		auto curObjMesh = obj->getMesh();
		auto curObjFaces = curObjMesh->getFaces();

		for (auto face : curObjFaces)
		{
			auto verts = face.getFaceVertices();

			Point v1 = verts[1] - verts[0];
			Point v2 = verts[2] - verts[0];
			v1.norm();
			v2.norm();

			Point cur1 = verts[0];
			Point cur2 = verts[0];

			while (1)
			{
				Point mvec = cur2 - cur1;
				mvec.norm();
				Point curm = cur1;

				if (!((cur1-verts[0]).len() < (verts[0] - verts[1]).len()) &&
					!((cur2-verts[0]).len() < (verts[0] - verts[2]).len()))
					break;

				if (((cur1-verts[0]).len() < (verts[0] - verts[1]).len()))
					cur1 = cur1 + v1;
				if (((cur2-verts[0]).len() < (verts[0] - verts[2]).len()))
					cur2 = cur2 + v2;

				while ((curm - cur1).len() <= (cur1 - cur2).len())
				{
					int cx = int(round(curm.getX())),
						cy = int(round(curm.getY()));

					cx += size.first/2;
					cy += size.second/2;

					if (cx >= 0 && cx < size.first && cy >= 0 && cy < size.second)
					{
						if (screenInfo[size_t(cx)][size_t(cy)].first > curm.getZ())
						{
							screenInfo[size_t(cx)][size_t(cy)].first = curm.getZ();
							screenInfo[size_t(cx)][size_t(cy)].second = obj->getColor();
						}
					}

					curm = curm + mvec;
				}
			}
		}
	}

	for (int i = 0; i < size.first; i++)
	{
		for (int j = 0; j < size.second; j++)
		{
			QColor q_color(screenInfo[i][j].second.getX(), screenInfo[i][j].second.getY(), screenInfo[i][j].second.getZ());

			drawPoint(painter, q_color, i - size.first/2, j - size.second/2);
		}
	}
}



















