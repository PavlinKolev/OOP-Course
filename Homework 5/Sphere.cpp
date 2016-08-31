#include "Sphere.h"
using std::cout;

Sphere::Sphere(const Point3D& center, double radius) :center(center), radius(0.0)
{
	setRadius(radius);
}

void Sphere::setRadius(double radius)
{
	if (radius <= 0.0)
		throw "Radius of Sphere must be positive number.";

	this->radius = radius;
}

bool Sphere::isPointInside(const Point3D& point) const
{
	double x_length = point.get_x() - center.get_x();
	x_length *= x_length;

	double y_length = point.get_y() - center.get_y();
	y_length *= y_length;

	double z_length = point.get_z() - center.get_z();
	z_length *= z_length;

	bool isInside = (x_length <= radius*radius) && (y_length <= radius*radius) && (z_length <= radius*radius);

	return isInside;
}

void Sphere::printAbsoluteCoordinates()const
{
	cout << "Sphere: ";

	center.printAbsoluteCoordinates();

	cout << "  " << radius;
}

void Sphere::printTranslateWithVectorAndScalar(const Point3D vectorDir, double scalar)const
{
	Point3D translatedCenter = center.translateWithVector(vectorDir);
	translatedCenter.addScalar(scalar);

	cout << "Sphere: " << translatedCenter << ' ' << radius;
}

Figure* Sphere::clone()const
{
	return new Sphere(*this);
}
