#include "RandomizedReflexAgentState.h"
#include "Sensor.h"
#include "Actuator.h"
#include  <stdlib.h>

RandomizedReflexAgentState::RandomizedReflexAgentState()
{
}

void RandomizedReflexAgentState::setEnv(Environtment* env) {
	Agent::setEnv(env);
	width = env->getWidth();
	height = env->getHeight();
	for (int y = 0; y < env->getHeight(); y++)
	for (int x = 0; x < env->getWidth(); x++)
		state[x][y] = 0;
}

bool RandomizedReflexAgentState::isAllObserve() {
	for (int y = 0; y < width; y++)
	for (int x = 0; x < height; x++)
	if (state[x][y] == 0) return false;

	return true;
}

void RandomizedReflexAgentState::reset() {
	for (int y = 0; y < width; y++)
		for (int x = 0; x < height; x++)
			state[x][y] = 0;
}

int RandomizedReflexAgentState::run()
{
	// update state
	if (isAllObserve())
		reset();

	state[getX()][getY()]++;

	sensor->detect();
	if (sensor->isDirt()) {
		return actuator->actionSuck();
	}
	else if (sensor->canMoveLeft() && state[getX() - 1][getY()] == 0) {
		return actuator->actionMoveLeft();
	}
	else if (sensor->canMoveDown() && state[getX()][getY() + 1] == 0) {
		return actuator->actionMoveDown();
	}
	else if (sensor->canMoveRight() && state[getX() + 1][getY()] == 0) {
		return actuator->actionMoveRight();
	}
	else if (sensor->canMoveUp() && state[getX()][getY() - 1] == 0) {
		return actuator->actionMoveUp();
	}

	// if there is not satisfy the state
	int move_random = rand() % 4;

	if (sensor->canMoveLeft() && move_random == 0) {
		return actuator->actionMoveLeft();
	}


	if (sensor->canMoveDown() && move_random == 1) {
		return actuator->actionMoveDown();
	}

	if (sensor->canMoveRight() && move_random == 2) {
		return actuator->actionMoveRight();
	}

	if (sensor->canMoveUp() && move_random == 3) {
		return actuator->actionMoveUp();
	}

	return 0;
}

RandomizedReflexAgentState::~RandomizedReflexAgentState()
{
}
