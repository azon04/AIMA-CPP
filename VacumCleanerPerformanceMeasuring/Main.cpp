#include "Environtment.h"
#include "RandomizedReflexAgentState.h"
#include "Sensor.h"
#include "Actuator.h"
#include "PerformanceMeasurerWithPenalty.h"
#include <iostream>

using namespace std;


int main() {
	Environtment env(5,5);
	RandomizedReflexAgentState agent;
	Sensor sensor;
	Actuator actuator;
	PerformanceMeasurer measurer;

	// Agent Configuration
	agent.setSensor(&sensor);
	agent.setActuator(&actuator);
	agent.setX(2);
	agent.setY(2);

	// Environtment Configuration
	bool config_env[25] = { 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1
	};
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			env.setDirt(x, y, config_env[5*y + x]);
		}
	}

	agent.setEnv(&env);
	
	cout << "Score : " << measurer.measure(&agent, &env, 100);

	return 0;
}