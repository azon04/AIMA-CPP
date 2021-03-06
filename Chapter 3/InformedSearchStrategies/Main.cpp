#include "Greedy_BestFirstSearch.h"
#include "A_star.h"
#include "RBFS.h"

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
	arad.setAction(&go, &sibiu, 140);
	arad.setAction(&go1, &zerind, 75);
	arad.setAction(&go2, &timisoara, 118);
	sibiu.setAction(&go, &arad, 140);
	sibiu.setAction(&go1, &oradea, 151);
	sibiu.setAction(&go2, &faragas, 99);
	sibiu.setAction(&go3, &rimnicu_vilcea, 80);
	zerind.setAction(&go, &arad, 75);
	zerind.setAction(&go1, &oradea, 71);
	timisoara.setAction(&go, &arad, 118);
	timisoara.setAction(&go1, &lugoj, 111);
	oradea.setAction(&go, &zerind, 71);
	oradea.setAction(&go1, &sibiu, 151);
	faragas.setAction(&go, &sibiu, 99);
	faragas.setAction(&go1, &bucharest, 211);
	rimnicu_vilcea.setAction(&go, &sibiu, 80);
	rimnicu_vilcea.setAction(&go1, &pitesti, 97);
	rimnicu_vilcea.setAction(&go2, &craiova, 146);
	lugoj.setAction(&go, &timisoara, 111);
	lugoj.setAction(&go1, &mehadia, 70);
	bucharest.setAction(&go, &pitesti, 101);
	bucharest.setAction(&go1, &faragas, 211);
	bucharest.setAction(&go2, &urziceni, 85);
	bucharest.setAction(&go3, &giurgiu, 90);
	pitesti.setAction(&go, &rimnicu_vilcea, 97);
	pitesti.setAction(&go1, &craiova, 138);
	pitesti.setAction(&go2, &bucharest, 101);
	craiova.setAction(&go, &drobeta, 120);
	craiova.setAction(&go2, &rimnicu_vilcea, 146);
	craiova.setAction(&go3, &pitesti, 138);
	mehadia.setAction(&go, &lugoj, 70);
	mehadia.setAction(&go1, &drobeta, 75);
	urziceni.setAction(&go, &bucharest, 85);
	urziceni.setAction(&go1, &hirsova, 98);
	urziceni.setAction(&go2, &vaslui, 142);
	giurgiu.setAction(&go, &bucharest, 90);
	drobeta.setAction(&go, &mehadia, 75);
	drobeta.setAction(&go1, &craiova, 120);
	hirsova.setAction(&go, &urziceni, 98);
	hirsova.setAction(&go1, &eforie, 86);
	vaslui.setAction(&go, &urziceni, 142);
	vaslui.setAction(&go1, &iasi, 92);
	eforie.setAction(&go, &hirsova, 86);
	iasi.setAction(&go, &vaslui, 92);
	iasi.setAction(&go1, &neamt, 87);
	neamt.setAction(&go, &iasi, 87);

	// Heuristic
	HeuristicTableEvaluation table;
	table.add(&arad, 366);
	table.add(&bucharest, 0);
	table.add(&craiova, 160);
	table.add(&drobeta, 242);
	table.add(&eforie, 161);
	table.add(&faragas, 176);
	table.add(&giurgiu, 77);
	table.add(&hirsova, 151);
	table.add(&iasi, 226);
	table.add(&lugoj, 244);
	table.add(&mehadia, 241);
	table.add(&neamt, 234);
	table.add(&oradea, 380);
	table.add(&pitesti, 100);
	table.add(&rimnicu_vilcea, 193);
	table.add(&sibiu, 253);
	table.add(&timisoara, 329);
	table.add(&urziceni, 80);
	table.add(&vaslui, 199);
	table.add(&zerind, 374);

	// Problem
	Problem problem;
	problem.setStart(&arad);
	problem.setGoal(bucharest.getState());

	A_star solver;
	solver.setHeuristic(&table);
	Solution* solution = solver.Solve(&problem);

	if (solution)
		std::cout << solution << std::endl;
	else
		std::cout << "No Solution Found" << std::endl;

	return 0;
}