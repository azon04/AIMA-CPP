#include "Graph_DFS.h"
#include <stack>

Graph_DFS::Graph_DFS()
{
}


Graph_DFS::~Graph_DFS()
{
}

Solution* Graph_DFS::Solve(Problem* problem)
{
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
	std::stack<Node*> frontier;
	frontier.push(node);

	std::stack<Solution*> solutionFrontier;
	solutionFrontier.push(solution);

	// Explored array
	std::vector<Node*> explored;

	while (!frontier.empty())
	{
		node = frontier.top(); frontier.pop();
		prevSolution = solutionFrontier.top(); solutionFrontier.pop();

		explored.push_back(node);

		// Get Posible Action
		std::vector<Action*> actions = node->getActions();

		// Check Goal
		if (problem->isGoal(node))
		{
			return prevSolution;
		}

		for (int i = 0; i < actions.size(); i++)
		{
			Action* action = actions[i];
			Node* child = (*node)[*action];
			if (std::find(explored.begin(), explored.end(), child) == explored.end())
			{
				// Create Solution
				solution = new Solution(prevSolution, child, action);


				frontier.push(child);
				solutionFrontier.push(solution);
			}
		}
	}

	return 0;
}
