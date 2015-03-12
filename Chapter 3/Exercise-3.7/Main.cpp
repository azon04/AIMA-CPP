#include "Problem.h"
#include "Solution.h"
#include "Graph_BFS.h"
#include "Graph_DFS.h"
#include "Graph_UCS.h"
#include "Recursive_DLS.h"
#include "IDS.h"
#include "HeuristicTableEvaluation.h"
#include "RBFS.h"
#include "A_star.h"
#include "Greedy_BestFirstSearch.h"
#include <math.h>
#include <string>

class PositionState : public State {
public:
	PositionState(int x, int y);
	~PositionState();
	int compareTo(State* state);
	std::string& toString();
	int X() const;
	int Y() const;
private:
	int x;
	int y;
};

int Distance(int x1, int y1, int x2, int y2) {
	int divX = (x2 - x1);
	int divY = (y2 - y1);

	float distance = std::sqrtf(divX*divX + divY*divY);

	return static_cast<int>(distance);
}

void printAndDelete(Solution* solution) {
	if (solution) {
		std::cout << solution << std::endl ;
		std::cout << "COST : " << solution->Cost() << std::endl << std::endl;
		delete solution;
	}
	else
		std::cout << "No Solution Found" << std::endl << std::endl;
}

int main() {

	Node s(new PositionState(4, 5));
	Node trans[] = {
		{ new PositionState(4, 13) }, // 0
		{ new PositionState(20, 13) }, // 1
		{ new PositionState(35, 13) }, // 2
		{ new PositionState(28, 35) }, // 3
		{ new PositionState(33, 22) }, // 4
		{ new PositionState(46, 29) }, // 5
		{ new PositionState(41, 13) }, // 6
		{ new PositionState(47, 16) }, // 7
		{ new PositionState(43, 1) }, // 8
		{ new PositionState(52, 12) }, // 9
		{ new PositionState(65, 18) }, // 10
		{ new PositionState(63, 35) }, // 11
		{ new PositionState(69, 40) }, // 12
		{ new PositionState(74, 10) }, // 13
	};
	Node g(new PositionState(75, 38));

	// Actions
	Action b1("b1"),
		b2("b2"),
		b3("b3");
	
	// Model transitions
	s.setAction(&b1, &trans[0], Distance(4, 5, 4, 13));
	trans[0].setAction(&b1, &s, Distance(4, 5, 4, 13));
	trans[0].setAction(&b2, &trans[1], Distance(4, 13, 20, 13));
	trans[1].setAction(&b1, &trans[0], Distance(4, 13, 20, 13));
	trans[1].setAction(&b2, &trans[2], Distance(20, 13, 35, 13));
	trans[1].setAction(&b3, &trans[3], Distance(20, 13, 28, 35));
	trans[2].setAction(&b1, &trans[1], Distance(20, 13, 35, 13));
	trans[2].setAction(&b2, &trans[5], Distance(35, 13, 46, 29));
	trans[2].setAction(&b3, &trans[6], Distance(35, 13, 41, 13));
	trans[3].setAction(&b1, &trans[1], Distance(28, 35, 20, 13));
	trans[3].setAction(&b2, &trans[4], Distance(28, 35, 33, 22));
	trans[4].setAction(&b1, &trans[3], Distance(33, 22, 28, 35));
	trans[4].setAction(&b2, &trans[5], Distance(33, 22, 46, 29));
	trans[5].setAction(&b1, &trans[2], Distance(46, 29, 35, 13));
	trans[5].setAction(&b2, &trans[4], Distance(46, 29, 33, 22));
	trans[5].setAction(&b3, &trans[7], Distance(46, 29, 47, 16));
	trans[6].setAction(&b1, &trans[2], Distance(41, 13, 35, 13));
	trans[6].setAction(&b2, &trans[8], Distance(41, 13, 43, 1));
	trans[7].setAction(&b1, &trans[5], Distance(47, 16, 46, 29));
	trans[7].setAction(&b2, &trans[9], Distance(47, 16, 54, 12));
	trans[8].setAction(&b1, &trans[6], Distance(43, 1, 43, 13));
	trans[8].setAction(&b2, &trans[9], Distance(43, 1, 54, 12));
	trans[9].setAction(&b1, &trans[7], Distance(54, 12, 47, 16));
	trans[9].setAction(&b2, &trans[8], Distance(54, 12, 43, 1));
	trans[9].setAction(&b3, &trans[10], Distance(54, 12, 65, 18));
	trans[10].setAction(&b1, &trans[9], Distance(65, 18, 54, 12));
	trans[10].setAction(&b2, &trans[11], Distance(65, 18, 63, 35));
	trans[10].setAction(&b3, &trans[13], Distance(65, 18, 74, 10));
	trans[11].setAction(&b1, &trans[10], Distance(63, 35, 65, 18));
	trans[11].setAction(&b2, &trans[12], Distance(63, 35, 69, 40));
	trans[12].setAction(&b1, &trans[11], Distance(69, 40, 63, 35));
	trans[12].setAction(&b2, &g, Distance(69, 40, 75, 38));
	trans[13].setAction(&b1, &trans[10], Distance(74, 10, 65, 18));
	trans[13].setAction(&b2, &g, Distance(74, 10, 75, 38));
	g.setAction(&b1, &trans[12], Distance(75,38, 69, 40));
	g.setAction(&b2, &trans[13], Distance(75, 38, 74, 10));

	// Problem
	Problem problem;
	problem.setStart(&s);
	problem.setGoal(&g);

	// Solve Using BFS
	Graph_BFS bfsSolver;
	Solution* solution = bfsSolver.Solve(&problem);

	std::cout << "BFS Solution :" << std::endl;
	std::cout << "================" << std::endl;
	printAndDelete(solution);

	// Solve using DFS
	Graph_DFS dfsSolver;
	solution = dfsSolver.Solve(&problem);

	std::cout << "DFS Solution :" << std::endl;
	std::cout << "================" << std::endl;
	printAndDelete(solution);

	// Solve using UCS
	Graph_UCS ucsSolver;
	solution = ucsSolver.Solve(&problem);

	std::cout << "UCS Solution :" << std::endl;
	std::cout << "================" << std::endl;
	printAndDelete(solution);

	// Solve using IDS
	IDS IDSSolver;
	solution = IDSSolver.Solve(&problem);

	std::cout << "IDS Solution :" << std::endl;
	std::cout << "================" << std::endl;
	printAndDelete(solution);

	// Heuristic Table
	HeuristicTableEvaluation table;
	table.add(&s, 100);
	for (int i = 0; i < 14; i++) {
		PositionState* current = static_cast<PositionState*>(trans[i].getState());
		PositionState* goal = static_cast<PositionState*>(g.getState());
		table.add(&trans[i], Distance(current->X(), current->Y(),
			goal->X(), goal->Y()));
	}
	table.add(&g, 0);

	// Solve using RBFS
	RBFS RBFSSolver;
	RBFSSolver.setHeuristic(&table);
	solution = RBFSSolver.Solve(&problem);

	std::cout << "RBFS :" << std::endl;
	std::cout << "================" << std::endl;
	printAndDelete(solution);

	// Solve using Greedy_BFSSolver
	Greedy_BestFirstSearch Greedy_BFSSolver;
	Greedy_BFSSolver.setHeuristic(&table);
	solution = Greedy_BFSSolver.Solve(&problem);

	std::cout << "Greedy_BFSSolver :" << std::endl;
	std::cout << "================" << std::endl;
	printAndDelete(solution);

	// Solve using A*
	A_star AStarSolver;
	AStarSolver.setHeuristic(&table);
	solution = AStarSolver.Solve(&problem);

	std::cout << "AStar Solver :" << std::endl;
	std::cout << "================" << std::endl;
	printAndDelete(solution);

	return 0;
}

PositionState::PositionState(int _x, int _y)
: State(""), x(_x), y(_y)
{
	
}

PositionState::~PositionState()
{

}

int PositionState::compareTo(State* state)
{
	PositionState* posState = static_cast<PositionState*>(state);
	if (this->x == posState->x && this->y == posState->y)
		return 0;
	return this->x - posState->x + this->y - posState->y;
}

std::string& PositionState::toString()
{
	valueString = "";
	valueString += std::to_string(x);
	valueString += ",";
	valueString += std::to_string(y);
	return valueString;
}

int PositionState::X() const
{
	return x;
}

int PositionState::Y() const
{
	return y;
}