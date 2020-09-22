#include "Point.h"

Point::Point(float x, float y, float elevation) :
	x(x),
	y(y),
	elevation(elevation)
{
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

double Point::getElevation() const
{
	return elevation;
}

void Point::setX(float x)
{
	this->x = x;
}

void Point::setY(float y)
{
	this->y = y;
}

void Point::setElevation(float elevation)
{
	this->elevation = elevation;
}
