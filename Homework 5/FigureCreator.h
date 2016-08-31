#ifndef _FIGURE_CREATOR_H
#define _FIGURE_CREATOR_H
#include "Figure.h"
#include "Sphere.h"
#include "Pyramid.h"
#include "Cuboid.h"
#include "Group.h"
using std::ifstream;

class FigureCreator
{
public:
	static Figure* createFigure(ifstream& file);
private:
	static Figure* createGroup(ifstream& file);
};

#endif
