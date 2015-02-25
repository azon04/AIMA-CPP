#include "Problem.h"

class PositionState : public State {
public:
	PositionState(int x, int y);
	~PositionState();
	int compareTo(const PositionState& state);
	std::string toString();
private:
	int x;
	int y;
};

int main() {

	Node s(PositionState(4, 5));
	Node trans[] = {
		{ PositionState(4, 13) }, // 0
		{ PositionState(20, 13) }, // 1
		{ PositionState(35, 13) }, // 2
		{ PositionState(28, 35) }, // 3
		{ PositionState(33, 22) }, // 4
		{ PositionState(46, 29) }, // 5
		{ PositionState(41, 13) }, // 6
		{ PositionState(47, 16) }, // 7
		{ PositionState(43, 1) }, // 8
		{ PositionState(52, 12) }, // 9
		{ PositionState(65, 18) }, // 10
		{ PositionState(63, 35) }, // 11
		{ PositionState(69, 40) }, // 12
		{ PositionState(74, 10) }, // 13
	};
	Node g(PositionState(75, 38));
	
	return 0;
}