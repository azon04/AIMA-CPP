#include "Graph_BFS.h"

int main()
{
	/* road map Romania Problem */
	Node arad;
	arad.state = "Arad";
	arad.numAction = 0;

	Node sibiu;
	sibiu.state = "Sibiu";
	sibiu.numAction = 0;

	Node timisoara;
	timisoara.state = "Timisoara";

	Node zerind;
	zerind.state = "Zerind";

	Node oradea;
	oradea.state = "Oradea";

	Node faragas;
	faragas.state = "Faragas";

	Node rimnicu_vilcea;
	rimnicu_vilcea.state = "Rimnicu Vilcea";

	Node pitesti;
	pitesti.state = "Pitesti";

	Node lugoj;
	lugoj.state = "Lugoj";

	Node mehadia;
	mehadia.state = "Mehadia";

	Node drobeta;
	drobeta.state = "Drobeta";

	Node craiova;
	craiova.state = "Craiova";

	Node bucharest;
	bucharest.state = "Bucharest";

	Node giurgiu;
	giurgiu.state = "Giurgiu";

	Node urziceni;
	urziceni.state = "Urziceni";

	Node hirsova;
	hirsova.state = "Hirsova";

	Node eforie;
	eforie.state = "Eforie";

	Node vaslui;
	vaslui.state = "Vaslui";

	Node iasi;
	iasi.state = "Iasi";

	Node neamt;
	neamt.state = "Neamt";

	ActionAddress aradToSibiu;
	GenerateAction(&aradToSibiu, "Arad to Sibiu",  (NodeAddress) &sibiu);
	AddAction( (NodeAddress) &arad, aradToSibiu);

	ActionAddress sibiuToArad;
	GenerateAction(&sibiuToArad, "Sibiu to Arad", (NodeAddress)&arad);
	AddAction((NodeAddress)&sibiu, sibiuToArad);

	free(aradToSibiu);
	free(sibiuToArad);
	return 0;
}