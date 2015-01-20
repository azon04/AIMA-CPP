#include "Agent.h"
#include "Sensor.h"
#include "Actuator.h"

Agent::Agent()
{
}

int Agent::getX()
{
	return position_x;
}

int Agent::getY() 
{
	return position_y;
}

void Agent::setX(int x) {
	position_x = x;
}
void Agent::setY(int y) {
	position_y = y;
}

void Agent::setEnv(Environtment* env) {
	if (sensor) {
		sensor->setEnv(env);
	}

	if (actuator) {
		actuator->setEnv(env);
	}
}

void Agent::setSensor(Sensor* _sensor) {
	sensor = _sensor;
	sensor->setAgent(this);
}

void Agent::setActuator(Actuator* _actuator) {
	actuator = _actuator;
	actuator->setAgent(this);
}

int Agent::run()
{
	sensor->detect();
	if (sensor->isDirt()) {
		return actuator->actionSuck();
	}
	else if (sensor->canMoveLeft()) {
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

Agent::~Agent()
{
	
}
