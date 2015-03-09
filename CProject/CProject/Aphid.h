#ifndef APHID_H
#define APHID_H

#include "Insect.h"
class Aphid :
	public Insect
{
public:
	Aphid();
	~Aphid();
	void attack();


	static float Aphid::movement_Prob;
	static float Aphid::Group_Attack_Mod;
	static float Aphid::kill_Prob;
	static float Aphid::reproduce_Prob;



private:




};
#endif
