#include "sphere.h"

Sphere::Sphere(Point center, double radius)
{
    setCenter(center);
    setRadius(radius);

	setReflecitonCoef(0.8);
	setDispertionCoef(0.8);
	setGlossCoef(1000);

	Point color(255, 255, 255);
	setColor(color);

	double phi = (1 + sqrt(5))/2;//1.618033988749895;
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

	for (size_t i = 0; i < vecFs.size(); i++)
	{
		Point n = vecFs[i].getNormal();
		auto verts = vecFs[i].getFaceVertices();

		Point vecToCenter = getCenter() - verts[0];
		vecToCenter.norm();

		if ( n.scalarMult(vecToCenter) >= 0 )
		{
			vecFs[i].changeNormalDir();
		}
	}

	std::shared_ptr<Mesh> pNewMesh(new Mesh(vecPt, vecFs));
	setMesh(pNewMesh);
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

void Sphere::setName(std::string name) { _name = name; };
std::string Sphere::getName() const { return _name; };


void Sphere::rotate(double xAngle, double yAngle, double zAngle)
{
	const double PI = 3.141592653589793238463;

	double sinX = sin(xAngle * PI / 180);
	double cosX = cos(xAngle * PI / 180);

	double sinY = sin(yAngle * PI / 180);
	double cosY = cos(yAngle * PI / 180);

	double sinZ = sin(zAngle * PI / 180);
	double cosZ = cos(zAngle * PI / 180);

	auto pts = _mesh->getVertices();
	std::vector<Point> vecPt;

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

		vecPt.push_back(tmp);
	}

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

	for (size_t i = 0; i < vecFs.size(); i++)
	{
		Point n = vecFs[i].getNormal();
		auto verts = vecFs[i].getFaceVertices();

		Point vecToCenter = getCenter() - verts[0];
		vecToCenter.norm();

		if ( n.scalarMult(vecToCenter) >= 0 )
		{
			vecFs[i].changeNormalDir();
		}
	}

	std::shared_ptr<Mesh> pNewMesh(new Mesh(vecPt, vecFs));
	setMesh(pNewMesh);
}


