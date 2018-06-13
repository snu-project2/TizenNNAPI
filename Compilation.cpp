
#include "Compilation.h"

Compilation::Compilation(const Model* model) :
    mModel(model) {
    }

int Compilation::create(Model* model, Compilation* compilation) {
    if (!mFinished) {
        *execution = nullptr;
        return ANEURALNETWORKS_BAD_STATE;
    }
    *compilation = new Compilation(*model);
    return (*compilation ? ANEURALNETWORKS_NO_ERROR : ANEURALNETWORKS_OUT_OF_MEMORY);
}

int Compilation::setPreference(int32_t preference) {
    if (mFinished) {
        return ANEURALNETWORKS_BAD_STATE;
    }
    if (preference >= kNumberOfPreferences) {
        return ANEURALNETWORKS_BAD_DATA;
    }

    mPreference = preference;
    return ANEURALNETWORKS_NO_ERROR;
}

int Compilation::finish() {
    if (mFinished) {
        return ANEURALNETWORKS_BAD_STATE;
    }

    mFinished = true;

    return ANEURALNETWORKS_NO_ERROR;
}

void Compilation::free() {

    delete this;
}















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