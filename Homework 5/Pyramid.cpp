#include "Pyramid.h"
using std::cout;
using std::endl;

Pyramid::Pyramid(const Point3D& A, const Point3D& B, const Point3D& C, const Point3D& D)
:A(A), B(B), C(C), D(D){}

bool Pyramid::isPointInside(const Point3D& point) const
{
	/*Used algorithm:
	http://steve.hollasch.net/cgindex/geometry/ptintet.html
	*/

	//Setting the fifties determinants with coordinates
	double** D0 = createCoordinatesDeterminant();

	double** D1 = createCoordinatesDeterminant();
	setRowForPoint(D1, point, 0);

	double** D2 = createCoordinatesDeterminant();
	setRowForPoint(D2, point, 1);

	double** D3 = createCoordinatesDeterminant();
	setRowForPoint(D3, point, 2);

	double** D4 = createCoordinatesDeterminant();
	setRowForPoint(D4, point, 3);

	//Finding the signs of the values of the determinants
	size_t detSize = 4;
	bool signD0 = (Determinant::calculateDeterminant(D0, detSize) >= 0.0) ? true : false;
	bool signD1 = (Determinant::calculateDeterminant(D1, detSize) >= 0.0) ? true : false;
	bool signD2 = (Determinant::calculateDeterminant(D2, detSize) >= 0.0) ? true : false;
	bool signD3 = (Determinant::calculateDeterminant(D3, detSize) >= 0.0) ? true : false;
	bool signD4 = (Determinant::calculateDeterminant(D4, detSize) >= 0.0) ? true : false;

	freeAllocatedBlocks(D0, D1, D2, D3, D4, detSize);

	//If every determinants have same sign
	if ((signD0 == signD1) && (signD0 == signD2) && (signD0 == signD3) && (signD0 == signD4))
		return true;
	else
		return false;
}

void Pyramid::printAbsoluteCoordinates() const
{
	cout << "Pyramid: ";

	A.printAbsoluteCoordinates();
	cout << "	";
	B.printAbsoluteCoordinates();
	cout << "	";
	C.printAbsoluteCoordinates();
	cout << "	";
	D.printAbsoluteCoordinates();
}

void Pyramid::printTranslateWithVectorAndScalar(const Point3D vectorDir, double scalar)const
{
	Point3D translatedA = A.translateWithVector(vectorDir);
	Point3D translatedB = B.translateWithVector(vectorDir);
	Point3D translatedC = C.translateWithVector(vectorDir);
	Point3D translatedD = D.translateWithVector(vectorDir);

	translatedA.addScalar(scalar);
	translatedB.addScalar(scalar);
	translatedC.addScalar(scalar);
	translatedD.addScalar(scalar);

	cout << "Pyramid: " << translatedA << "	" << translatedB << "	" << translatedC << "	" << translatedD;
}

Figure* Pyramid::clone()const
{
	return new Pyramid(*this);
}

double** Pyramid::createCoordinatesDeterminant()const
{
	const size_t determinantSize = 4;
	double** matrix = new double*[determinantSize];
	for (size_t i = 0; i < determinantSize; i++)
	{
		matrix[i] = new double[determinantSize];
	}


	matrix[0][0] = A.get_x();
	matrix[0][1] = A.get_y();
	matrix[0][2] = A.get_z();
	matrix[0][3] = 1;

	matrix[1][0] = B.get_x();
	matrix[1][1] = B.get_y();
	matrix[1][2] = B.get_z();
	matrix[1][3] = 1;

	matrix[2][0] = C.get_x();
	matrix[2][1] = C.get_y();
	matrix[2][2] = C.get_z();
	matrix[2][3] = 1;

	matrix[3][0] = D.get_x();
	matrix[3][1] = D.get_y();
	matrix[3][2] = D.get_z();
	matrix[3][3] = 1;

	return matrix;
}

void Pyramid::setRowForPoint(double** det, const Point3D& point, size_t rowPos)const
{
	det[rowPos][0] = point.get_x();
	det[rowPos][1] = point.get_y();
	det[rowPos][2] = point.get_z();
}

void Pyramid::freeAllocatedBlocks(double** D0, double** D1, double** D2, double** D3, double** D4, size_t size)const
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] D0[i];
		delete[] D1[i];
		delete[] D2[i];
		delete[] D3[i];
		delete[] D4[i];
	}

	delete[] D0;
	delete[] D1;
	delete[] D2;
	delete[] D3;
	delete[] D4;
}
