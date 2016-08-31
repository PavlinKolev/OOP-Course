#include "FiguresContainer.h"

FiguresContainer::FiguresContainer() :figures(new Figure*[DEFAULT_CAPACITY]), size(0), capacity(DEFAULT_CAPACITY){}

FiguresContainer::FiguresContainer(const FiguresContainer& rhs) : figures(NULL), size(0), capacity(0)
{
	copyFrom(rhs);
}

FiguresContainer& FiguresContainer::operator=(const FiguresContainer& rhs)
{
	if (this != &rhs)
	{
		free();
		copyFrom(rhs);
	}
	return *this;
}

FiguresContainer::~FiguresContainer()
{
	free();
}

void FiguresContainer::addFigure(Figure* figure)
{
	figures[size++] = figure;
	if (size == capacity)
	{
		resize();
	}
}

const Figure* FiguresContainer::operator[](size_t pos)const
{
	if (pos >= size)
	{
		throw "Index out of range.";
	}

	return figures[pos];
}

void FiguresContainer::copyFrom(const FiguresContainer& rhs)
{
	capacity = rhs.capacity;
	size = rhs.size;

	figures = new Figure*[capacity];

	for (size_t i = 0; i < size; i++)
	{
		figures[i] = rhs.figures[i]->clone();
	}
}

void FiguresContainer::resize()
{
	capacity *= 2;
	Figure** newFigures = new Figure*[capacity];

	for (size_t i = 0; i < size; i++)
	{
		newFigures[i] = figures[i];
	}

	delete[] figures;

	figures = newFigures;
}

void FiguresContainer::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete figures[i];
	}

	delete[] figures;

	figures = NULL;
	size = 0;
	capacity = 0;
}
