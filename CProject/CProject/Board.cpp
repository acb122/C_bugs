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

void Board::add(Aphid * aphid,int x,int y){
	cells[x][y].add(aphid);

}

void Board::add(Ladybug * ladybug, int x, int y){
	cells[x][y].add(ladybug);

}

void Board::print(){
	for (int x = 0; x < w; x++){
		for (int y = 0; y < h; y++){
			cout << cells[x][y].numA << cells[x][y].numL;

		}
		cout << endl;
	}
}

void Board::move(){
	for (int x = 0; x < w; x++){
		for (int y = 0; y < h; y++){
			for (int z = 0; z < cells[x][y].numA; z++){
				Aphid * moveA = cells[x][y].aphids.front();
				cells[x][y].aphids.pop_front();
				
				float move = (rand() % 10000) / 10000.0;
				
				if (move < moveA->movement_Prob&&moveA->hasMoved==false)
				{
					moveA->hasMoved = true;
					int position =rand() % 8;

					switch (position)
					{

					case(0) : cells[x][y - 1].add(moveA); break;

					case(1) : cells[x+1][y - 1].add(moveA); break;

					case(2) : cells[x+1][y].add(moveA); break;
					case(3) : cells[x+1][y + 1].add(moveA); break;
					case(4) : cells[x][y + 1].add(moveA); break;

					case(5) : cells[x-1][y + 1].add(moveA); break;
					case(6) : cells[x-1][y ].add(moveA); break;
					case(7) : cells[x-1][y - 1].add(moveA); break;
					
					
					}

				}
				else{
					moveA->hasMoved = true;
					cells[x][y].aphids.push_back(moveA);
				}
					

			
			}
			for (int z = 0; z < cells[x][y].numL; z++){
				Ladybug * moveA = cells[x][y].ladybugs.front();
				cells[x][y].ladybugs.pop_front();
				
				float move = (rand() % 10000) / 10000.0;

				if (move < moveA->movement_Prob&&moveA->hasMoved == false)
				{
					moveA->hasMoved = true;
					int position = rand() % 3;

					if (moveA->heading == 0){

						switch (position)
						{

						case(0) : cells[x][y - 1].add(moveA); break;

						case(1) : cells[x + 1][y - 1].add(moveA); break;

						case(2) : cells[x - 1][y - 1].add(moveA); break;


						}
					}
						if (moveA->heading == 1){

							switch (position)
							{

							case(0) : cells[x+1][y].add(moveA); break;

							case(1) : cells[x + 1][y - 1].add(moveA); break;

							case(2) : cells[x + 1][y + 1].add(moveA); break;


							}

						}
						if (moveA->heading == 2){

							switch (position)
							{

							case(0) : cells[x][y + 1].add(moveA); break;

							case(1) : cells[x + 1][y + 1].add(moveA); break;

							case(2) : cells[x - 1][y + 1].add(moveA); break;


							}
						}
						if (moveA->heading == 3){

							switch (position)
							{

							case(0) : cells[x - 1][y].add(moveA); break;

							case(1) : cells[x - 1][y + 1].add(moveA); break;

							case(2) : cells[x - 1][y - 1].add(moveA); break;


							}
						}
					}

				
				else{
					moveA->hasMoved = true;
					cells[x][y].ladybugs.push_back(moveA);
				}
			
			}
		}
	}

}

Board::~Board()
{
}
