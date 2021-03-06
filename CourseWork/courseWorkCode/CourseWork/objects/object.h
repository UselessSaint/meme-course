#ifndef OBJECT_H
#define OBJECT_H

#include "../math/point.h"
#include "../math/face.h"
#include "../math/mesh.h"
#include <vector>
#include <memory>
#include <iostream>

class Object
{
public:
    Object() = default;
	virtual ~Object() = default;

	virtual double getRadius() = 0;

	virtual Point getCenter() const = 0;
	virtual void setCenter(Point value) = 0;

	virtual Point getColor() const = 0;
    virtual void setColor(Point value) = 0;

	virtual std::shared_ptr<Mesh> getMesh() const = 0;
	virtual void setMesh(std::shared_ptr<Mesh>) = 0;

	virtual double getReflecitonCoef() const  = 0;
	virtual void setReflecitonCoef(double value) = 0;

	virtual double getDispertionCoef() const = 0;
	virtual void setDispertionCoef(double value) = 0;

	virtual double getGlossCoef() const = 0;
	virtual void setGlossCoef(double value) = 0;

	virtual void setName(std::string) = 0;
	virtual std::string getName() const = 0;

	virtual void rotate(double xAngle, double yAngle, double zAngle);
protected:
	Point _center;
    Point _color;
	std::shared_ptr<Mesh> _mesh;

	double _radius;
	double _reflectionCoef;
	double _dispertionCoef;
	double _glossCoef;
	std::string _name;
};

#endif // OBJECT_H
