#ifndef OBJECT_H
#define OBJECT_H

#include "../math/point.h"
#include "../math/face.h"
#include "../math/mesh.h"
#include <vector>
#include <memory>

class Object
{
public:
    Object() = default;
	virtual ~Object() = default;

	virtual Point getCenter() = 0;
	virtual void setCenter(Point value) = 0;

    virtual Point getColor() = 0;
    virtual void setColor(Point value) = 0;

    virtual std::shared_ptr<Mesh> getMesh() = 0;
    virtual void setMesh(std::shared_ptr<Mesh>) = 0;

	virtual double getReflecitonCoef() = 0;
	virtual void setReflecitonCoef(double value) = 0;

	virtual double getDispertionCoef() = 0;
	virtual void setDispertionCoef(double value) = 0;

	virtual double getGlossCoef() = 0;
	virtual void setGlossCoef(double value) = 0;
protected:
	Point _center;
    Point _color;
    std::shared_ptr<Mesh> _mesh;

	double _reflectionCoef;
	double _dispertionCoef;
	double _glossCoef;
};

#endif // OBJECT_H