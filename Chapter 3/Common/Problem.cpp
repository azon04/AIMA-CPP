#include "Problem.h"
#include <iostream>

/*ACTION CLASS*/

Action::Action() : name("DefaultName")
{

}

Action::Action(const std::string& _name) : name(_name)
{

}

Action::~Action()
{

}

const std::string& Action::getName()
{
	return name;
}

/* STATE CLASS */
State::State() :
valueString("")
{

}

State::State(const std::string& value) :
valueString(value)
{

}

State::~State()
{

}

int State::compareTo(State* state)
{
	return valueString.compare(state->valueString);
}

std::string& State::toString()
{
	return valueString;
}

/*NODE CLASS*/
Node::Node() 
: state(nullptr), 
parent(0)
{

}

Node::Node(State* _state) 
: state(_state),
parent(0)
{

}

Node::Node(const std::string& _state)
: state(new State(_state)),
parent(0)
{

}

Node::Node(Node* _parent, State* _state)
: parent(_parent),
state(_state)
{

}

Node::~Node()
{

}

void Node::setState(State* _state)
{
	state = _state;
}

State* Node::getState()
{
	return state;
}

Node* Node::operator[](Action& _action)
{
	return relatedNodes[_action.getName()];
}

std::vector<Action*>& Node::getActions()
{
	return actions;
}

std::vector<int>& Node::getCosts()
{
	return costs;
}

void Node::setAction(Action* _action, Node* _node)
{
	costs.push_back(0);
	actions.push_back(_action);
	relatedNodes.insert(std::pair<std::string, Node*>(_action->getName(), _node));
}

void Node::setAction(Action* _action, Node* _node, int _cost) {
	costs.push_back(_cost);
	actions.push_back(_action);
	relatedNodes.insert(std::pair<std::string, Node*>(_action->getName(), _node));
}

/* PROBLEM CLASS */
Problem::Problem()
: name("Problem"), startNode(0), goalState(nullptr), goalNode(0)
{

}

Problem::~Problem() 
{

}

void Problem::setStart(Node* _node)
{
	startNode = _node;
}

void Problem::setGoal(State* _goal) 
{
	goalState = _goal;
}

void Problem::setGoal(Node* _goal)
{
	goalNode = _goal;
}

bool Problem::isGoal(Node* _node)
{
	if (goalNode)
	{
		return _node->getState()->compareTo((goalNode->getState())) == 0;
	}
	else if (_node->getState()->compareTo(goalState) == 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

Node* Problem::getStartedNode()
{
	return startNode;
}

std::vector<Action*>& Problem::getActions()
{
	return actions;
}

/* CLASS NODEWITHCOST */
NodeWithCost::NodeWithCost()
: node(0), cost(0)
{

}

NodeWithCost::NodeWithCost(Node* _node, int _cost)
: node(_node), cost(_cost)
{

}

NodeWithCost::~NodeWithCost()
{

}

Node* NodeWithCost::getNode()
{
	return node;
}

int NodeWithCost::getCost()
{
	return cost;
}

/* Class CompareNodeWithCost */
/* For priority Queue, check "http://comsci.liu.edu/~jrodriguez/cs631sp08/c++priorityqueue.html" */

bool CompareNodeWithCost::operator()(NodeWithCost& node1, NodeWithCost& node2)
{
	return (node1.getCost() > node2.getCost()) ? true : false;
}

/* Class CompareNodeWithCostMap*/
/* For MAP<> */
bool CompareNodeWithCostMap::operator()(NodeWithCost node1, NodeWithCost node2)
{
	return (node1.getCost() < node2.getCost()) ? true : false;
}