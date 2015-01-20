#pragma once

#include "Environtment.h"

class Sensor;
class Actuator;

#ifndef _CLASS_AGENT_
#define _CLASS_AGENT_

class Agent
{
public:
	Agent();

	int getX();
	int getY();

	void setX(int);
	void setY(int);

	virtual void setEnv(Environtment*);

	virtual void setSensor(Sensor*);
	virtual void setActuator(Actuator*);

	virtual int run();

	~Agent();
private:
	int position_x, position_y;
protected:
	Sensor* sensor;
	Actuator* actuator;
};

#endif

