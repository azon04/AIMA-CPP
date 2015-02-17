#pragma once
#include "Problem.h"
#include "Solution.h"
#include "HeuristicTableEvaluation.h"

class Greedy_BestFirstSearch
{
public:
	Greedy_BestFirstSearch();
	~Greedy_BestFirstSearch();

	Solution* Solve(Problem*);
	
	void setHeuristic(HeuristicTableEvaluation* _evaluation);

private:
	HeuristicTableEvaluation* table;
};

