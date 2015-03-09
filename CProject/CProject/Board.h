#ifndef BOARD_H
#define BOARD_H
#include "Cell.h"
class Aphid;
class Cell;

class Board
{
public:
	Board();
	Board(int,int);
	~Board();
	void  add(Aphid*);
	void  add(Ladybug*);



private:
	Cell ** cells;
	const int w;
	const int h;


};

#endif 