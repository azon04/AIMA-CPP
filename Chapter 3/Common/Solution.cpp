#include "Solution.h"
#include <stack>
#include <iostream>
#include <string>

Solution::Solution()
: currentNode(0), prevSolution(0), currentAction(0), cost(0)
{

}

Solution::Solution(Solution* _prev, Node* _node, Action* _action)
	: currentNode(_node), prevSolution(_prev), currentAction(_action),
	cost(0)
{

}

Solution::Solution(Solution* _prev, Node* _node, Action* _action,
	int _cost)
: currentNode(_node), prevSolution(_prev), currentAction(_action),
cost(_cost)
{

}

Solution::~Solution()
{
	if (prevSolution)
		delete prevSolution;
}

Node* Solution::getNode()
{
	return currentNode;
}

Solution* Solution::getPrevSolution()
{
	return prevSolution;
}

Action* Solution::getAction()
{
	return currentAction;
}

std::ostream& operator<<(std::ostream& os, Solution* _solution)
{
	Solution* solution = _solution;
	std::stack<Solution*> solutions;
	solutions.push(solution);
	while (solution->getPrevSolution() != NULL)
	{
		solution = solution->getPrevSolution();
		solutions.push(solution);
	}

	while (!solutions.empty())
	{
		solution = solutions.top(); solutions.pop();
		if (solution->getAction() == NULL && solution->getNode() == 0)
			os << "This may be cutoff" << std::endl;
		else if (solution->getAction() == NULL)
			os << solution->getNode()->getState()->toString() << std::endl;
		else
			os << "(" << solution->getAction()->getName() << ")"
				<< solution->getNode()->getState()->toString() << std::endl;
	}

	return os;
}

void Solution::setPrevSolution(Solution* _prev)
{
	prevSolution = _prev;
}

Solution* reverse(Solution* _solution)
{
	Solution* solution = _solution;
	Solution* tmpSolution;
	Solution* result;
	std::stack<Solution*> solutions;
	solutions.push(solution);
	while (solution->getPrevSolution() != NULL)
	{
		solution = solution->getPrevSolution();
		solutions.push(solution);
	}

	tmpSolution = solutions.top(); solutions.pop();
	result = tmpSolution;
	while (!solutions.empty())
	{
		solution = solutions.top(); solutions.pop();
		tmpSolution->setPrevSolution(solution);
		tmpSolution = solution;
	}

	tmpSolution->setPrevSolution(0);
	return result;
}