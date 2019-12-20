#include "prism.h"

prism::prism(Point center, double width, double height, double depth)
{
	setCenter(center);

	std::vector<Point> vp;

	vp.push_back(Point(center.getX() - width/2, center.getY() - height/2, center.getZ() - depth/2));
	vp.push_back(Point(center.getX() + width/2, center.getY() - height/2, center.getZ() - depth/2));
	vp.push_back(Point(center.getX(), center.getY() + height/2, center.getZ() - depth/2));

	vp.push_back(Point(center.getX() - width/2, center.getY() - height/2, center.getZ() + depth/2));
	vp.push_back(Point(center.getX() + width/2, center.getY() - height/2, center.getZ() + depth/2));
	vp.push_back(Point(center.getX(), center.getY() + height/2, center.getZ() + depth/2));

	std::vector<Face> vf;

	vf.push_back(Face(vp[0], vp[1], vp[2]));

	vf.push_back(Face(vp[0], vp[2], vp[5]));
	vf.push_back(Face(vp[0], vp[3], vp[5]));

	vf.push_back(Face(vp[1], vp[2], vp[5]));
	vf.push_back(Face(vp[1], vp[4], vp[5]));

	vf.push_back(Face(vp[1], vp[4], vp[0]));
	vf.push_back(Face(vp[0], vp[3], vp[4]));

	vf.push_back(Face(vp[3], vp[4], vp[5]));

	for (size_t i = 0; i < vf.size(); i++)
	{
		Point n = vf[i].getNormal();
		auto verts = vf[i].getFaceVertices();

		Point vecToCenter = getCenter() - verts[0];
		vecToCenter.norm();

		if ( n.scalarMult(vecToCenter) >= 0 )
		{
			vf[i].changeNormalDir();
		}
	}

	Mesh *newMesh = new Mesh(vp, vf);

	std::shared_ptr<Mesh> pNewMesh(newMesh);//(new Mesh(vp, vf));
	setMesh(pNewMesh);

	setRadius((center - vp[0]).len());
}

double prism::getRadius() { return _radius; }
void prism::setRadius(double value) { _radius = value; }

Point prism::getColor() const { return _color; }
void prism::setColor(Point value) { _color = value; }

std::shared_ptr<Mesh> prism::getMesh() const { return _mesh; };
void prism::setMesh(std::shared_ptr<Mesh> value) { _mesh = value; };

double prism::getReflecitonCoef() const { return _reflectionCoef; }
void prism::setReflecitonCoef(double value) { _reflectionCoef = value; }

double prism::getDispertionCoef() const { return _dispertionCoef; }
void prism::setDispertionCoef(double value) {_dispertionCoef = value; }

double prism::getGlossCoef() const { return _glossCoef; }
void prism::setGlossCoef(double value) { _glossCoef = value; }

Point prism::getCenter() const { return _center; }
void prism::setCenter(Point value) { _center = value; }

void prism::setName(std::string name) { _name = name; };
std::string prism::getName() const { return _name; };

void prism::rotate(double xAngle, double yAngle, double zAngle)
{
	const double PI = 3.141592653589793238463;

	double sinX = sin(xAngle * PI / 180);
	double cosX = cos(xAngle * PI / 180);

	double sinY = sin(yAngle * PI / 180);
	double cosY = cos(yAngle * PI / 180);

	double sinZ = sin(zAngle * PI / 180);
	double cosZ = cos(zAngle * PI / 180);

	auto pts = _mesh->getVertices();
	std::vector<Point> vp;

	for(size_t i = 0; i < pts.size(); i++)
	{
		Point tmp = pts[i];
		double tmpX, tmpY, tmpZ;
		tmp = tmp - getCenter();

		if (xAngle != 0.0)
		{
			tmpX = tmp.getX();
			tmpY = tmp.getY()*cosX - tmp.getZ()*sinX;
			tmpZ = tmp.getY()*sinX + tmp.getZ()*cosX;
			tmp.setX( tmpX );
			tmp.setY( tmpY );
			tmp.setZ( tmpZ );
		}

		if (yAngle != 0.0)
		{
			tmpX = tmp.getX()*cosY + tmp.getZ()*sinY;
			tmpY = tmp.getY();
			tmpZ = -tmp.getX()*sinY + tmp.getZ()*cosY;
			tmp.setX( tmpX );
			tmp.setY( tmpY );
			tmp.setZ( tmpZ );
		}

		if (zAngle != 0.0)
		{
			tmpX = tmp.getX()*cosZ - tmp.getY()*sinZ;
			tmpY = tmp.getX()*sinZ + tmp.getY()*cosZ;
			tmpZ = tmp.getZ();
			tmp.setX( tmpX );
			tmp.setY( tmpY );
			tmp.setZ( tmpZ );
		}

		tmp = tmp + getCenter();

		vp.push_back(tmp);
	}

	std::vector<Face> vf;

	vf.push_back(Face(vp[0], vp[1], vp[2]));

	vf.push_back(Face(vp[0], vp[2], vp[5]));
	vf.push_back(Face(vp[0], vp[3], vp[5]));

	vf.push_back(Face(vp[1], vp[2], vp[5]));
	vf.push_back(Face(vp[1], vp[4], vp[5]));

	vf.push_back(Face(vp[1], vp[4], vp[0]));
	vf.push_back(Face(vp[0], vp[3], vp[4]));

	vf.push_back(Face(vp[3], vp[4], vp[5]));

	for (size_t i = 0; i < vf.size(); i++)
	{
		Point n = vf[i].getNormal();
		auto verts = vf[i].getFaceVertices();

		Point vecToCenter = getCenter() - verts[0];
		vecToCenter.norm();

		if ( n.scalarMult(vecToCenter) >= 0 )
		{
			vf[i].changeNormalDir();
		}
	}

	Mesh *newMesh = new Mesh(vp, vf);

	std::shared_ptr<Mesh> pNewMesh(newMesh);//(new Mesh(vp, vf));
	setMesh(pNewMesh);
}
