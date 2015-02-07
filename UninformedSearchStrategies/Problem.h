#pragma once
#include <map>
#include <vector>

class Action {
public:
	Action();
	Action(const std::string&);
	~Action();

	const std::string& getName();

private:
	/* Data Member*/
	std::string name;
};

class Node {
public:
	Node();
	Node(const std::string&);
	Node(Node*, const std::string&);
	~Node();

	void setState(const std::string&);
	
	std::string& getState();

	Node* operator[](Action&);

	std::vector<Action*>& getActions();

	void setAction(Action*, Node*);

private:
	/* Data Member */
	std::string state;
	Node* parent;
	std::map<std::string, Node*> relatedNodes;
	std::vector<Action*> actions;
};



class Problem {
public :
	Problem();
	~Problem();

	void setStart(Node*);
	void setGoal(const std::string&);

	bool isGoal(Node*);

	Node* getStartedNode();
	std::vector<Action*>& getActions();

private:
	/* Data Member */
	std::string name;
	Node* startNode;
	std::string goalState;
	std::vector<Action*> actions;
};