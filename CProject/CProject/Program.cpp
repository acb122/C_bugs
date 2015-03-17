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
	
	time_t t = time(0);
	
	srand(t);
	Program program = Program();

	ifstream myfile("aphids.conf");
	if (myfile.is_open()){


		myfile >> Aphid::movement_Prob;
		myfile >> Aphid::kill_Prob;
		myfile >> Aphid::Group_Attack_Mod;
		myfile >> Aphid::reproduce_Prob;

	}
	else{
		cout << "aphids config file not found default data used";
		 Aphid::movement_Prob = 0.7f;
		 Aphid::kill_Prob= 0.2f; 
		 Aphid::Group_Attack_Mod = 0.1f;
		 Aphid::reproduce_Prob = 0.4f;


	}

	ifstream myfile2("ladybugs.conf");
	if (myfile2.is_open()){
		myfile2 >> Ladybug::movement_Prob;
		myfile2 >> Ladybug::direction_Change_Prob;
		myfile2 >> Ladybug::kill_Prob;
		myfile2 >> Ladybug::reproduce_Prob;
	}
	else{
		cout << "ladybugs config file not found default data used";
		Ladybug::movement_Prob= 0.7f;
		Ladybug::direction_Change_Prob=0.2f;
		Ladybug::kill_Prob=0.4f;
		Ladybug::reproduce_Prob=0.2f;
	}

	int w, h, aphidsN, ladybugsN, i;

	ifstream myfile3("aphidsAndLadybugs.conf");
	if (myfile3.is_open()){
		myfile3 >> w >> h;
		
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
		cout << "manager config file not found debug used";
		myfile3 >> w >> h;
		
		cout << endl;
		program.board = new Board(10, 10);


		

			program.board->add(new Aphid(), 3, 5);
			program.board->add(new Aphid(), 4, 8); 
			program.board->add(new Aphid(), 2, 9); 
			program.board->add(new Aphid(), 1, 6); 
			program.board->add(new Aphid(), 1, 9);
		


			program.board->add(new Ladybug(), 5,9);
			program.board->add(new Ladybug(), 1,1);
			program.board->add(new Ladybug(), 3,8);
			program.board->add(new Ladybug(), 9,2);
	}

	int counter = 0;
	cout << "Starting board"<<endl;
	program.print();
	cout << endl;
	do
	{
		counter++;
		cout << "Turn : " << counter << endl<< endl;
		program.update();
		program.print();
		cout << endl;

	} while (program.board->empty() == false);
	

	if (program.board->ladybugWin() == true){
		cout << "No Aphids left winner is Ladybugs";
	}
	else{
		cout << "No Ladybugs left winner is Aphids";
	
	}
	cout << endl;
	program.print();
	getchar();
	
}