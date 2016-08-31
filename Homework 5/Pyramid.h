#ifndef _PYRAMID_H
#define _PYRAMID_H
#include "Figure.h"
#include "Determinant.h"

class Pyramid :public Figure
{
public:
	Pyramid(const Point3D& A, const Point3D& B, const Point3D& C, const Point3D& D);

public:
	virtual bool isPointInside(const Point3D& point) const;
	virtual void printAbsoluteCoordinates() const;
	virtual Figure* clone()const;

private:
	virtual void printTranslateWithVectorAndScalar(const Point3D vectorDir, double scalar)const;

	double** createCoordinatesDeterminant()const;
	void freeAllocatedBlocks(double** D0, double** D1, double** D2, double** D3, double** D4, size_t size)const;

	//Makes the elements of determinant "det" in row "rowPos" the same as coordinates from "point"
	void setRowForPoint(double** det, const Point3D& point, size_t rowPos)const;

private:
	Point3D A;
	Point3D B;
	Point3D C;
	Point3D D;
};

#endif
