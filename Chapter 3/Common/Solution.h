#pragma once
#include "Problem.h"
#include <iostream>

class Solution {
public:
	Solution();
	Solution(Solution*, Node*, Action*);
	Solution(Solution*, Node*, Action*, int);
	~Solution();

	Node* getNode();
	Solution* getPrevSolution();
	Action* getAction();

	int Cost() const { return cost; }

	void setPrevSolution(Solution*);

private:
	/* Data Member */
	Node* currentNode;
	Solution* prevSolution;
	Action* currentAction;
	int cost;
};

std::ostream& operator<<(std::ostream& os, Solution*);
Solution* reverse(Solution*);