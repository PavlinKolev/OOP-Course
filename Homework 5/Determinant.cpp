#include "Determinant.h"
using std::cout;

double Determinant::calculateDeterminant(double** matrix, size_t size)
{
	if (size == 1)
	{
		return **matrix;
	}

	//Finds the value of the determinant
	//as moving through the elements from first row of matrix
	//and every element is multiplied with it's adjoint
	//and this value is added to "determinant Value".
	double determinantValue = 0.0;
	for (size_t col = 0; col < size; col++)
	{
		//Sets in "subMatrix" the value of subdeterminant of element matrix[0][col]
		double** subMatrix = allocateSquareBlock(size - 1);
		setSubDeterminant(subMatrix, matrix, size, col);

		//Finds the adjoint of element matrix[0][col]
		double adjoint = calculateDeterminant(subMatrix, size - 1);
		if (col % 2)//equivalent of: sum of the indexes of element to be odd number
			adjoint *= -1;

		double elem = (*matrix)[col];//equivalent of matrix[0][col]
		determinantValue += elem * adjoint;

		freeSquareBlock(subMatrix, size - 1);
	}

	return determinantValue;
}

void Determinant::setSubDeterminant(double** subMatrix, double** sourceMatrix, size_t sourceSize, size_t withoutColumn)
{
	size_t destMatrixCol;

	//Copies in "subMatrix" the elements from "sourceMatrix"
	//exept the elements from first row and Column "withoutColumn"
	//that's why first for-cycle starts from 1
	for (size_t i = 1; i < sourceSize; i++)
	{
		destMatrixCol = 0;
		for (size_t j = 0; j < sourceSize; j++)
		{
			if (j != withoutColumn)
				subMatrix[i - 1][destMatrixCol++] = sourceMatrix[i][j];
		}
	}
}

double** Determinant::allocateSquareBlock(size_t size)
{
	double** ptr = new double*[size];
	for (size_t i = 0; i < size; i++)
	{
		ptr[i] = new double[size];
	}

	return ptr;
}

void Determinant::freeSquareBlock(double** ptr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] ptr[i];
	}

	delete[] ptr;
}
