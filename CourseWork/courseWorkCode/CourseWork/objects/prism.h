#ifndef PRISM_H
#define PRISM_H

#include "object.h"
#include "../math/mesh.h"
#include "../math/point.h"
#include "../math/face.h"
#include <memory>

class prism : public Object
{
public:
	prism();
	prism(Point center, double width, double height, double depth);

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

#endif // PRISM_H
