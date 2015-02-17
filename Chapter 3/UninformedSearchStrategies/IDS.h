#pragma once
#include "Recursive_DLS.h"

class IDS :
	public Recursive_DLS
{
public:
	IDS();
	~IDS();

	Solution* Solve(Problem*);

private:
	int max_depth = 100;
};

