

#ifndef PROGRAM_H
#define PROGRAM_H
#include "Board.h"
#include "Aphid.h"
#include "Ladybug.h"
#include "Insect.h"
#include <iostream>
#include <fstream>
float Aphid::movement_Prob;
float Aphid::kill_Prob;
float Aphid::Group_Attack_Mod;
float Aphid::reproduce_Prob;
float Ladybug::movement_Prob;
float Ladybug::kill_Prob;
float Ladybug::direction_Change_Prob;
float Ladybug::reproduce_Prob;

class Program {

	public:
		Program();
		~Program();
		void update();
		void end();
		void get_Data();
		void set_up();
		void setboard(Board*);
		void print();
		Board * board;
		Board * nextBoard;
	
	private:
		
		



};


#endif 