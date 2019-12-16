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

	std::shared_ptr<Mesh> pNewMesh(new Mesh(vp, vf));
	setMesh(pNewMesh);

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
