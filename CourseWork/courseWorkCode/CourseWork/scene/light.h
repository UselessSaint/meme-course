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

	std::string getName();
	void setName(std::string);

private:
	Point _position;
	double _intens;

	std::string _name;
};

#endif // LIGHT_H
