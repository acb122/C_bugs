#ifndef LADYBUG_H
#define LADYBUG_H
#include "Insect.h"
class Ladybug :
	public Insect
{
public:
	Ladybug();
	~Ladybug();
	void attack();
	void move();
	void mate();
	int getHeading();
	void setHeading(int);

	static float movement_Prob;
	static float direction_Change_Prob;
	static float kill_Prob;
	static float reproduce_Prob;

	



private:


	int heading;

};
#endif

