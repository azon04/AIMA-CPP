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
	return RDLS(problem->getStartedNode(), problem, limit, 0, 0, 0);
}

Solution* Recursive_DLS::RDLS(Node* node, Problem* problem, int limit, Solution* prev, Action* action, int cost)
{
	Solution* solution = new Solution(prev, node, action, cost);
	if (problem->isGoal(node)) return solution;
	else if (limit == 0) return cutOff; // should be cut out
	else
	{
		bool isCutoff = false;
		std::vector<Action*> actions = node->getActions();
		std::vector<int> costs = node->getCosts();
		for (int i = 0; i < actions.size(); i++)
		{
			Action* action = actions[i];
			Node* child = (*node)[*action];
			Solution* result = RDLS(child, problem, limit - 1, solution, action, cost + costs[i]);
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
