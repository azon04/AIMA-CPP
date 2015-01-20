#pragma once
#include "Agent.h"
#include "Environtment.h"

#ifndef _CLASS_PERFORMANCE_MEASURER_
class PerformanceMeasurer
{
public:
	PerformanceMeasurer();
	virtual int measure(Agent*, Environtment*,int); // measure by timestep
	~PerformanceMeasurer();
};
#endif

