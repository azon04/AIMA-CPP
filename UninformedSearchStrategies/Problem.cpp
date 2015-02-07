#include "Problem.h"

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

/*NODE CLASS*/
Node::Node() 
: state("DefaultState"), 
parent(0)
{

}

Node::Node(const std::string& _state) 
: state(_state),
parent(0)
{

}

Node::Node(Node* _parent, const std::string& _state)
: parent(_parent),
state(_state)
{

}

Node::~Node()
{

}

void Node::setState(const std::string& _state)
{
	state = _state;
}

std::string& Node::getState()
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

void Node::setAction(Action* _action, Node* _node)
{
	actions.push_back(_action);
	relatedNodes.insert(std::pair<std::string, Node*>(_action->getName(), _node));
}

/* PROBLEM CLASS */
Problem::Problem()
: name("Problem"), startNode (0), goalState("goal") 
{

}

Problem::~Problem() 
{

}

void Problem::setStart(Node* _node)
{
	startNode = _node;
}

void Problem::setGoal(const std::string& _goal) 
{
	goalState = _goal;
}

bool Problem::isGoal(Node* _node)
{
	if (_node->getState().compare(goalState) == 0) 
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
