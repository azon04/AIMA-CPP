#include "Greedy_BestFirstSearch.h"
#include  <queue>
#include <vector>

Greedy_BestFirstSearch::Greedy_BestFirstSearch()
{
}


Greedy_BestFirstSearch::~Greedy_BestFirstSearch()
{
}

Solution* Greedy_BestFirstSearch::Solve(Problem* problem)
{

	int f_n = 0;
	Solution* solution;
	Solution* prevSolution;
	Node* node = problem->getStartedNode();

	// Create Solution
	solution = new Solution(0, node, 0);


	if (problem->isGoal(node))
	{
		return solution;
	}

	// A FIFO Queue, and add the first node
	std::priority_queue<NodeWithCost, std::vector<NodeWithCost>, CompareNodeWithCost> frontier;
	f_n = (*table)[node];
	NodeWithCost nodeWithCost(node, f_n);
	frontier.push(nodeWithCost);

	std::map<NodeWithCost, Solution*, CompareNodeWithCostMap> solutionFrontier;
	solutionFrontier.insert(std::pair<NodeWithCost, Solution*>(nodeWithCost, solution));

	// Explored array
	std::vector<Node*> explored;

	while (!frontier.empty())
	{
		NodeWithCost nodeWC = frontier.top(); frontier.pop();
		node = nodeWC.getNode();
		f_n = nodeWC.getCost();
		prevSolution = solutionFrontier[nodeWC]; solutionFrontier[nodeWC] = 0;

		explored.push_back(node);

		// If Goal
		if (problem->isGoal(node))
		{
			return prevSolution;
		}

		// Get Posible Action
		std::vector<Action*> actions = node->getActions();
		for (int i = 0; i < actions.size(); i++)
		{
			Action* action = actions[i];
			Node* child = (*node)[*action];
			if (std::find(explored.begin(), explored.end(), child) == explored.end())
			{
				// TODO check if value is in frontier
				// Create Solution
				solution = new Solution(prevSolution, child, action);

				f_n = (*table)[child];
				NodeWithCost nodeChildCost(child, f_n);

				frontier.push(nodeChildCost);
				solutionFrontier.insert(std::pair<NodeWithCost, Solution*>(nodeChildCost, solution));

			}
		}
	}

	return 0;
}

void Greedy_BestFirstSearch::setHeuristic(HeuristicTableEvaluation* _evaluation)
{
	table = _evaluation;
}
