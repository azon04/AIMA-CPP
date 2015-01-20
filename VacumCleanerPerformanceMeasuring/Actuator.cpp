#include "Actuator.h"
#include <stdlib.h>

Actuator::Actuator()
{
}

void Actuator::setAgent(Agent* _agent)
{
	agent = _agent;
}

void Actuator::setEnv(Environtment* _env)
{
	env = _env;
}

int Actuator::actionMoveLeft()
{
	agent->setX(agent->getX() - 1);
	return ACTUATOR_ACTION_MOVE;
}

int Actuator::actionMoveRight()
{
	agent->setX(agent->getX() + 1);
	return ACTUATOR_ACTION_MOVE;
}


int Actuator::actionMoveUp()
{
	agent->setY(agent->getY() - 1);
	return ACTUATOR_ACTION_MOVE;
}

int Actuator::actionMoveDown()
{
	agent->setY(agent->getY() + 1);
	return ACTUATOR_ACTION_MOVE;
}

int Actuator::actionSuck()
{
	#ifdef MURPHY_LAW
		int prob = rand() % 100;
		if(prob < 25) {
			// Failed clean and deposit the dirt
			env->setDirt(agent->getX(), agent->getY(), true);
			return 0;
		} else {
			env->setDirt(agent->getX(), agent->getY(), false);
			return ACTUATOR_ACTION_SUCK;
		}
	#else
		env->setDirt(agent->getX(), agent->getY(), false);
		return ACTUATOR_ACTION_SUCK;
	#endif
}

Actuator::~Actuator()
{
}
