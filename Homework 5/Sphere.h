#ifndef _SPHERE_H
#define _SPHERE_H
#include "Figure.h"

class Sphere :public Figure
{
public:
	Sphere(const Point3D& center, double radius);

public:
	virtual bool isPointInside(const Point3D& point) const;
	virtual void printAbsoluteCoordinates() const;
	virtual Figure* clone()const;

	void setRadius(double radius);
private:
	virtual void printTranslateWithVectorAndScalar(const Point3D vectorDir, double scalar)const;
private:
	Point3D center;
	double radius;
};

#endif
