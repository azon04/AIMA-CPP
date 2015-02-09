#include "Recursive_DLS.h"


Recursive_DLS::Recursive_DLS()
: cutOff(new Solution(0,0,0))
{
}


Recursive_DLS::~Recursive_DLS()
{
}

Solution* Recursive_DLS::Solve(Problem* problem, int limit)
{
	return RDLS(problem->getStartedNode(), problem, limit);
}

Solution* Recursive_DLS::RDLS(Node* node, Problem* problem, int limit)
{
	Solution* solution = new Solution(0, node, 0);
	if (problem->isGoal(node)) return solution;
	else if (limit == 0) return cutOff; // should be cut out
	else
	{
		bool isCutoff = false;
		std::vector<Action*> actions = node->getActions();
		for (int i = 0; i < actions.size(); i++)
		{
			Action* action = actions[i];
			Node* child = (*node)[*action];
			Solution* result = RDLS(child, problem, limit - 1);
			if (result == cutOff) isCutoff = true;
			else if (result) { 
				// Set Previous
				return result; 
			}
		}
		if (isCutoff) return cutOff;
		else return 0;
	}
}
