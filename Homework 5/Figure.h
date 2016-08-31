#ifndef _FIGURE_H
#define _FIGURE_H
#include "Point3D.h"

class Figure
{
	friend class Group;
public:
	virtual ~Figure(){}

	virtual bool isPointInside(const Point3D& point) const = 0;
	virtual void printAbsoluteCoordinates() const = 0;
	virtual Figure* clone()const = 0;

protected:
	virtual void printTranslateWithVectorAndScalar(const Point3D vectorDir, double scalar)const{}

};

#endif
