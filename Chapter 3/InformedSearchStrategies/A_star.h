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
	int getID() { return id; }

private:
	int f_n; // to keep track of f(n) or path cost
	static int inc;
	int id;
};

class CompareNodeAStarSame {
public:
	bool operator()(NodeWithAStarCost, NodeWithAStarCost);
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


