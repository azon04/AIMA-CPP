#pragma once
#include "Problem.h"
#include "Solution.h"

class Recursive_DLS
{
public:
	Recursive_DLS();
	~Recursive_DLS();

	Solution* Solve(Problem*, int);

private:
	Solution* RDLS(Node*, Problem*, int);
	Solution* cutOff;
};

