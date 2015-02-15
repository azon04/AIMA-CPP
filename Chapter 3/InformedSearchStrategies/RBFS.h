#pragma once
#include "Problem.h"
#include "Solution.h"
#include "HeuristicTableEvaluation.h"


class RBFS
{
public:
	struct Result {
		Result(Solution* _solution, int _f) :
		solution(_solution), f(_f) {};
		Solution* solution;
		int f;
	};

	struct NodeF {
		NodeF(Node* _node, int _f, int _g, int _h) 
		: node(_node), f(_f), g(_g), h(_h), action(0)
		{};
		Node* node;
		Action* action;
		int f;
		int g;
		int h;
	};

	class CompareNodeF
	{
	public:
		bool operator()(NodeF&, NodeF&);
	};

public:
	RBFS();
	~RBFS();

	Solution* Solve(Problem*);

	void setHeuristic(HeuristicTableEvaluation* _evaluation);
private:
	Result& RBFS_function(Problem*, NodeF&, int, Solution*, Action*);
	HeuristicTableEvaluation* table;
};

