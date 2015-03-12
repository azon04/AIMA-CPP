#include "A_star.h"
#include <queue>
#include <iostream>

int NodeWithAStarCost::inc = 0;

NodeWithAStarCost::NodeWithAStarCost(Node* _node, int _f_n, int _g_n)
: NodeWithCost(_node, _f_n + _g_n), id(inc++)
{
	f_n = _f_n;
}

NodeWithAStarCost::~NodeWithAStarCost()
{

}

int NodeWithAStarCost::getPathCost()
{
	return f_n;
}

A_star::A_star()
{
}


A_star::~A_star()
{
}



Solution* A_star::Solve(Problem* problem)
{
	int path_cost = 0;
	int g_n = 0;
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
	std::priority_queue<NodeWithAStarCost, std::vector<NodeWithAStarCost>, CompareNodeWithCost> frontier;
	g_n = (*table)[node];
	NodeWithAStarCost nodeWithCost(node, path_cost, g_n);
	frontier.push(nodeWithCost);

	std::map<NodeWithAStarCost, Solution*, CompareNodeAStarSame> solutionFrontier;
	solutionFrontier.insert(std::pair<NodeWithAStarCost, Solution*>(nodeWithCost, solution));

	// Explored array
	std::vector<Node*> explored;

	while (!frontier.empty())
	{
		NodeWithAStarCost nodeWC = frontier.top(); frontier.pop();
		node = nodeWC.getNode();
		path_cost = nodeWC.getPathCost();
		prevSolution = solutionFrontier[nodeWC]; //solutionFrontier[nodeWC] = 0;

		explored.push_back(node);

		// If Goal
		if (problem->isGoal(node))
		{
			return prevSolution;
		}

		// Get Posible Action
		std::vector<Action*> actions = node->getActions();
		std::vector<int> costs = node->getCosts();

		for (int i = 0; i < actions.size(); i++)
		{
			Action* action = actions[i];
			Node* child = (*node)[*action];
			if (std::find(explored.begin(), explored.end(), child) == explored.end())
			{
				// TODO check if value is in frontier
				// Create Solution
				solution = new Solution(prevSolution, child, action,
					prevSolution == NULL ? 0 :
					prevSolution->Cost() + costs[i]);

				g_n = (*table)[child];
				NodeWithAStarCost nodeChildCost(child, path_cost + costs[i], g_n );
				frontier.push(nodeChildCost);
				auto ret = solutionFrontier.insert(std::pair<NodeWithAStarCost, Solution*>(nodeChildCost, solution));
				if (ret.second == false) {
					std::cout << "Exist" << std::endl;
				}

			}
		}
	}

	return 0;
}

void A_star::setHeuristic(HeuristicTableEvaluation* _evaluation)
{
	table = _evaluation;
}

bool CompareNodeAStarSame::operator()(NodeWithAStarCost node1, NodeWithAStarCost node2)
{
	return node1.getID() < node2.getID();
}