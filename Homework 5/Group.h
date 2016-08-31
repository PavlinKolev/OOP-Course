#ifndef _GROUP_H
#define _GROUP_H
#include "FiguresContainer.h"

class Group :public Figure
{
public:
	Group(const Point3D& vectorDir, double scalar);

public:
	virtual bool isPointInside(const Point3D& point) const;
	virtual void printAbsoluteCoordinates() const;
	virtual Figure* clone()const;

	void addFigure(Figure* figure);

private:
	FiguresContainer figures;
	Point3D vectorDirection;
	double scalar;
};

#endif
