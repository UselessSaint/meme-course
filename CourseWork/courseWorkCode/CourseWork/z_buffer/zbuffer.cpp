#include "zbuffer.h"

zBuffer::zBuffer(Scene *scene): _scene(scene) {}

void zBuffer::drawPoint(QPainter *painter, QColor &color, int x, int y)
{
	auto w = painter->window().width() / 2;
	auto h = painter->window().height() / 2;
	painter->setPen(color);
	painter->drawPoint(w + x , h - y);
}

void zBuffer::renderGouraud(QPainter *painter)
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

		Point objColor = obj->getColor();

		for (auto face : curObjFaces)
		{
			auto verts = face.getFaceVertices();

			Point v1 = verts[1] - verts[0];
			Point v2 = verts[2] - verts[0];
			v1.norm();
			v2.norm();

			Point cur1 = verts[0];
			Point cur2 = verts[0];

			Point nv0 = findNormalToPoint(verts[0], *obj);
			Point nv1 = findNormalToPoint(verts[1], *obj);
			Point nv2 = findNormalToPoint(verts[2], *obj);

			Point v0Color = calcLight(verts[0], nv0, objColor, *obj);
			Point v1Color = calcLight(verts[1], nv1, objColor, *obj);
			Point v2Color = calcLight(verts[2], nv2, objColor, *obj);

			Point cv1 = v1Color - v0Color;
			Point cv2 = v2Color - v0Color;

			cv1 = cv1/(verts[1] - verts[0]).len();
			cv2 = cv2/(verts[2] - verts[0]).len();

			Point curC1 = v0Color;
			Point curC2 = v0Color;

			while (1)
			{
				Point mvec = cur2 - cur1;
				mvec.norm();
				Point curm = cur1;

				Point mvecol = curC2 - curC1;
				mvecol = mvecol / (cur2 - cur1).len();
				Point curCol = curC1;

				if (!((cur1-verts[0]).len() <= (verts[0] - verts[1]).len()) &&
					!((cur2-verts[0]).len() <= (verts[0] - verts[2]).len()))
					break;

				while ((curm - cur1).len() <= (cur1 - cur2).len())
				{
					double cx = size.first/2 + curm.getX()*800/(curm.getZ() + 800),
						   cy = size.second/2 + curm.getY()*800/(curm.getZ() + 800);

					cx = ceil(cx);
					cy = ceil(cy);

					if (cx >= 0 && cx < size.first && cy >= 0 && cy < size.second)
					{
						if (screenInfo[size_t(cx)][size_t(cy)].first > curm.getZ())
						{
							screenInfo[size_t(cx)][size_t(cy)].first = curm.getZ();
							screenInfo[size_t(cx)][size_t(cy)].second = curCol;
						}
					}
					if (mvec.getX() == 0 && mvec.getY() == 0 && mvec.getZ() == 0)
						break;
					curm = curm + mvec;
					curCol = curCol + mvecol;
				}


				if (((cur1-verts[0]).len() <= (verts[0] - verts[1]).len()))
				{
					cur1 = cur1 + v1;
					curC1 = curC1 + cv1;
				}
				if (((cur2-verts[0]).len() <= (verts[0] - verts[2]).len()))
				{
					cur2 = cur2 + v2;
					curC2 = curC2 + cv2;
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

void zBuffer::renderPhong(QPainter *painter)
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

		Point objColor = obj->getColor();

		for (auto face : curObjFaces)
		{
			auto verts = face.getFaceVertices();

			Point v1 = verts[1] - verts[0];
			Point v2 = verts[2] - verts[0];
			v1.norm();
			v2.norm();

			Point cur1 = verts[0];
			Point cur2 = verts[0];

			Point n = face.getNormal();

			while (1)
			{
				Point mvec = cur2 - cur1;
				mvec.norm();
				Point curm = cur1;

				if (!((cur1-verts[0]).len() <= (verts[0] - verts[1]).len()) &&
					!((cur2-verts[0]).len() <= (verts[0] - verts[2]).len()))
					break;

				while ((curm - cur1).len() <= (cur1 - cur2).len())
				{
					double cx = size.first/2 + curm.getX()*800/(curm.getZ() + 800),
						   cy = size.second/2 + curm.getY()*800/(curm.getZ() + 800);

					if (cx >= 0 && cx < size.first && cy >= 0 && cy < size.second)
					{
						if (screenInfo[size_t(cx)][size_t(cy)].first > curm.getZ())
						{
							screenInfo[size_t(cx)][size_t(cy)].first = curm.getZ();
							screenInfo[size_t(cx)][size_t(cy)].second = calcLight(curm, n, objColor, *obj);
						}
					}
					if (mvec.getX() == 0 && mvec.getY() == 0 && mvec.getZ() == 0)
						break;
					curm = curm + mvec;
				}


				if (((cur1-verts[0]).len() <= (verts[0] - verts[1]).len()))
				{
					cur1 = cur1 + v1;
				}
				if (((cur2-verts[0]).len() <= (verts[0] - verts[2]).len()))
				{
					cur2 = cur2 + v2;
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

Point zBuffer::findNormalToPoint(Point &pt, Object &obj)
{
	Point n(0,0,0);
	int count = 0;

	for (auto face : obj.getMesh()->getFaces())
	{
		for (auto facePt : face.getFaceVertices())
		{
			if (pt == facePt)
			{
				Point tmpN = face.getNormal();

				n = n + tmpN;
				count++;
			}
		}
	}

	n = n/count;

	n.norm();

	return n;
}

Point zBuffer::calcLight(Point &pt, Point &n, Point &objColor, const Object &curObj)
{
	auto sceneLights = _scene->getLights();
	Point pnt = pt;
	Point pnt2 = pt;

	Point res(0, 0, 0);

	double intens = 0.0;

	Point vecToCenter = curObj.getCenter() - pnt;
	vecToCenter.norm();

	for (auto lt : sceneLights)
	{
		Point dir = lt->getPos() - pnt;
		double lenBetween = dir.len();
		dir.norm();

		Point reflRay1 = n*n.scalarMult(dir);
		reflRay1 = reflRay1 * (-2.0);
		reflRay1 = reflRay1 + dir;
		reflRay1.norm();

		pnt = pnt + n;

        Point view(0, 0, -800);

		Point tmp = (pnt-view);
		tmp.norm();

		if (!isIntersecting(pnt, dir))
		{
			double curLtIntent = lt->getIntens() / lenBetween;
			intens += curObj.getDispertionCoef()*fabs(dir.scalarMult(n))*curLtIntent;
			intens += curObj.getReflecitonCoef()*pow(fabs(tmp.scalarMult(reflRay1)), curObj.getGlossCoef())*curLtIntent;
		}
	}

	intens += 0.2;

	if (intens > 1)
		intens = 1;
	if (intens < 0)
		intens = 0;

	res.setX(objColor.getX()*intens);
	res.setY(objColor.getY()*intens);
	res.setZ(objColor.getZ()*intens);

	return res;
}

bool zBuffer::isIntersecting(Point &start, Point &direction)
{
	auto sceneObjs = _scene->getObjects();

	for (auto obj : sceneObjs)
	{
		auto curObjMesh = obj->getMesh();
		auto curObjFaces = curObjMesh->getFaces();

		for (auto face : curObjFaces)
		{
			auto verts = face.getFaceVertices();

			Point n = face.getNormal();

			double div = n.scalarMult(direction);
			double t;

			if (div != 0.0)
			{
				t = n.scalarMult(verts[0] - start)/div;
			}
			else
				continue;

			if (t < 0)
				continue;

			Point curPt(start.getX() + t*direction.getX(),
						start.getY() + t*direction.getY(),
						start.getZ() + t*direction.getZ());
			Point vecs[3];

			vecs[0] = (verts[1] - verts[0]).vecMult(curPt - verts[0]);
			vecs[1] = (verts[2] - verts[1]).vecMult(curPt - verts[1]);
			vecs[2] = (verts[0] - verts[2]).vecMult(curPt - verts[2]);

			vecs[0] = vecs[0].sign();
			vecs[1] = vecs[1].sign();
			vecs[2] = vecs[2].sign();

			if ( (vecs[0].getX()*vecs[1].getX()) >= 0 && (vecs[1].getX()*vecs[2].getX()) >= 0 && (vecs[2].getX()*vecs[0].getX()) >= 0 &&
				 (vecs[0].getY()*vecs[1].getY()) >= 0 && (vecs[1].getY()*vecs[2].getY()) >= 0 && (vecs[2].getY()*vecs[0].getY()) >= 0 &&
				 (vecs[0].getZ()*vecs[1].getZ()) >= 0 && (vecs[1].getZ()*vecs[2].getZ()) >= 0 && (vecs[2].getZ()*vecs[0].getZ()) >= 0 )
			{
				return true;
			}
		}
	}

	return false;
}

















