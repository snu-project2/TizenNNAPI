#include "NeuralNetworks.h"
#include "Model.h"

#include <stdlib.h>
#include <vector>

using namespace android;

class Execution{
public:
    Execution(){}
    ~Execution();

    int create(Compilation* compilation, Execution** execution);
    void free(Execution* execution);
    int setInput(Execution* execution, int32_t index,
                 const OperandType* type, const void* buffer,
                 size_t length);
    int setInputFromMemory(Execution* execution, int32_t index,
                           const OperandType* type, const Memory* memory,
                           size_t offset, size_t length);
    int setOutput(Execution* execution, int32_t index,
                  const OperandType, void* buffer, size_t length);
    int setOutputFromMemory(Execution* execution, int32_t index, const OperandType* type,
                            const Memory* memory, size_t offset, size_t length);
    int startCompute(Execution* execution, Event** event);

private:
    const Model* mModel;
    std::vector<Model> mInputs;
    std::vector<Model> mOutputs;
}