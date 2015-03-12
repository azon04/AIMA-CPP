#include "RBFS.h"
#include <vector>
#include <queue>
#define MAX(a,b) a < b ? b : a
#define MIN(a,b) a < b ? a : b

RBFS::RBFS()
{
}


RBFS::~RBFS()
{
}

Solution* RBFS::Solve(Problem* problem)
{
	Result result = RBFS_function(problem, NodeF(problem->getStartedNode(), 0, 0, 0), INT_MAX, 0, 0);
	return result.solution;
}

RBFS::Result& RBFS::RBFS_function(Problem* problem, NodeF& nodeF, int f_limit, Solution* sol, Action* action)
{
	Solution* solution = new Solution(sol, nodeF.node, action,
		sol == NULL ? 0 :
		sol->Cost() + nodeF.cost);
	if (problem->isGoal(nodeF.node)) {
		Result result(solution, f_limit);
		return result;
	}

	std::priority_queue<NodeF, std::vector<NodeF>, CompareNodeF> successors;

	std::vector<Action*> actions = nodeF.node->getActions();
	std::vector<int> costs = nodeF.node->getCosts();

	for (int i = 0; i < actions.size(); i++)
	{
		Action* action = actions[i];
		Node* child = (*(nodeF.node))[*action];
		NodeF childF(child, 0, nodeF.g + costs[i], (*table)[child]);
		childF.action = action;
		childF.f = MAX(childF.g + childF.h, nodeF.f);
		childF.cost = costs[i];
		successors.push(childF);
	}

	while (true)
	{

		NodeF best = successors.top(); successors.pop();
		if (best.f > f_limit) {
			Result result(0, best.f);
			return result;
		}
		// TO DO if successor only one
		NodeF alternative;
		if (successors.empty()) {
			alternative = best;
		}
		else 
		{
			alternative = successors.top(); successors.pop();
		}
		Result result = RBFS_function(problem, best, MIN(f_limit, alternative.f), solution, best.action);
		best.f = result.f;

		if (result.solution)
		{
			return result;
		}

		successors.push(best);
		successors.push(alternative);

	}


}

void RBFS::setHeuristic(HeuristicTableEvaluation* _evaluation)
{
	table = _evaluation;
}

bool RBFS::CompareNodeF::operator()(NodeF& node1, NodeF& node2)
{
	return (node1.f > node2.f) ? true : false;
}
