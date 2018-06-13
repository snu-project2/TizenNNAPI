#include "NeuralNetworks.h"

using namespace::android;


class Memory{
public:
	Memory(){}
	~Memory();
	uint8_t* buffer;
	size_t getSize();
private:
	size_t size;
};

Memory::getSize(){
	return size;
}
