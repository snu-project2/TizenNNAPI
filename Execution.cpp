#include "Execution.h"

Execution::Execution(const Compilation compilation) :
    mModel(compilation->mModel),
    nInputs(mModel->inputcount()),
    mOutputs(mModel->outputCount()){}


int Execution::create(Compilation* compilation, Execution** execution){
    //TODO
    return ANEURALNETWORKS_NO_ERROR;
}
void Execution::free(Execution* execution){
    free(execution);
}
int Execution::setInput(Execution* execution, int32_t index,
                const OperandType* type, const void* buffer,
                size_t length){
    //TODO                
    return ANEURALNETWORKS_NO_ERROR;
}
int Execution::setInputFromMemory(Execution* execution, int32_t index,
                        const OperandType* type, const Memory* memory,
                        size_t offset, size_t length){
    //TODO
    return ANEURALNETWORKS_NO_ERROR;
}
int Execution::setOutput(Execution* execution, int32_t index,
                const OperandType, void* buffer, size_t length){
    //TODO
    return ANEURALNETWORKS_NO_ERROR;
}
int Execution::setOutputFromMemory(Execution* execution, int32_t index, const OperandType* type,
                        const Memory* memory, size_t offset, size_t length){
    //TODO
    return ANEURALNETWORKS_NO_ERROR;
}
int Execution::startCompute(Execution* execution, Event** event){
    //TODO
    return ANEURALNETWORKS_NO_ERROR;
}
