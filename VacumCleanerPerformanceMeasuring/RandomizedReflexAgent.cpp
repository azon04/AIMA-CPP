#include "RandomizedReflexAgent.h"
#include "Sensor.h"
#include "Actuator.h"
#include <stdlib.h>

RandomizedReflexAgent::RandomizedReflexAgent()
{
}

int RandomizedReflexAgent::run() {
	sensor->detect();
	int move_random = rand() % 4;

	if (sensor->isDirt()) {
		return actuator->actionSuck();
	}
	
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

RandomizedReflexAgent::~RandomizedReflexAgent()
{
}
