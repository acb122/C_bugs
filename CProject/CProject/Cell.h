#ifndef Cell_H
#define Cell_H

#include <list>
#include "Ladybug.h"
#include "Insect.h"
#include "Aphid.h"
#include "Board.h"



class Board;


class Cell
{ 

public:
	Cell();
	~Cell();
	void Update(Board,Aphid);
	void Update(Board,Ladybug);
	void add(Aphid * );
	void add(Ladybug *);
	int numA = 0;
	int numL = 0;

private:
	int x;
	int y;

	std::list<Ladybug*>  ladybugs;
	std::list<Aphid*>  aphids;

	



};
#endif

