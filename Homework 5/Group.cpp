#include "Group.h"
using std::cout;

Group::Group(const Point3D& vectorDir, double scalar) :vectorDirection(vectorDir), scalar(scalar){}

bool Group::isPointInside(const Point3D& point) const
{
	for (size_t i = 0; i < figures.getSize(); i++)
	{
		if (figures[i]->isPointInside(point))
		{
			return true;
		}
	}

	return false;
}

void Group::printAbsoluteCoordinates() const
{
	cout << "Group:\n";

	for(size_t i = 0; i < figures.getSize(); i++)
	{
		cout << "	";
		figures[i]->printTranslateWithVectorAndScalar(vectorDirection, scalar);
		cout << '\n';
	}
}

Figure* Group::clone()const
{
	return new Group(*this);
}

void Group::addFigure(Figure* figure)
{
	figures.addFigure(figure);
}
