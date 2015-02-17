#include "IDS.h"


IDS::IDS()
{

}


IDS::~IDS()
{

}

Solution* IDS::Solve(Problem* problem)
{
	for (int depth = 0; depth < max_depth; depth++)
	{
		Solution* result = Recursive_DLS::Solve(problem, depth);
		if (result != cutOff) return result;
	}

	return 0;
}
