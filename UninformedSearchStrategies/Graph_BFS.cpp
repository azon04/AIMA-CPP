#include "Graph_BFS.h"
#include <queue>
#include <vector>

Graph_BFS::Graph_BFS()
{
}


Graph_BFS::~Graph_BFS()
{
}

Solution* Graph_BFS::Solve(Problem* problem)
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
	std::queue<Node*> frontier;
	frontier.push(node);
	
	std::queue<Solution*> solutionFrontier;
	solutionFrontier.push(solution);

	// Explored array
	std::vector<Node*> explored;

	while (!frontier.empty())
	{
		node = frontier.front(); frontier.pop();
		prevSolution = solutionFrontier.front(); solutionFrontier.pop();

		explored.push_back(node);

		// Get Posible Action
		std::vector<Action*> actions = node->getActions();

		for (int i = 0; i < actions.size(); i++)
		{
			Action* action = actions[i];
			Node* child = (*node)[*action];
			if (std::find(explored.begin(), explored.end(), child) == explored.end())
			{
				// Create Solution
				solution = new Solution(prevSolution, child, action);

				if (problem->isGoal(child))
				{
					return solution;
				}

				frontier.push(child);
				solutionFrontier.push(solution);
			}
		}
	}

	return 0;
}
