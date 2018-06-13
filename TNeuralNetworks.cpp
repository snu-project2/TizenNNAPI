#include <sys/mman.h>
#include "TNeuralNetworks.h"

void* TNeuralNetworksMemoryCreate(TNeuralNetworkModel *model, size_t size, int protect, int fd, size_t offset){
	mmap(model->mappedMemory, size, protect, MAP_SHARED, fd, offset);
}

int TNeuralNetworksModel_create(TNeuralNetworksModel **model){
	model* = (TNeuralNetworksModel*) malloc(sizeof(TNeuralNetworksModel));
	return TNEURALNETWORKS_NO_ERROR;	
}
int TNeuralNetworksModel_finish(TNeuralNetworksModel *model){
	return TNEURALNETWORKS_NO_ERROR;	
}
void TNeuralNetworksModel_free(TNeuralNetworksModel *model){
	free(model);
}
int TNeuralNetworksModel_identifyInputsAndOutputs(TNeuralNetworksModel *model, uint32_t inputCount, const uint32_t *inputs, uint32_t outputCount, const uint32_t *outputs){}
int TNeuralNetworksModel_addOperand(TNeuralNetworksModel *model, const TNeuralNetworksOperandType *type{}
int TNeuralNetworksModel_addOperation(TNeuralNetworksModel *model, TNeuralNetworksOperationType type, uint32_t inputCount, const uint32_t *inputs, uint32_t outputCount, const uint32_t *outputs){}
int TNeuralNetworksCompilation_create(TNeuralNetworksModel *model, TNeuralNetworksCompilation **compilation){}
int TNeuralNetworksCompilation_finish(TNeuralNetworksCompilation *compilation){}
void TNeuralNetworksCompilation_free(TNeuralNetworksCompilation *compilation){}
void TNeuralNetworksMemory_free(TNeuralNetworksMemory *memory)
int TNeuralNetworksMemory_createFromFd(size_t size, int protect, int fd, size_t offset, TNeuralNetworksMemory **memory)
int TNeuralNetworksExecution_create(TNeuralNetworksCompilation *compilation, TNeuralNetworksExecution **execution)
void TNeuralNetworksExecution_free(TNeuralNetworksExecution *execution)
int TNeuralNetworksExecution_setInput(TNeuralNetworksExecution *execution, int32_t index, const TNeuralNetworksOperandType *type, const void *buffer, size_t length)
int TNeuralNetworksExecution_setOutput(TNeuralNetworksExecution *execution, int32_t index, const TNeuralNetworksOperandType *type, void *buffer, size_t length)
int TNeuralNetworksExecution_startCompute(TNeuralNetworksExecution *execution, TNeuralNetworksEvent **event)
int TNeuralNetworksEvent_wait(TNeuralNetworksEvent *event)
void TNeuralNetworksEvent_free(TNeuralNetworksEvent *event)
int TNeuralNetworksExecution_setInputFromMemory( TNeuralNetworksExecution *execution, int32_t index, const TNeuralNetworksOperandType *type, const TNeuralNetworksMemory *memory, size_t offset, size_t length){
	if(memory == 0)
		return 0;
	memcpy((void*)(execution->inputs + index), (void*)(memory->mappedmemory + offset), length);
		return 1;
}
int TNeuralNetworksExecution_setOutputFromMemory(TNeuralNetworksExecution *execution, int32_t index, const TNeuralNetworksOperandType *type, const TNeuralNetworksMemory *memory, size_t offset, size_t length){
	if(memory == 0)
		return 0;
	memcpy((void*)(memory->mappedmemory + offset), (void*)(execution->outputs + index), length);
		return 1;
}

