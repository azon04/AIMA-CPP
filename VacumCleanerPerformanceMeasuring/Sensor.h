#pragma once

#include "Environtment.h"
#include "Agent.h"

#ifndef _CLASS_SENSOR_
#define _CLASS_SENSOR_

class Sensor
{
public:
	Sensor();

	bool isDirt();
	void setEnv(Environtment*);
	void setAgent(Agent*);
	void detect();

	bool canMoveLeft();
	bool canMoveRight();
	bool canMoveUp();
	bool canMoveDown();

	~Sensor();
private:
	bool detected_dirt;
	Environtment* env;
	Agent* agent;
};

#endif

