#include "Graph_UCS.h"
#include <queue>
#include <vector>
#include <map>
#include <iostream>

Graph_UCS::Graph_UCS()
{
}


Graph_UCS::~Graph_UCS()
{
}

Solution* Graph_UCS::Solve(Problem* problem)
{
	int path_cost = 0;
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
	NodeWithCost nodeWithCost(node, 0);
	frontier.push(nodeWithCost);

	std::map<Node*, Solution*> solutionFrontier;
	solutionFrontier.insert(std::pair<Node*, Solution*>(node,solution));

	// Explored array
	std::vector<Node*> explored;

	while (!frontier.empty())
	{
		NodeWithCost nodeWC = frontier.top(); frontier.pop();
		node = nodeWC.getNode();
		path_cost = nodeWC.getCost();
		std::cout << "explore : " << node->getState().c_str() << " cost : " << nodeWC.getCost() << std::endl;
		prevSolution = solutionFrontier[nodeWC.getNode()]; solutionFrontier[nodeWC.getNode()] = 0;

		explored.push_back(node);

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
				solution = new Solution(prevSolution, child, action);

				if (problem->isGoal(child))
				{
					return solution;
				}

				NodeWithCost nodeChildCost(child, path_cost + costs[i]);
				std::cout << "checked : " << child->getState().c_str() << " cost : " << costs[i] << std::endl;
				frontier.push(nodeChildCost);
				solutionFrontier.insert(std::pair<Node*, Solution*>(child, solution));
				
			}
		}
	}

	return 0;
}
