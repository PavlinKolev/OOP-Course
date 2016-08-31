#ifndef _DETERMINANT_H
#define _DETERMINANT_H
#include <iostream>

class Determinant
{
public:
	static double calculateDeterminant(double** matrix, size_t size);

private:
	static void setSubDeterminant(double** dest, double** source, size_t sourceSize, size_t withoutColummn);

	static double** allocateSquareBlock(size_t size);
	static void freeSquareBlock(double** ptr, size_t size);

private:
	Determinant(const Determinant&) = delete;
	Determinant& operator=(const Determinant&) = delete;
	~Determinant() = delete;
};

#endif
