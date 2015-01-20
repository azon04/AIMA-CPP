#include "Sensor.h"
#include <stdlib.h>

#define MURPHY_LAW

Sensor::Sensor()
{
	detected_dirt = false;
}

bool Sensor::isDirt() {
	return detected_dirt;
}

void Sensor::setEnv(Environtment* env) {
	this->env = env;
}

void Sensor::setAgent(Agent* _agent) {
	agent = _agent;
}

void Sensor::detect() {
#ifdef MURPHY_LAW
	int prob = rand() % 100;
	if (env) {
		if (prob < 10) {
			detected_dirt = !(*env)(agent->getX(), agent->getY());
		}
		else {
			detected_dirt = (*env)(agent->getX(), agent->getY());
		}
	}
#else
	if (env) {
		detected_dirt = (*env)(agent->getX(), agent->getY());
	}
#endif
}

bool Sensor::canMoveLeft() {
	return agent->getX() > 0 ? true : false;
}

bool Sensor::canMoveRight() {
	return agent->getX() < (env->getWidth() - 1) ? true : false;
}

bool Sensor::canMoveUp() {
	return agent->getY() > 0 ? true : false;
}

bool Sensor::canMoveDown() {
	return agent->getY() < (env->getHeight() - 1) ? true : false;
}

Sensor::~Sensor()
{
}
