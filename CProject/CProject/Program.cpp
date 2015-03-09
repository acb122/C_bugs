#include "Program.h"

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

int main(){

	Program program = Program();
	
	ifstream myfile ("aphids.conf");
	if (myfile.is_open()){
		cin >> Aphid::movement_Prob ;
		cin >> Aphid::kill_Prob;
		cin >> Aphid::Group_Attack_Mod;
		cin >> Aphid::reproduce_Prob;
	}
	else{
		cout << "aphids not found";
	}

	ifstream myfile2("ladybugs.conf");
	if (myfile2.is_open()){
		cin >> Ladybug::movement_Prob;
		cin >> Ladybug::direction_Change_Prob;
		cin >> Ladybug::kill_Prob;
		cin >> Ladybug::reproduce_Prob;
	}
	else{
		cout << "ladybugs not found";
	}

	int w, h, aphidsN,ladybugsN,i;
	
	ifstream myfile3("aphidsAndLadybugs.conf");
	if (myfile3.is_open()){
		cin >> w >> h;
		program.board = new Board(w, h); 
		
			
		//07977598613
		cin >> aphidsN;
		for (i = 0; aphidsN > i; i++){
			int x, y;
			cin >> x >> y;
			
			
			program.board->add(new Aphid(x, y));

		}

		cin >> ladybugsN;
		for (i = 0; ladybugsN > i; i++){
			int x, y;
			cin >> x >> y;
			program.board->add(new Ladybug(x, y));
			

		}
		
	}
	else{
		cout << "insects not added";
	}
	program.print();

}