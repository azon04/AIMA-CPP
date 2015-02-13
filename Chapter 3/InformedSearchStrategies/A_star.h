#pragma once
#include "Problem.h"
#include "Solution.h"
#include "HeuristicTableEvaluation.h"

class NodeWithAStarCost : public NodeWithCost
{
public:
	NodeWithAStarCost(Node*, int f_n,int g_n);
	~NodeWithAStarCost();

	int getPathCost();

private:
	int f_n; // to keep track of f(n) or path cost
};

class A_star
{
public:
	A_star();
	~A_star();

	Solution* Solve(Problem*);

	void setHeuristic(HeuristicTableEvaluation* _evaluation);

private:
	HeuristicTableEvaluation* table;
};

