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
	void print();
	void add(Aphid * );
	void add(Ladybug *);
	void breed();
	void attack();
	std::list<Ladybug*>  ladybugs;
	std::list<Aphid*>  aphids;


private:
	



	



};
#endif

