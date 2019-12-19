#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"
#include "../math/mesh.h"
#include "../math/point.h"
#include "../math/face.h"
#include <memory>

class Sphere: public Object
{
public:
    Sphere() = default;
    Sphere(Point, double);

	double getRadius() override;
    void setRadius(double value);

	Point getCenter() const override;
    void setCenter(Point value) override;

	Point getColor() const override;
    void setColor(Point value) override;

	std::shared_ptr<Mesh> getMesh() const override;
	void setMesh(std::shared_ptr<Mesh>) override;

	double getReflecitonCoef() const override;
    void setReflecitonCoef(double value) override;

	double getDispertionCoef() const override;
    void setDispertionCoef(double value) override;

	double getGlossCoef() const override;
    void setGlossCoef(double value) override;

	void setName(std::string) override;
	std::string getName() const override;

	void rotate(double xAgnle, double yAngle, double zAngle) override;
};

#endif // SPHERE_H
