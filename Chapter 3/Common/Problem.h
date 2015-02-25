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

class State {
public:
	State();
	State(const std::string&);
	virtual ~State();
	virtual int compareTo(const State& state);
	virtual std::string toString();
protected:
	/* Data Member */
	std::string valueString;
};

class Node {
public:
	Node();
	Node(const std::string&);
	Node(const State&);
	Node(Node*, const State&);
	~Node();

	void setState(const State&);
	
	State& getState();

	Node* operator[](Action&);

	std::vector<Action*>& getActions();
	std::vector<int>& getCosts();

	void setAction(Action*, Node*);
	void setAction(Action*, Node*, int);
private:
	/* Data Member */
	State state;
	Node* parent;
	std::map<std::string, Node*> relatedNodes;
	std::vector<Action*> actions;
	std::vector<int> costs;
};



class Problem {
public :
	Problem();
	~Problem();

	void setStart(Node*);
	void setGoal(const State&);
	void setGoal(Node*);

	bool isGoal(Node*);

	Node* getStartedNode();
	std::vector<Action*>& getActions();

private:
	/* Data Member */
	std::string name;
	Node* startNode;
	Node* goalNode;
	State goalState;
	std::vector<Action*> actions;
};

class NodeWithCost{
public:
	NodeWithCost();
	NodeWithCost(Node*, int);
	~NodeWithCost();

	Node* getNode();
	int getCost();

private:
	Node* node;
	int cost;
};

class CompareNodeWithCost{
public:
	bool operator()(NodeWithCost&, NodeWithCost&);
};

class CompareNodeWithCostMap {
public:
	bool operator()(NodeWithCost, NodeWithCost);
};