#include "FigureCreator.h"
using std::cout;
using std::endl;

void readFigures(FiguresContainer& figures, ifstream& file)
{
	Figure* figure = FigureCreator::createFigure(file);
	while (figure)
	{
		figures.addFigure(figure);
		figure = FigureCreator::createFigure(file);
	}
}

void testIsPointInside(const FiguresContainer& figures)
{
	Point3D point(0, 0, 0);
	for (size_t i = 0; i < figures.getSize(); i++)
	{
		if (figures[i]->isPointInside(point))
		{
			cout << "Point " << point << " is inside figure " << i << ".\n";
		}
	}
}

void testPrintAbsoluteCoordinates(const FiguresContainer& figures)
{
	for (size_t i = 0; i < figures.getSize(); i++)
	{
		figures[i]->printAbsoluteCoordinates();
		cout << endl;
	}
}

int main()
{
	FiguresContainer figures;
	ifstream file("figures.txt", std::ios::in);
	if (!file)
	{
		return 0;
	}

	readFigures(figures, file);

	cout << "Test \"Is point inside\" \n";
	testIsPointInside(figures);

	cout <<"\nTest \"Test Print Absolute Coordinates\" \n";

	testPrintAbsoluteCoordinates(figures);

	return 0;
}
