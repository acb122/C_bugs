#ifndef APHID_H
#define APHID_H

#include "Insect.h"
class Aphid :
	public Insect
{
public:
	Aphid(int,int);
	~Aphid();
	void attack();
	void move();
	void mate();

	static float movement_Prob;
	static float Group_Attack_Mod;
	static float kill_Prob;
	static float reproduce_Prob;



private:




};
#endif
