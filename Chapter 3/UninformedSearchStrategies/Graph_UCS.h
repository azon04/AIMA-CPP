#pragma once
#include "Problem.h"
#include "Solution.h"

/* Uniform-cost Search*/
class Graph_UCS
{
public:
	Graph_UCS();
	~Graph_UCS();

	Solution* Solve(Problem*);
};

