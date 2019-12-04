#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"
#include "../math/mesh.h"
#include "../math/point.h"
#include "../math/face.h"

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

    std::shared_ptr<Mesh> getMesh() override;
    void setMesh(std::shared_ptr<Mesh>) override;

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
