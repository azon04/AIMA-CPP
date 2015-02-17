#pragma once
#include <map>
#include "Problem.h"

class HeuristicTableEvaluation
{
public:
	HeuristicTableEvaluation();
	~HeuristicTableEvaluation();

	void add(Node*, int);

	int operator[](Node*);

private:
	std::map<Node*, int> table;
};

