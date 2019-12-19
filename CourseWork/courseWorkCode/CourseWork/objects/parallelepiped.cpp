#include "parallelepiped.h"

parallelepiped::parallelepiped(Point center, double width, double height, double depth)
{
	setCenter(center);

	setReflecitonCoef(0.8);
	setDispertionCoef(0.8);
	setGlossCoef(1000);

	Point color(255, 255, 255);
	setColor(color);

	std::vector<Point> vp;

	vp.push_back(Point(center.getX() + width/2, center.getY() - height/2, center.getZ() - depth/2));
	vp.push_back(Point(center.getX() + width/2, center.getY() - height/2, center.getZ() + depth/2));
	vp.push_back(Point(center.getX() + width/2, center.getY() + height/2, center.getZ() + depth/2));
	vp.push_back(Point(center.getX() + width/2, center.getY() + height/2, center.getZ() - depth/2));

	vp.push_back(Point(center.getX() - width/2, center.getY() - height/2, center.getZ() - depth/2));
	vp.push_back(Point(center.getX() - width/2, center.getY() - height/2, center.getZ() + depth/2));
	vp.push_back(Point(center.getX() - width/2, center.getY() + height/2, center.getZ() + depth/2));
	vp.push_back(Point(center.getX() - width/2, center.getY() + height/2, center.getZ() - depth/2));

	std::vector<Face> vf;

	vf.push_back(Face(vp[0], vp[1], vp[3]));
	vf.push_back(Face(vp[0], vp[3], vp[4]));
	vf.push_back(Face(vp[0], vp[1], vp[4]));

	vf.push_back(Face(vp[5], vp[4], vp[1]));
	vf.push_back(Face(vp[5], vp[4], vp[6]));
	vf.push_back(Face(vp[5], vp[1], vp[6]));

	vf.push_back(Face(vp[2], vp[1], vp[6]));
	vf.push_back(Face(vp[2], vp[3], vp[1]));
	vf.push_back(Face(vp[2], vp[6], vp[3]));

	vf.push_back(Face(vp[7], vp[6], vp[3]));
	vf.push_back(Face(vp[7], vp[3], vp[4]));
	vf.push_back(Face(vp[7], vp[6], vp[4]));

	Mesh *newMesh = new Mesh(vp, vf);

	std::shared_ptr<Mesh> pNewMesh(newMesh);//(new Mesh(vp, vf));
	setMesh(pNewMesh);

	auto t = getMesh();

	setRadius((center - vp[0]).len());
}

double parallelepiped::getRadius() { return _radius; }
void parallelepiped::setRadius(double value) { _radius = value; }

Point parallelepiped::getColor() const { return _color; }
void parallelepiped::setColor(Point value) { _color = value; }

std::shared_ptr<Mesh> parallelepiped::getMesh() const { return _mesh; };
void parallelepiped::setMesh(std::shared_ptr<Mesh> value) { _mesh = value; };

double parallelepiped::getReflecitonCoef() const { return _reflectionCoef; }
void parallelepiped::setReflecitonCoef(double value) { _reflectionCoef = value; }

double parallelepiped::getDispertionCoef() const { return _dispertionCoef; }
void parallelepiped::setDispertionCoef(double value) {_dispertionCoef = value; }

double parallelepiped::getGlossCoef() const { return _glossCoef; }
void parallelepiped::setGlossCoef(double value) { _glossCoef = value; }

Point parallelepiped::getCenter() const { return _center; }
void parallelepiped::setCenter(Point value) { _center = value; }

void parallelepiped::setName(std::string name) { _name = name; };
std::string parallelepiped::getName() const { return _name; };

void Object::rotate(double xAgnle, double yAngle, double zAngle) {};

void parallelepiped::rotate(double xAngle, double yAngle, double zAngle)
{
	const double PI = 3.141592653589793238463;

	double sinX = sin(xAngle * PI / 180);
	double cosX = cos(xAngle * PI / 180);

	double sinY = sin(yAngle * PI / 180);
	double cosY = cos(yAngle * PI / 180);

	double sinZ = sin(zAngle * PI / 180);
	double cosZ = cos(zAngle * PI / 180);

	auto pts = _mesh->getVertices();

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

		_mesh->setVertice(i, tmp);
	}

	auto vp = _mesh->getVertices();

	Face a(vp[0], vp[1], vp[3]);
	_mesh->setFace(0, a);
	a = Face(vp[0], vp[3], vp[4]);
	_mesh->setFace(1, a);
	a = Face(vp[0], vp[1], vp[4]);
	_mesh->setFace(2, a);

	a = Face(vp[5], vp[4], vp[1]);
	_mesh->setFace(3, a);
	a = Face(vp[5], vp[4], vp[6]);
	_mesh->setFace(4, a);
	a = Face(vp[5], vp[1], vp[6]);
	_mesh->setFace(5, a);

	a = Face(vp[2], vp[1], vp[6]);
	_mesh->setFace(6, a);
	a = Face(vp[2], vp[3], vp[1]);
	_mesh->setFace(7, a);
	a = Face(vp[2], vp[6], vp[3]);
	_mesh->setFace(8, a);

	a = Face(vp[7], vp[6], vp[3]);
	_mesh->setFace(9, a);
	a = Face(vp[7], vp[3], vp[4]);
	_mesh->setFace(10, a);
	a = Face(vp[7], vp[6], vp[4]);
	_mesh->setFace(11, a);
}























