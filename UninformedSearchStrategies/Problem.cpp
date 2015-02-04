#include "Problem.h"

/*ACTION CLASS*/

Action::Action() : name("DefaultName")
{

}

Action::Action(std::string& _name) : name(_name)
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

/* PROBLEM CLASS */

