#include "Model.h"

int ANeuralNetworksModel_create(ANeuralNetworksModel **model){
	*model = new Model();
	return ANEURALNETWORKS_NO_ERROR;
}
int ANeuralNetworksModel_finish(ANeuralNetworksModel *model){
	model->isFinished = true;
	return ANEURALNETWORKS_NO_ERROR;
}
void ANeuralNetworksModel_free(ANeuralNetworksModel *model){
	model->~Model();
}

int ANeuralNetworksModel_identifyInputsAndOutputs(ANeuralNetworksModel *model, uint32_t inputCount, const uint32_t *inputs, uint32_t outputCount, const uint32_t *outputs){
	model->inputIndexes.resize(inputCount);
	for (uint32_t i = 0; i < inputCount; i++) {
		const uint32_t operandIndex = inputs[i];
		model->inputIndexes[i] = operandIndex;
	}
	for (uint32_t i = 0; i < outputCount; i++) {
		const uint32_t operandIndex = outputs[i];
		model->outputIndexes[i] = operandIndex;
	}
	return ANEURALNETWORKS_NO_ERROR;
}
int ANeuralNetworksModel_addOperand(ANeuralNetworksModel *model, const ANeuralNetworksOperandType *type){
	Operand operand = new Operand();
	operand.type = type;
	model->Operands.push_back(operand);
	return ANEURALNETWORKS_NO_ERROR;
}
int ANeuralNetworksModel_addOperation(ANeuralNetworksModel *model, ANeuralNetworksOperationType type, uint32_t inputCount, const uint32_t *inputs, uint32_t outputCount, const uint32_t *outputs){
	
}
