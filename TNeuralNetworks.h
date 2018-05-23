#include <sys/mman.h>
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

ANeuralNetworksCompilation_create(ANeuralNetworksModel *model, ANeuralNetworksCompilation **compilation)
ANeuralNetworksCompilation_finish(ANeuralNetworksCompilation *compilation)
ANeuralNetworksCompilation_free(ANeuralNetworksCompilation *compilation)

TNeuralNetworksMemory_free(TNeuralNetworksMemory *memory)
TNeuralNetworksMemory_createFromFd(size_t size, int protect, int fd, size_t offset, TNeuralNetworksMemory **memory)

TNeuralNetworksExecution_create(TNeuralNetworksCompilation *compilation, TNeuralNetworksExecution **execution)
TNeuralNetworksExecution_free(TNeuralNetworksExecution *execution)
TNeuralNetworksExecution_setInput(TNeuralNetworksExecution *execution, int32_t index, const TNeuralNetworksOperandType *type, const void *buffer, size_t length)
TNeuralNetworksExecution_setOutput(TNeuralNetworksExecution *execution, int32_t index, const TNeuralNetworksOperandType *type, void *buffer, size_t length)
TNeuralNetworksExecution_startCompute(TNeuralNetworksExecution *execution, TNeuralNetworksEvent **event)

TNeuralNetworksEvent_wait(TNeuralNetworksEvent *event)
TNeuralNetworksEvent_free(TNeuralNetworksEvent *event)
