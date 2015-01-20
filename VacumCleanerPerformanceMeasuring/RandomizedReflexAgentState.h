#pragma once
#include "Agent.h"
class RandomizedReflexAgentState :
	public Agent
{
public:
	RandomizedReflexAgentState();
	int run();
	void setEnv(Environtment*);
	void reset();
	~RandomizedReflexAgentState();
private:
	
	bool isAllObserve();

	int state[100][100];
	int width, height;
};

