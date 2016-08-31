#include "FigureCreator.h"

Figure* FigureCreator::createFigure(ifstream& file)
{
	char figureType[32];

	file >> figureType;

	if (strcmp(figureType, "sphere") == 0)
	{
		double centerX, centerY, centerZ, radius;
		file >> centerX >> centerY >> centerZ >> radius;

		Point3D center(centerX, centerY, centerZ);

		return new Sphere(center, radius);
	}
	else if (strcmp(figureType, "pyramid") == 0)
	{
		double aX, aY, aZ;
		double bX, bY, bZ;
		double cX, cY, cZ;
		double dX, dY, dZ;

		file >> aX >> aY >> aZ
			>> bX >> bY >> bZ
			>> cX >> cY >> cZ
			>> dX >> dY >> dZ;

		Point3D A(aX, aY, aZ);
		Point3D B(bX, bY, bZ);
		Point3D C(cX, cY, cZ);
		Point3D D(dX, dY, dZ);

		return new Pyramid(A, B, C, D);
		
	}
	else if (strcmp(figureType, "cuboid") == 0)
	{
		double aX, aY, aZ;
		double bX, bY, bZ;

		file >> aX >> aY >> aZ
			>> bX >> bY >> bZ;

		Point3D A(aX, aY, aZ);
		Point3D B(bX, bY, bZ);

		return new Cuboid(A, B);
	}
	else if (strcmp(figureType, "group") == 0)
	{
		return createGroup(file);
	}
	else
	{
		return NULL;
	}
}

Figure* FigureCreator::createGroup(ifstream& file)
{
	char inOrOut[4];
	file >> inOrOut;

	if (strcmp(inOrOut, "out") == 0)
	{
		return NULL;
	}
	else //inOrOut == "in"
	{
		double vectorX, vectorY, vectorZ, scalar;

		file >> vectorX >> vectorY >> vectorZ >> scalar;

		Point3D vectorDir(vectorX, vectorY, vectorZ);

		Group* newGroup = new Group(vectorDir, scalar);

		Figure* tempFigure = createFigure(file);
		while (tempFigure)
		{
			newGroup->addFigure(tempFigure);
			tempFigure = createFigure(file);
		}

		return newGroup;
	}
}
