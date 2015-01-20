#pragma once
#include "Agent.h"

class ReflexAgentWithState :
	public Agent
{
public:
	ReflexAgentWithState();
	int run();
	void setEnv(Environtment*);
	~ReflexAgentWithState();
private:
	int state[100][100];
};

