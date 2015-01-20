#pragma once
#include "Agent.h"
#include "Environtment.h"

#define ACTUATOR_ACTION_SUCK 1
#define ACTUATOR_ACTION_MOVE 2

//#define MURPHY_LAW

#ifndef _CLASS_ACTUATOR_
#define _CLASS_ACTUATOR_
class Actuator
{
public:
	Actuator();

	void setAgent(Agent*);
	void setEnv(Environtment*);

	int actionMoveLeft();
	int actionMoveRight();
	int actionMoveUp();
	int actionMoveDown();
	int actionSuck();

	~Actuator();
private:
	Agent* agent;
	Environtment* env;
};

#endif

