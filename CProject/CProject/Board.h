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
	void  add(Aphid*,int,int);
	void  add(Ladybug*,int,int);
	void move();
	void print();
	void attack();
	void breed();
	bool empty();


private:
	Cell ** cells;
	const int w;
	const int h;


};

#endif 