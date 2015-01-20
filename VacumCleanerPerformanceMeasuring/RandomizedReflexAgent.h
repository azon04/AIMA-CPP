#pragma once
#include "Agent.h"

class RandomizedReflexAgent :
	public Agent
{
public:
	RandomizedReflexAgent();
	int run();
	~RandomizedReflexAgent();
};

