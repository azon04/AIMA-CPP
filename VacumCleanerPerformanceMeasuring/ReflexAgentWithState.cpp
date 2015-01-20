#include "ReflexAgentWithState.h"
#include "Sensor.h"
#include "Actuator.h"

ReflexAgentWithState::ReflexAgentWithState()
{
}

void ReflexAgentWithState::setEnv(Environtment* env) {
	Agent::setEnv(env);
	for (int y = 0; y < env->getHeight(); y++)
		for (int x = 0; x < env->getWidth(); x++)
			state[x][y] = 0;
}


int ReflexAgentWithState::run()
{
	// update state
	state[getX()][getY()]++;

	sensor->detect();
	if (sensor->isDirt()) {
		return actuator->actionSuck();
	}
	else if (sensor->canMoveLeft() && state[getX()-1][getY()] == 0) {
		return actuator->actionMoveLeft();
	}
	else if (sensor->canMoveDown() && state[getX()][getY()+1] == 0) {
		return actuator->actionMoveDown();
	}
	else if (sensor->canMoveRight() && state[getX() + 1][getY()] == 0) {
		return actuator->actionMoveRight();
	}
	else if (sensor->canMoveUp() && state[getX()][getY()-1] == 0) {
		return actuator->actionMoveUp();
	}

	// if there is not satisfy the state
	if (sensor->canMoveLeft()) {
		return actuator->actionMoveLeft();
	}
	else if (sensor->canMoveDown()) {
		return actuator->actionMoveDown();
	}
	else if (sensor->canMoveRight()) {
		return actuator->actionMoveRight();
	}
	else if (sensor->canMoveUp()) {
		return actuator->actionMoveUp();
	}

	return 0;
}

ReflexAgentWithState::~ReflexAgentWithState()
{
}
