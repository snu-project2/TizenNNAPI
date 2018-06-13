#include "Memory.h"
#include <sys/mman.h>

int ANeuralNetworksMemory_createFromFd(size_t size, int protect, int fd, size_t offset, ANeuralNetworksMemory **memory){
	memory = new Memory();
	void* buf = mmap(0, size, protect, MAP_SHARED, fd, offset);
	(*memory)->buffer = static_cast<uint8_t>(buf);
	return ANEURALNETWORKS_NO_ERROR;
}

void ANduralNetworksMemory_free(ANeuralNetworksMemory *memory){
	munmap(memory->buffer, memory.getSize());
} 


