#include "Cell.h"


Cell::Cell()
{

}


Cell::~Cell()
{
}

void Cell::add(Ladybug * ladybug){
	ladybugs.push_back(ladybug);
	numL++;
}

void Cell::add(Aphid * aphid){
	aphids.push_back(aphid);
	numA++;
}