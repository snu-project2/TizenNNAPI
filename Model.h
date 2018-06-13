#include "Memory.h"
#include <vector>

class Operand{
	ANeuralNetworksOperandType type;
};

class Operation{
	ANeuralNetworksOperationType type;
	vector<int> inputs; //input operand indexes at model.operands
	vector<int> outputs;
};

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
