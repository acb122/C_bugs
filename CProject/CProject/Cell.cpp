#include "Cell.h"
#include <string>
#include <iostream>

using namespace std;

Cell::Cell()
{

}


Cell::~Cell()
{
}


void Cell::attack(){
	int numL = ladybugs.size();

	for (int z = 0; z < numL; z++){
		if (aphids.size() > 0){
			float move = (rand() % 10000) / 10000.0;
			Ladybug * attackL = ladybugs.front();
			if (attackL->kill_Prob > move){
				aphids.pop_front();

			}


		}
	}
	int numA = aphids.size();


	for (int z = 0; z < numA; z++){
		if (ladybugs.size() > 0){
			float attack_pb = (rand() % 10000) / 10000.0;

			Aphid * attackA = aphids.front();
			attack_pb = attack_pb + (attackA->Group_Attack_Mod*numA);

			if (attackA->kill_Prob < attack_pb){
				ladybugs.pop_front();

			}

		}
	}
}

void Cell::breed(){
	int numL = ladybugs.size();
	for (int z = 0; z < numL / 2; z++){
		Ladybug * baby = new Ladybug();
		float move = (rand() % 10000) / 10000.0;
		if (baby->reproduce_Prob > move){
			add(baby);
		}
		else{
			delete(baby);
		}

	}

	int numA = aphids.size();
	for (int z = 0; z < numA / 2; z++){
		Aphid * baby = new Aphid();
		float move = (rand() % 10000) / 10000.0;
		if (baby->reproduce_Prob > move){
			add(baby);
		}
		else{
			delete(baby);
		}

	}
}

void Cell::add(Ladybug * ladybug){
	ladybugs.push_back(ladybug);

}

void Cell::add(Aphid * aphid){
	aphids.push_back(aphid);

}

void Cell::print(){
	int aphidsN = aphids.size();
	int ladybirdsN = ladybugs.size();
	string ladybird;
	string aphid;
	if (aphidsN == 0){
		cout << "|" << " ";

	}
	else if (aphidsN > 9){
		cout << "|" << "~";

	}
	else{
		cout << "|" << aphidsN;
	}

	cout << ",";

	if (ladybirdsN == 0){
		cout << " " << "|";

	}
	else if (ladybirdsN > 9){
		cout << "~" << "|";

	}
	else{
		cout << ladybirdsN << "|";
	}




}

