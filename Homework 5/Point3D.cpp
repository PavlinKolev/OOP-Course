#include "Point3D.h"

Point3D::Point3D(double x, double y, double z) :x(x), y(y), z(z){}

Point3D Point3D::translateWithVector(const Point3D& vectorDirection)const
{
	double x_ = x + vectorDirection.x;
	double y_ = y + vectorDirection.y;
	double z_ = z + vectorDirection.z;

	return Point3D(x_, y_, z_);
}

void Point3D::addScalar(double scalar)
{
	x += scalar;
	y += scalar;
	z += scalar;
}

void Point3D::printAbsoluteCoordinates()const
{
	double x = this->x, y = this->y, z = this->z;

	if (x < 0.0)
		x *= -1;

	if (y < 0.0)
		y *= -1;

	if (z < 0.0)
		z *= -1;

	std::cout << x << ' ' << y << ' ' << z;
}

ostream& operator<<(ostream& stream, const Point3D& point)
{
	stream << point.x << ' '
		<< point.y << ' '
		<< point.z;

	return stream;
}
