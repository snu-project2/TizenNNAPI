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
	if(inputCount > inputs
	model->inputIndexes.resize(inputCount);
}
int ANeuralNetworksModel_addOperand(ANeuralNetworksModel *model, const ANeuralNetworksOperandType *type)
int ANeuralNetworksModel_addOperation(ANeuralNetworksModel *model, ANeuralNetworksOperationType type, uint32_t inputCount, const uint32_t *inputs, uint32_t outputCount, const uint32_t *outputs)
