#include "PerformanceMeasurer.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, Environtment& env) {
	for (int y = 0; y < env.getHeight(); y++) {
		for (int x = 0; x < env.getWidth(); x++)
			os << (env(x,y) == true ? "1" : "0") << "\t";
		os << endl;
	}

	return os;
}

PerformanceMeasurer::PerformanceMeasurer()
{
}

int PerformanceMeasurer::measure(Agent* agent, Environtment* env, int timestep) // measure by timestep
{
	int result = 0;

	cout << "Before : " << endl << (*env) << endl;
	while (timestep--)
	{
		agent->run();
		
		for (int y = 0; y < env->getHeight(); y++) {
			for (int x = 0; x < env->getWidth(); x++) {
				if ((*env)(x,y) == false)
					result++;
			}
		}
		
		env->change();
	}
	cout << "After : " << endl << (*env) << endl;

	return result;
}

PerformanceMeasurer::~PerformanceMeasurer()      
{
}
