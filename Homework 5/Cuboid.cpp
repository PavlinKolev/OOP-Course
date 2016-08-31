#include "Cuboid.h"
using std::cout;

Cuboid::Cuboid(const Point3D& A, const Point3D& B) :A(A), B(B){}

bool Cuboid::isPointInside(const Point3D& point) const
{
	double xBegin, xEnd;
	double yBegin, yEnd;
	double zBegin, zEnd;

	setIntervals(xBegin, xEnd, yBegin, yEnd, zBegin, zEnd);

	bool insideInterval_X = point.get_x() >= xBegin && point.get_x() <= xEnd;
	bool insideInterval_Y = point.get_y() >= yBegin && point.get_y() <= yEnd;
	bool insideInterval_Z = point.get_z() >= zBegin && point.get_z() <= zEnd;

	if (insideInterval_X && insideInterval_Y && insideInterval_Z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Cuboid::printAbsoluteCoordinates() const
{
	cout << "Cuboid: ";
	A.printAbsoluteCoordinates();
	cout << "	";
	B.printAbsoluteCoordinates();
}

void Cuboid::printTranslateWithVectorAndScalar(const Point3D vectorDir, double scalar)const
{
	Point3D translatedA = A.translateWithVector(vectorDir);
	Point3D translatedB = B.translateWithVector(vectorDir);

	translatedA.addScalar(scalar);
	translatedB.addScalar(scalar);

	cout << "Cuboid: " << translatedA << "	" << translatedB;
}

Figure* Cuboid::clone()const
{
	return new Cuboid(*this);
}

void Cuboid::setIntervals(double& xBegin, double& xEnd, double& yBegin, double& yEnd, double& zBegin, double& zEnd)const
{
	if (A.get_x() <= B.get_x())
	{
		xBegin = A.get_x();
		xEnd = B.get_x();
	}
	else
	{
		xBegin = B.get_x();
		xEnd = A.get_x();
	}


	if (A.get_y() <= B.get_y())
	{
		yBegin = A.get_y();
		yEnd = B.get_y();
	}
	else
	{
		yBegin = B.get_y();
		yEnd = A.get_y();
	}

	
	if (A.get_z() <= B.get_z())
	{
		zBegin = A.get_z();
		zEnd = B.get_z();
	}
	else
	{
		zBegin = B.get_z();
		zEnd = A.get_z();
	}
}

