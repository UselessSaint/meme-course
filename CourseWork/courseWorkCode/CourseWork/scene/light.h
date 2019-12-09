#ifndef LIGHT_H
#define LIGHT_H

#include "../math/point.h"
#include "../math/face.h"
#include "../math/mesh.h"
#include <vector>
#include <memory>

class Light
{
public:
    Light();
    Light(Point, double);

	Point getPos();
	double getIntens();

private:
	Point _position;
	double _intens;
};

#endif // LIGHT_H
