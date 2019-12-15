#include "raytrace.h"

RayTrace::RayTrace(){}

RayTrace::RayTrace(Scene *scene): _scene(scene) {}

Point RayTrace::traceRay(Point &start, Point &direction, int depth)
{
	auto sceneObjs = _scene->getObjects();

	double closestT = 0;
	Point bgColor(255,255,255);
	Point closestColor = bgColor;

	for (auto obj : sceneObjs)
	{
        auto curObjMesh = obj->getMesh();
		auto curObjFaces = curObjMesh->getFaces();

		Point viewCenterVec = start - obj->getCenter();
		double B = 2*(direction.getX()*viewCenterVec.getX() +
					  direction.getY()*viewCenterVec.getY() +
					  direction.getZ()*viewCenterVec.getZ());
		double C = viewCenterVec.len()*viewCenterVec.len() - obj->getRadius()*obj->getRadius();

		if ((B*B - 4*C) < 0.0)
			continue;

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

			Point vecToCenter = obj->getCenter() - curPt;
			vecToCenter.norm();

			if ( (n.getX() * vecToCenter.getX() >= 0) &&
				 (n.getY() * vecToCenter.getY() >= 0) &&
				 (n.getZ() * vecToCenter.getZ() >= 0))
			{
				n.setX(n.getX()*(-1));
				n.setY(n.getY()*(-1));
				n.setZ(n.getZ()*(-1));
			}

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
				if (closestT > t || closestT == 0.0)
				{
					closestT = t;
					closestColor = obj->getColor();
					curPt.setX(curPt.getX() + n.getX());
					curPt.setY(curPt.getY() + n.getY());
					curPt.setZ(curPt.getZ() + n.getZ());

					Point reflRay = n*n.scalarMult(direction);
					reflRay = reflRay * (-2.0);
					reflRay = reflRay + direction;
					reflRay.norm();

					closestColor = calcLight(curPt, closestColor, n, start, *obj);
					if (depth > 0)
					{
						Point refColor = traceRay(curPt, reflRay, depth-1);

						if (refColor != bgColor)
						{
							closestColor = closestColor + refColor*obj->getReflecitonCoef();
						}
					}
				}
			}
		}
	}

    if (closestColor.getX() > 255)
        closestColor.setX(255);

    if (closestColor.getY() > 255)
        closestColor.setY(255);

    if (closestColor.getZ() > 255)
        closestColor.setZ(255);

	return closestColor;
}

Point RayTrace::calcLight(Point &start, Point &objColor, Point &n, Point &view, const Object &curObj)
{
	auto sceneLights = _scene->getLights();

	Point res(0, 0, 0);
	double intens = 0.0;

	for (auto lt : sceneLights)
	{
		Point dir = lt->getPos() - start;
		double lenBetween = dir.len();
		dir.norm();

		Point tmp = (start-view);
		tmp.norm();

		Point reflRay1 = n*n.scalarMult(dir);
		reflRay1 = reflRay1 * (-2.0);
		reflRay1 = reflRay1 + dir;
		reflRay1.norm();

		if (!isIntersecting(start, dir))
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

bool RayTrace::isIntersecting(Point &start, Point &direction)
{
	auto sceneObjs = _scene->getObjects();

	for (auto obj : sceneObjs)
	{
		auto curObjMesh = obj->getMesh();
		auto curObjFaces = curObjMesh->getFaces();

		for (auto face : curObjFaces)
		{
			auto verts = face.getFaceVertices();

			Point v1 = verts[1] - verts[0];
			Point v2 = verts[2] - verts[0];

			Point n = v1.vecMult(v2);
			n.norm();

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












































