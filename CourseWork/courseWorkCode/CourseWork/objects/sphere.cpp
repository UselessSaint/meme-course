#include "sphere.h"

Sphere::Sphere(Point center, double radius)
{
    setCenter(center);
    setRadius(radius);

    setReflecitonCoef(0.5);
    setDispertionCoef(0.5);
    setGlossCoef(1);

	Point color(255, 0, 0);
	setColor(color);
/*
    double phi = 1.618033988749895;

    std::vector<Point> vecPt;

    vecPt.push_back(Point(-radius, phi*radius, 0));
    vecPt.push_back(Point(radius, phi*radius, 0));
    vecPt.push_back(Point(-radius, -phi*radius, 0));
    vecPt.push_back(Point(radius, -phi*radius, 0));

    vecPt.push_back(Point(0, -radius, phi*radius));
    vecPt.push_back(Point(0, radius, phi*radius));
    vecPt.push_back(Point(0, -radius, -phi*radius));
    vecPt.push_back(Point(0, radius, -phi*radius));

    vecPt.push_back(Point(phi*radius, 0, -radius));
    vecPt.push_back(Point(phi*radius, 0, radius));
    vecPt.push_back(Point(-phi*radius, 0, -radius));
    vecPt.push_back(Point(phi*radius, 0, radius));*/
}

double Sphere::getRadius() { return _radius; }
void Sphere::setRadius(double value) { _radius = value; }

Point Sphere::getColor() { return _color; }
void Sphere::setColor(Point value) { _color = value; }

std::shared_ptr<Mesh> Sphere::getMesh() { return _mesh; };
void Sphere::setMesh(std::shared_ptr<Mesh> value) { _mesh = value; };

double Sphere::getReflecitonCoef() { return _reflectionCoef; }
void Sphere::setReflecitonCoef(double value) { _reflectionCoef = value; }

double Sphere::getDispertionCoef() { return _dispertionCoef; }
void Sphere::setDispertionCoef(double value) {_dispertionCoef = value; }

double Sphere::getGlossCoef() { return _glossCoef; }
void Sphere::setGlossCoef(double value) { _glossCoef = value; }

Point Sphere::getCenter() { return _center; }
void Sphere::setCenter(Point value) { _center = value; }



