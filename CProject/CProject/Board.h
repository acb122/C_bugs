#ifndef BOARD_H
#define BOARD_H
#include "Cell.h"
#include <iostream>
#include <fstream>

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
	void print();


private:
	Cell ** cells;
	const int w;
	const int h;


};

#endif 