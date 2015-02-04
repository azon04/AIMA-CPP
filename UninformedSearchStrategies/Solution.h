#pragma once
#include "Problem.h"
#include <iostream>

class Solution {
public:
	Solution();
	Solution(Solution*, Node*, Action*);
	~Solution();

	Node* getNode();
	Solution* getPrevSolution();
	Action* getAction();

private:
	/* Data Member */
	Node* currentNode;
	Solution* prevSolution;
	Action* currentAction;
};

std::ostream operator<<(std::ostream& os, const Solution&);