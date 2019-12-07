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

    double getRadius();
    void setRadius(double value);

    Point getCenter() override;
    void setCenter(Point value) override;

    Point getColor() override;
    void setColor(Point value) override;

    Mesh getMesh() override;
    void setMesh(Mesh) override;

    double getReflecitonCoef() override;
    void setReflecitonCoef(double value) override;

    double getDispertionCoef() override;
    void setDispertionCoef(double value) override;

    double getGlossCoef() override;
    void setGlossCoef(double value) override;
private:
    double _radius;
};

#endif // SPHERE_H
