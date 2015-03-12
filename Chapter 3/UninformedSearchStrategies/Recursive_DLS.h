#pragma once
#include "Problem.h"
#include "Solution.h"

class Recursive_DLS
{
public:
	Recursive_DLS();
	~Recursive_DLS();

	Solution* Solve(Problem*, int);

public:
	Solution* cutOff;

private:
	Solution* RDLS(Node*, Problem*, int, Solution*, Action* action, int cost);
	
};

