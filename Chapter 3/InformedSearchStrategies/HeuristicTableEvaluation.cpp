#include "HeuristicTableEvaluation.h"


HeuristicTableEvaluation::HeuristicTableEvaluation()
{
}


HeuristicTableEvaluation::~HeuristicTableEvaluation()
{
}

void HeuristicTableEvaluation::add(Node* _node, int _score)
{
	table.insert(std::pair<Node*, int>(_node, _score));
}

int HeuristicTableEvaluation::operator[](Node* _node)
{
	return table[_node];
}
