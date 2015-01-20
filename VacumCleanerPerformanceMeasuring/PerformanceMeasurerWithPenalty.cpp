#include "PerformanceMeasurerWithPenalty.h"
#include "Actuator.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, Environtment& env);

PerformanceMeasurerWithPenalty::PerformanceMeasurerWithPenalty()
{
}

int PerformanceMeasurerWithPenalty::measure(Agent* agent, Environtment* env, int timestep) // measure by timestep
{
	int result = 0;

	cout << "Before : " << endl << (*env) << endl;
	while (timestep--)
	{
		int resultAction = agent->run();

		if (resultAction == ACTUATOR_ACTION_MOVE) {
			result--;
		}

		for (int y = 0; y < env->getHeight(); y++) {
			for (int x = 0; x < env->getWidth(); x++) {
				if ((*env)(x, y) == false)
					result++;
			}
		}

	}
	cout << "After : " << endl << (*env) << endl;

	return result;
}


PerformanceMeasurerWithPenalty::~PerformanceMeasurerWithPenalty()
{
}
