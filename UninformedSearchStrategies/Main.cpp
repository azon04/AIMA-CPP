#include "Graph_BFS.h"
#include "Graph_DFS.h"

int main()
{
	/* road map Romania Problem */

	// States
	Node arad("Arad");
	Node sibiu("Sibiu");
	Node timisoara("Timisoara");
	Node zerind("Zerind");
	Node oradea("Oradea");
	Node faragas("Faragas");
	Node rimnicu_vilcea("Rimnicu Vilcea");
	Node pitesti("Pitesti");
	Node lugoj("Lugoj");
	Node mehadia("Mehadia");
	Node drobeta("Drobeta");
	Node craiova("Craiova");
	Node bucharest("Bucharest");
	Node giurgiu("Giurgiu");
	Node urziceni("Urziceni");
	Node hirsova("Hirsova");
	Node eforie("Eforie");
	Node vaslui("Vaslui");
	Node iasi("Iasi");
	Node neamt("Neamt");

	// Actions
	Action go("GO"), 
		go1("GO1"), 
		go2("GO2"), 
		go3("GO3"); // Since there are maximum 4 branching of "go" 
	
	// Model Transition
	arad.setAction(&go, &sibiu);
	arad.setAction(&go1, &zerind);
	arad.setAction(&go2, &timisoara);
	sibiu.setAction(&go, &arad);
	sibiu.setAction(&go1, &oradea);
	sibiu.setAction(&go2, &faragas);
	sibiu.setAction(&go3, &rimnicu_vilcea);
	zerind.setAction(&go, &arad);
	zerind.setAction(&go1, &oradea);
	timisoara.setAction(&go, &arad);
	timisoara.setAction(&go1, &lugoj);
	oradea.setAction(&go, &zerind);
	oradea.setAction(&go1, &sibiu);
	faragas.setAction(&go, &sibiu);
	faragas.setAction(&go1, &bucharest);
	rimnicu_vilcea.setAction(&go, &sibiu);
	rimnicu_vilcea.setAction(&go1, &pitesti);
	rimnicu_vilcea.setAction(&go2, &craiova);
	lugoj.setAction(&go, &timisoara);
	lugoj.setAction(&go1, &mehadia);
	bucharest.setAction(&go, &pitesti);
	bucharest.setAction(&go1, &faragas);
	bucharest.setAction(&go2, &urziceni);
	bucharest.setAction(&go3, &giurgiu);
	pitesti.setAction(&go, &rimnicu_vilcea);
	pitesti.setAction(&go1, &craiova);
	pitesti.setAction(&go2, &bucharest);
	craiova.setAction(&go, &drobeta);
	craiova.setAction(&go2, &rimnicu_vilcea);
	craiova.setAction(&go3, &pitesti);
	mehadia.setAction(&go, &lugoj);
	mehadia.setAction(&go1, &drobeta);
	urziceni.setAction(&go, &bucharest);
	urziceni.setAction(&go1, &hirsova);
	urziceni.setAction(&go2, &vaslui);
	giurgiu.setAction(&go, &bucharest);
	drobeta.setAction(&go, &mehadia);
	drobeta.setAction(&go1, &craiova);
	hirsova.setAction(&go, &urziceni);
	hirsova.setAction(&go1, &eforie);
	vaslui.setAction(&go, &urziceni);
	vaslui.setAction(&go1, &iasi);
	eforie.setAction(&go, &hirsova);
	iasi.setAction(&go, &vaslui);
	iasi.setAction(&go1, &neamt);
	neamt.setAction(&go, &iasi);

	// Problem
	Problem problem;
	problem.setStart(&arad);
	problem.setGoal(bucharest.getState());

	//Graph_BFS solver;
	Graph_DFS solver;
	Solution* solution = solver.Solve(&problem);

	std::cout << solution;

	return 0;
}