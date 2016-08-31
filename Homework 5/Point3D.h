#ifndef _POINT_3D_H
#define _POINT_3D_H
#include <iostream>
#include <fstream>
using std::ostream;


class Point3D
{
	friend ostream& operator<<(ostream& stream, const Point3D& point);
public:
	Point3D(double x = 0.0, double y = 0.0, double z = 0.0);

public:
	Point3D translateWithVector(const Point3D& vectorDirection)const;
	void addScalar(double scalar);
	void printAbsoluteCoordinates()const;

	double get_x()const{ return x; }
	double get_y()const{ return y; }
	double get_z()const{ return z; }

private:
	double x;
	double y;
	double z;
};

#endif
