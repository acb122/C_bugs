#include "Ladybug.h"
#include <random>


Ladybug::Ladybug() : Insect()
{
	this->heading = rand() % 3;
}


Ladybug::~Ladybug()
{
}

int Ladybug::getHeading()
{
	return heading;
}

void Ladybug::setHeading(int x)
{
	this->heading = x;
}