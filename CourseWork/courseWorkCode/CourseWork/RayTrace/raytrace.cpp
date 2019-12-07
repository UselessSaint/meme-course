#include "raytrace.h"

RayTrace::RayTrace(){}

RayTrace::RayTrace(Scene *scene): _scene(scene) {}
/*
void setScene(Scene *scene)
{
}
*/
Point RayTrace::traceRay(Point &start, Point &direction, int depth)
{
	auto sceneObjs = _scene->getObjects();

	double closestT = 0;
    Point closestColor(255,255,255);

	for (auto obj : sceneObjs)
	{
        auto curObjMesh = obj->getMesh();
        auto curObjFaces = curObjMesh.getFaces();

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
				if (closestT == 0.0)
				{
					closestT = t;
                    closestColor = obj->getColor();
				}
				if (closestT > t)
				{
					closestT = t;
                    closestColor = obj->getColor();
				}
			}
		}
	}

	return closestColor;
}
