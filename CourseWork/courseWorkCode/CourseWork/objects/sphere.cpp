#include "sphere.h"

Sphere::Sphere(Point center, double radius)
{
    setCenter(center);
    setRadius(radius);

	setReflecitonCoef(0.8);
	setDispertionCoef(0.8);
    setGlossCoef(1);

    Point color(0, 255, 255);
	setColor(color);

    double phi = 1.618033988749895;
	double icoRadius = radius/sqrt(1+phi*phi);

    std::vector<Point> vecPt;

	vecPt.push_back(Point(-icoRadius + center.getX(), phi*icoRadius + center.getY(), 0 + center.getZ()));
	vecPt.push_back(Point(icoRadius + center.getX(), phi*icoRadius + center.getY(), 0 + center.getZ()));
	vecPt.push_back(Point(-icoRadius + center.getX(), -phi*icoRadius + center.getY(), 0 + center.getZ()));
	vecPt.push_back(Point(icoRadius + center.getX(), -phi*icoRadius + center.getY(), 0 + center.getZ()));

	vecPt.push_back(Point(0 + center.getX(), -icoRadius + center.getY(), phi*icoRadius + center.getZ()));
	vecPt.push_back(Point(0 + center.getX(), icoRadius + center.getY(), phi*icoRadius + center.getZ()));
	vecPt.push_back(Point(0 + center.getX(), -icoRadius + center.getY(), -phi*icoRadius + center.getZ()));
	vecPt.push_back(Point(0 + center.getX(), icoRadius + center.getY(), -phi*icoRadius + center.getZ()));

	vecPt.push_back(Point(phi*icoRadius + center.getX(), 0 + center.getY(), -icoRadius + center.getZ()));
	vecPt.push_back(Point(phi*icoRadius + center.getX(), 0 + center.getY(), icoRadius + center.getZ()));
	vecPt.push_back(Point(-phi*icoRadius + center.getX(), 0 + center.getY(), -icoRadius + center.getZ()));
	vecPt.push_back(Point(-phi*icoRadius + center.getX(), 0 + center.getY(), icoRadius + center.getZ()));

	//setRadius(getRadius()*phi);

	std::vector<Face> vecFs;

	vecFs.push_back(Face(vecPt[0], vecPt[11], vecPt[5]));
	vecFs.push_back(Face(vecPt[0], vecPt[5], vecPt[1]));
	vecFs.push_back(Face(vecPt[0], vecPt[1], vecPt[7]));
	vecFs.push_back(Face(vecPt[0], vecPt[7], vecPt[10]));
	vecFs.push_back(Face(vecPt[0], vecPt[10], vecPt[11]));

	vecFs.push_back(Face(vecPt[1], vecPt[5], vecPt[9]));
	vecFs.push_back(Face(vecPt[5], vecPt[11], vecPt[4]));
	vecFs.push_back(Face(vecPt[11], vecPt[10], vecPt[2]));
	vecFs.push_back(Face(vecPt[10], vecPt[7], vecPt[6]));
	vecFs.push_back(Face(vecPt[7], vecPt[1], vecPt[8]));

	vecFs.push_back(Face(vecPt[3], vecPt[9], vecPt[4]));
	vecFs.push_back(Face(vecPt[3], vecPt[4], vecPt[2]));
	vecFs.push_back(Face(vecPt[3], vecPt[2], vecPt[6]));
	vecFs.push_back(Face(vecPt[3], vecPt[6], vecPt[8]));
	vecFs.push_back(Face(vecPt[3], vecPt[8], vecPt[9]));

	vecFs.push_back(Face(vecPt[4], vecPt[9], vecPt[5]));
	vecFs.push_back(Face(vecPt[2], vecPt[4], vecPt[11]));
	vecFs.push_back(Face(vecPt[6], vecPt[2], vecPt[10]));
	vecFs.push_back(Face(vecPt[8], vecPt[6], vecPt[7]));
	vecFs.push_back(Face(vecPt[9], vecPt[8], vecPt[1]));

	std::shared_ptr<Mesh> pNewMesh(new Mesh(vecPt, vecFs));
	setMesh(pNewMesh);
/*
	std::vector<Point> vecPt;

	vecPt.push_back(Point(center.getX(), center.getY()+icoRadius/4, center.getZ()-icoRadius/2));
	vecPt.push_back(Point(center.getX()+icoRadius, center.getY()+icoRadius/4, center.getZ()));
	vecPt.push_back(Point(center.getX()+icoRadius, center.getY()+icoRadius, center.getZ()));
	vecPt.push_back(Point(center.getX()-icoRadius, center.getY()-icoRadius/4, center.getZ()+icoRadius));

	std::vector<Face> vf;

	vf.push_back(Face(vecPt[0], vecPt[1], vecPt[2]));
	vf.push_back(Face(vecPt[3], vecPt[1], vecPt[2]));
	vf.push_back(Face(vecPt[0], vecPt[3], vecPt[1]));
	vf.push_back(Face(vecPt[0], vecPt[3], vecPt[2]));


	std::shared_ptr<Mesh> pNewMesh(new Mesh(vecPt, vf));
	setMesh(pNewMesh);*/
}

double Sphere::getRadius() { return _radius; }
void Sphere::setRadius(double value) { _radius = value; }

Point Sphere::getColor() const { return _color; }
void Sphere::setColor(Point value) { _color = value; }

std::shared_ptr<Mesh> Sphere::getMesh() const { return _mesh; };
void Sphere::setMesh(std::shared_ptr<Mesh> value) { _mesh = value; };

double Sphere::getReflecitonCoef() const { return _reflectionCoef; }
void Sphere::setReflecitonCoef(double value) { _reflectionCoef = value; }

double Sphere::getDispertionCoef() const { return _dispertionCoef; }
void Sphere::setDispertionCoef(double value) {_dispertionCoef = value; }

double Sphere::getGlossCoef() const { return _glossCoef; }
void Sphere::setGlossCoef(double value) { _glossCoef = value; }

Point Sphere::getCenter() const { return _center; }
void Sphere::setCenter(Point value) { _center = value; }



