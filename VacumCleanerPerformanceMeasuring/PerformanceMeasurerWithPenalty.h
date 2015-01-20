#pragma once
#include "PerformanceMeasurer.h"

class PerformanceMeasurerWithPenalty :
	public PerformanceMeasurer
{
public:
	PerformanceMeasurerWithPenalty();
	int measure(Agent*, Environtment*, int); // measure by timestep
	~PerformanceMeasurerWithPenalty();
};

