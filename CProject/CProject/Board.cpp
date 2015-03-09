#include "Board.h"
using namespace std;

Board::Board() :w(0), h(0)
{
}

Board::Board(int width, int height) :w(width), h(height)
{
	
	cells = new Cell*[w];
	for (int i = 0; i < w; i++)
	{
		cells[i] = new Cell[h];

	}
}

void Board::add(Aphid * aphid){
	cells[aphid->x][aphid->y].add(aphid);

}

void Board::add(Ladybug * ladybug){
	cells[ladybug->x][ladybug->y].add(ladybug);

}

void Board::print(){
	for (int x = 0; x < w; x++){
		for (int y = 0; y < h; y++){
			cout << cells[x][y].numA << cells[x][y].numL;

		}
		cout << endl;
	}
}

Board::~Board()
{
}
