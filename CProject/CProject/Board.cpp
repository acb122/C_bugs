#include "Board.h"
#include <string>
#include <iostream>

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
			cells[x][y].print();
		}
		cout << endl;
	}
}

void Board::breed(){
	for (int x = 0; x < this->w; x++){

		for (int y = 0; y < this->h; y++){

			cells[x][y].breed();
		}
	}
}

void Board::attack(){
	for (int x = 0; x < this->w; x++){

		for (int y = 0; y < this->h; y++){
			cells[x][y].attack();
			
		}
	}
}



void Board::move(){

	for (int x = 0; x < this->w; x++){

		for (int y = 0; y < this->h; y++){
			int numbA = cells[x][y].aphids.size();
			for (int z = 0; z < numbA; z++){

				Aphid * moveA = cells[x][y].aphids.front();
				cells[x][y].aphids.pop_front();


				float move = (rand() % 10000) / 10000.0f;

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

			int numb = cells[x][y].ladybugs.size();
			for (int   z = 0; z < numb; z++){

				Ladybug * moveL = cells[x][y].ladybugs.front();
				cells[x][y].ladybugs.pop_front();
				float move = (rand() % 10000) / 10000.0f;

				if (move < moveL->movement_Prob&&moveL->hasMoved == false)
				{
					moveL->hasMoved = true;
					int position = (rand() % 3)/3;

					int yminus = y - 1;
					if (yminus < 0){
						yminus = 1;
						moveL->setHeading(2);
					}
					int yplus = y + 1;
					if (yplus == w){
						yplus = w - 1;
						moveL->setHeading(0);

					}
					int xminus = x - 1;
					if (xminus < 0){
						xminus = 1;
						moveL->setHeading(1);
					}
					int xplus = x + 1;
					if (xplus == h){
						xplus = x - 1;
						moveL->setHeading(3);
					}

					if (moveL->getHeading() == 0){

						switch (position)
						{

						case(0) : cells[x][yminus].add(moveL); break;

						case(1) : cells[xplus][yminus].add(moveL); break;

						case(2) : cells[xplus][yminus].add(moveL); break;


						}
					}
					if (moveL->getHeading() == 1){

						switch (position)
						{

						case(0) : cells[xplus][y].add(moveL); break;

						case(1) : cells[xplus][yminus].add(moveL); break;

						case(2) : cells[xplus][yplus].add(moveL); break;


						}

					}
					if (moveL->getHeading() == 2){

						switch (position)
						{

						case(0) : cells[x][yplus].add(moveL); break;

						case(1) : cells[xplus][yplus].add(moveL); break;

						case(2) : cells[xminus][yplus].add(moveL); break;


						}
					}
					if (moveL->getHeading() == 3){

						switch (position)
						{

						case(0) : cells[xminus][y].add(moveL); break;

						case(1) : cells[xminus][yplus].add(moveL); break;

						case(2) : cells[xminus][yminus].add(moveL); break;


						}
					}

				}


				else{
					moveL->hasMoved = true;
					cells[x][y].ladybugs.push_back(moveL);
				}

			}

		}

	}


	for (int x = 0; x < this->w; x++){

		for (int y = 0; y < this->h; y++){

			int numb = cells[x][y].aphids.size();
			for (int  z = 0; z < numb; z++){
				Aphid * moveA = cells[x][y].aphids.front();
				cells[x][y].aphids.pop_front();
				moveA->hasMoved = false;
				cells[x][y].aphids.push_back(moveA);

			}
			int numbL = cells[x][y].ladybugs.size();
			for (int z = 0; z < numbL; z++){

				Ladybug * moveA = cells[x][y].ladybugs.front();
				cells[x][y].ladybugs.pop_front();
				moveA->hasMoved = false;
				cells[x][y].ladybugs.push_back(moveA);
			}
		}
	}
}

bool Board::empty(){
	int counterA=0;
	int counterL=0;

	for (int x = 0; x < this->w; x++){

		for (int y = 0; y < this->h; y++){
			counterA += cells[x][y].aphids.size();
			counterL += cells[x][y].ladybugs.size();

		}
	}
	
	cout <<" Number of Aphids left "<< counterA <<endl;
	cout << " Number of Ladybugs left " << counterL << endl<<endl;
	if (counterA == 0 || counterL == 0){
		return true;

	}
	else{
		return false;
	}

}

bool Board::ladybugWin(){
	
	
	int counterL = 0;

	for (int x = 0; x < this->w; x++){

		for (int y = 0; y < this->h; y++){
			
			counterL += cells[x][y].ladybugs.size();

		}
	}

	
	if (counterL == 0){
		return true;

	}
	else{
		return false;
	}

}
Board::~Board()
{
}
