#include "Cell.h"


Cell::Cell()
{

}


Cell::~Cell()
{
}

void Cell::add(Ladybug * ladybug){}

void Cell::add(Aphid * aphid){
	aphids.insert(aphid);
}