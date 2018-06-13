#include "Memory.h"
#include <vector>

class Model{
public:
	Model():isFinished(false){}

        vector<struct Operand> operands;
        vector<int> inputIndexes;
        vector<int> outputIndexes;
        vector<struct Operation> operations;
        vector<int> operandValues;

	void** pools;
	bool isFinished;
};
