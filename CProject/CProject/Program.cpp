#include "Program.h"
#include <vld.h> 
#include <ctime>

using namespace std;

#include "Board.h"
#include "Aphid.h"
#include "Ladybug.h"
#include "Insect.h"

Program::Program()
{
}

void Program::setboard(Board * b){
	board = b;
}

Program::~Program()
{
}

void Program::print(){
	board->print();

}

void Program::update(){
	this->board->move();
	this->board->attack();
	this->board->breed();

}

int main(){
	srand(time(0));
	Program program = Program();

	ifstream myfile("aphids.conf");
	if (myfile.is_open()){


		myfile >> Aphid::movement_Prob;
		myfile >> Aphid::kill_Prob;
		myfile >> Aphid::Group_Attack_Mod;
		myfile >> Aphid::reproduce_Prob;

	}
	else{
		cout << "aphids not found";
	}

	ifstream myfile2("ladybugs.conf");
	if (myfile2.is_open()){
		myfile2 >> Ladybug::movement_Prob;
		myfile2 >> Ladybug::direction_Change_Prob;
		myfile2 >> Ladybug::kill_Prob;
		myfile2 >> Ladybug::reproduce_Prob;
	}
	else{
		cout << "ladybugs not found";
	}

	int w, h, aphidsN, ladybugsN, i;

	ifstream myfile3("aphidsAndLadybugs.conf");
	if (myfile3.is_open()){
		myfile3 >> w >> h;
		cout << w;
		cout << endl;
		program.board = new Board(w, h);


		//07977598613
		myfile3 >> aphidsN;
		for (i = 0; aphidsN > i; i++){
			int x, y;
			myfile3 >> x >> y;


			program.board->add(new Aphid(), x, y);

		}

		myfile3 >> ladybugsN;
		for (i = 0; ladybugsN > i; i++){
			int x, y;
			myfile3 >> x >> y;
			program.board->add(new Ladybug(), x, y);


		}

	}
	else{
		cout << "insects not added";
	}

	int counter = 0;
	while (program.board->empty() == false){
		program.print();
		
		program.update();
		counter++;
		cout << counter << endl;
				
			
			
			
			
			
			
			
			
	}
	getchar();
	
}