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
			cout << cells[x][y].aphids.size() << cells[x][y].ladybugs.size();

		}
		cout << endl;
	}
}

void Board::move(){

	for (int x = 0; x < this->w; x++){

		for (int y = 0; y < this->h; y++){

			for (int z = 0; z < cells[x][y].aphids.size(); z++){

				Aphid * moveA = cells[x][y].aphids.front();
				cells[x][y].aphids.pop_front();
				cells[x][y].numA--;

				float move = (rand() % 10000) / 10000.0;

				if (move < moveA->movement_Prob&&moveA->hasMoved == false)
				{
					moveA->hasMoved = true;
					int position = rand() % 8;
					int yminus = y - 1;
					if (yminus < 0){
						yminus = 1;
					}
					int yplus = y + 1;
					if (yplus == w){
						yplus = w - 1;


					}
					int xminus = x - 1;
					if (xminus < 0){
						xminus = 1;
					}
					int xplus = x + 1;
					if (xplus == h){
						xplus = x - 1;
					}
					switch (position)
					{

					case(0) : cells[x][yminus].add(moveA); break;

					case(1) : cells[xplus][yminus].add(moveA); break;

					case(2) : cells[xplus][y].add(moveA); break;
					case(3) : cells[xplus][yplus].add(moveA); break;
					case(4) : cells[x][yplus].add(moveA); break;

					case(5) : cells[xminus][yplus].add(moveA); break;
					case(6) : cells[xminus][y].add(moveA); break;
					case(7) : cells[xminus][yminus].add(moveA); break;


					}


				}
				else{
					moveA->hasMoved = true;
					cells[x][y].aphids.push_back(moveA);
				}



			}
			for (int z = 0; z < cells[x][y].ladybugs.size(); z++){

				Ladybug * moveA = cells[x][y].ladybugs.front();
				cells[x][y].ladybugs.pop_front();
				cells[x][y].numL;
				float move = (rand() % 10000) / 10000.0;

				if (move < moveA->movement_Prob&&moveA->hasMoved == false)
				{
					moveA->hasMoved = true;
					int position = rand() % 3;

					int yminus = y - 1;
					if (yminus < 0){
						yminus = 1;
					}
					int yplus = y + 1;
					if (yplus == w){
						yplus = w - 1;


					}
					int xminus = x - 1;
					if (xminus < 0){
						xminus = 1;
					}
					int xplus = x + 1;
					if (xplus == h){
						xplus = x - 1;
					}

					if (moveA->heading == 0){

						switch (position)
						{

						case(0) : cells[x][yminus].add(moveA); break;

						case(1) : cells[xplus][yminus].add(moveA); break;

						case(2) : cells[xplus][yminus].add(moveA); break;


						}
					}
					if (moveA->heading == 1){

						switch (position)
						{

						case(0) : cells[xplus][y].add(moveA); break;

						case(1) : cells[xplus][yminus].add(moveA); break;

						case(2) : cells[xplus][yplus].add(moveA); break;


						}

					}
					if (moveA->heading == 2){

						switch (position)
						{

						case(0) : cells[x][yplus].add(moveA); break;

						case(1) : cells[xplus][yplus].add(moveA); break;

						case(2) : cells[xminus][yplus].add(moveA); break;


						}
					}
					if (moveA->heading == 3){

						switch (position)
						{

						case(0) : cells[xminus][y].add(moveA); break;

						case(1) : cells[xminus][yplus].add(moveA); break;

						case(2) : cells[xminus][yminus].add(moveA); break;


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


	for (int x = 0; x < this->w; x++){

		for (int y = 0; y < this->h; y++){

			for (int z = 0; z < cells[x][y].aphids.size(); z++){
				Aphid * moveA = cells[x][y].aphids.front();
				cells[x][y].aphids.pop_front();
				moveA->hasMoved = false;
				cells[x][y].aphids.push_back(moveA);

			}

			for (int z = 0; z < cells[x][y].ladybugs.size(); z++){

				Ladybug * moveA = cells[x][y].ladybugs.front();
				cells[x][y].ladybugs.pop_front();
				moveA->hasMoved = false;
				cells[x][y].ladybugs.push_back(moveA);
			}
		}
	}
}

Board::~Board()
{
}
