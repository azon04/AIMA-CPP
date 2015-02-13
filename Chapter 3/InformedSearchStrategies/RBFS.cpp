#include "RBFS.h"
#include <vector>
#include <queue>

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
	if (problem->isGoal(nodeF.node)) {
		Solution* solution = new Solution(sol, nodeF.node, action);
		Result result(solution, f_limit);
		return result;
	}

	std::priority_queue<NodeF, std::vector<NodeF>, CompareNodeF> successors;

	std::vector<Action*> actions = nodeF.node->getActions();

	for (int i = 0; i < actions.size(); i++)
	{
		NodeF childF((*(nodeF.node))[action[i]], 0, 0, 0);
		successors.push(childF);
	}

}

bool RBFS::CompareNodeF::operator()(NodeF& node1, NodeF& node2)
{
	return (node1.f > node2.f) ? true : false;
}
