#pragma once
class Point
{
private:

	double x = 0.0;
	double y = 0.0;
	double elevation = 0.0;

public:

	Point() = default;
	Point(float x, float y, float elevation);

	double getX() const;
	double getY() const;
	double getElevation() const;
	
	void setX(float x);
	void setY(float y);
	void setElevation(float elevation);

};

