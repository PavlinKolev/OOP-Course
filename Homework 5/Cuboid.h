#ifndef _CUBOID_H
#define _CUBOID_H
#include "Figure.h"

class Cuboid :public Figure
{
public:
	Cuboid(const Point3D& A, const Point3D& B);

public:
	virtual bool isPointInside(const Point3D& point) const;
	virtual void printAbsoluteCoordinates() const;
	virtual Figure* clone()const;

private:
	virtual void printTranslateWithVectorAndScalar(const Point3D vectorDir, double scalar)const;

	void setIntervals(double& xBegin, double& xEnd, double& yBegin, double& yEnd, double& zBegin, double& zEnd)const;

private:
	Point3D A;
	Point3D B;
};

#endif
