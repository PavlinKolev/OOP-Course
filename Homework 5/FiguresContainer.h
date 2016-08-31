#ifndef _FIGURES_CONTAINER_H
#define _FIGURES_CONTAINER_H
#include "Figure.h"

class FiguresContainer
{
public:
	FiguresContainer();
	FiguresContainer(const FiguresContainer& rhs);
	FiguresContainer& operator=(const FiguresContainer& rhs);
	~FiguresContainer();

public:
	void addFigure(Figure* figure);
	size_t getSize()const{ return size; }
	const Figure* operator[](size_t pos)const;

private:
	void copyFrom(const FiguresContainer& rhs);
	void resize();
	void free();

private:
	static const size_t DEFAULT_CAPACITY = 8;

private:
	Figure** figures;
	size_t size;
	size_t capacity;
};

#endif
