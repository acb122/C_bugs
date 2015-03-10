#include "Ladybug.h"
#include <random>


Ladybug::Ladybug() : Insect()
{
	this->heading = rand() % 3;
}


Ladybug::~Ladybug()
{
}
