#include <sys/mman.h>
class TNeuralNetworksModel{
}
class TNeuralNetworksCompilation {
	public:
			
	private:
}

class TNeuralNetworksMemory {
	public:
		TNeuralNetworksMemory(size_t size, int protect, int fd, size_t offset){
			mmap(mappedMemory, size, protect, MAP_SHARED, fd, offset);
		}

	private:
		void* mappedMemory;
		
};
class TNeuralNetworksExecution {
	public:
	private:
};
class TNeuralNetworksEvent {
	public:
	private:
};

TNeuralNetworksModel_create(TNeuralNetworksModel **model)
TNeuralNetworksModel_finish(TNeuralNetworksModel *model)
TNeuralNetworksModel_free(TNeuralNetworksModel *model)
TNeuralNetworksModel_identifyInputsAndOutputs(TNeuralNetworksModel *model, uint32_t inputCount, const uint32_t *inputs, uint32_t outputCount, const uint32_t *outputs)
TNeuralNetworksModel_addOperand(TNeuralNetworksModel *model, const TNeuralNetworksOperandType *type)
TNeuralNetworksModel_addOperation(TNeuralNetworksModel *model, TNeuralNetworksOperationType type, uint32_t inputCount, const uint32_t *inputs, uint32_t outputCount, const uint32_t *outputs)


TNeuralNetworksCompilation_create(TNeuralNetworksModel *model, TNeuralNetworksCompilation **compilation)
TNeuralNetworksCompilation_finish(TNeuralNetworksCompilation *compilation)
TNeuralNetworksCompilation_free(TNeuralNetworksCompilation *compilation)

TNeuralNetworksMemory_free(TNeuralNetworksMemory *memory)
TNeuralNetworksMemory_createFromFd(size_t size, int protect, int fd, size_t offset, TNeuralNetworksMemory **memory)

TNeuralNetworksExecution_create(TNeuralNetworksCompilation *compilation, TNeuralNetworksExecution **execution)
TNeuralNetworksExecution_free(TNeuralNetworksExecution *execution)
TNeuralNetworksExecution_setInput(TNeuralNetworksExecution *execution, int32_t index, const TNeuralNetworksOperandType *type, const void *buffer, size_t length)
TNeuralNetworksExecution_setOutput(TNeuralNetworksExecution *execution, int32_t index, const TNeuralNetworksOperandType *type, void *buffer, size_t length)
TNeuralNetworksExecution_startCompute(TNeuralNetworksExecution *execution, TNeuralNetworksEvent **event)

TNeuralNetworksEvent_wait(TNeuralNetworksEvent *event)
TNeuralNetworksEvent_free(TNeuralNetworksEvent *event)
