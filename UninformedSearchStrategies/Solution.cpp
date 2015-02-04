#include "Solution.h"
#include <stack>
#include <iostream>

using namespace std;

/* Constructor */
void GenerateSolution(SolutionAddress solution, SolutionAddress prevSolution, ActionAddress action, NodeAddress node)
{
	Prev(solution) = prevSolution;
	SolutionAction(solution) = action;
	SolutionNode(solution) = node;
}

/* Function */
void Print(SolutionAddress solution)
{
	stack<SolutionAddress> solutions;
	SolutionAddress s = solution;
	while (s != NULL)
	{
		solutions.push(s);
		s = Prev(s);
	}

	while (!solutions.empty()) {
		s = solutions.top();
		solutions.pop();

		if (SolutionAction(s) != NULL)
		{
			cout << " -" << ACTION_NAME(SolutionAction(s)) << "-> "  << STATE(SolutionNode(s));
		}
		else 
		{
			cout << STATE(SolutionNode(s));
		}
		
	}

	cout <<  endl;
}