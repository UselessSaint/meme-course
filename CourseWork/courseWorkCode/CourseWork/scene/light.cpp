#include "light.h"

Light::Light()
{
	_position.setX(0);
	_position.setY(0);
	_position.setZ(0);

	_intens = 1;
}

Light::Light(Point p, double i): _intens(i)
{
	_position.setX(p.getX());
	_position.setY(p.getY());
	_position.setZ(p.getZ());
}

Point Light::getPos() { return _position; }
double Light::getIntens() { return _intens; }
