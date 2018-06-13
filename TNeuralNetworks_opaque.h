#include <sys/mman.h>
enum 39 {
  TNEURALNETWORKS_MAX_SIZE_OF_IMMEDIATELY_COPIED_VALUES = 128
}

enum FuseCode {
  TNEURALNETWORKS_FUSED_NONE = 0,
  TNEURALNETWORKS_FUSED_RELU = 1,
  TNEURALNETWORKS_FUSED_RELU1 = 2,
  TNEURALNETWORKS_FUSED_RELU6 = 3
}

enum OperandType{
  FLOAT32 = 0,
  INT32 = 1,
  UINT32 = 2,
  TENSOR_FLOAT32 = 3,
  TENSOR_INT32 = 4,
  TENSOR_QUANT8_ASYMM = 5
}

enum OperationType{
  ADD = 0,
  AVERAGE_POOL_2D = 1,
  CONCATENATION = 2,
  CONV_2D = 3,
  DEPTHWISE_CONV_2D = 4,
  DEPTH_TO_SPACE = 5,
  DEQUANTIZE = 6,
  EMBEDDING_LOOKUP = 7,
  FLOOR = 8,
  FULLY_CONNECTED = 9,
  HASHTABLE_LOOKUP = 10,
  L2_NORMALIZATION = 11,
  L2_POOL_2D = 12,
  LOCAL_RESPONSE_NORMALIZATION = 13,
  LOGISTIC = 14,
  LSH_PROJECTION = 15,
  LSTM = 16,
  MAX_POOL_2D = 17,
  MUL = 18,
  RELU = 19,
  RELU1 = 20,
  RELU6 = 21,
  RESHAPE = 22,
  RESIZE_BILINEAR = 23,
  RNN = 24,
  SOFTMAX = 25,
  SPACE_TO_DEPTH = 26,
  SVDF = 27,
  TANH = 28,
  BATCH_TO_SPACE_ND = 29,
  DIV = 30,
  MEAN = 31,
  PAD = 32,
  SPACE_TO_BATCH_ND = 33,
  SQUEEZE = 34,
  STRIDED_SLICE = 35,
  SUB = 36,
  TRANSPOSE = 37
}

enum PaddingCode{
  TNEURALNETWORKS_PADDING_SAME = 1,
  TNEURALNETWORKS_PADDING_VALID = 2
}

enum PreferenceCode{
  TNEURALNETWORKS_PREFER_LOW_POWER = 0,
  TNEURALNETWORKS_PREFER_FAST_SINGLE_ANSWER = 1,
  TNEURALNETWORKS_PREFER_SUSTAINED_SPEED = 2
}

enum ResultCode{
  TNEURALNETWORKS_NO_ERROR = 0,
  TNEURALNETWORKS_OUT_OF_MEMORY = 1,
  TNEURALNETWORKS_INCOMPLETE = 2,
  TNEURALNETWORKS_UNEXPECTED_NULL = 3,
  TNEURALNETWORKS_BAD_DATA = 4,
  TNEURALNETWORKS_OP_FAILED = 5,
  TNEURALNETWORKS_BAD_STATE = 6,
  TNEURALNETWORKS_UNMAPPABLE = 7
}



int32_t TNeuralNetworksOperationType;

struct TNeuralNetworksModel{
	void** pools;
	vector<struct Operand> operands;
	vector<int> inputIndexes;
	vector<int> outputIndexes;
	vector<struct Operation> operations;
	vector<int> operandValues;
		
}
struct TNeuralNetworksCompilation {
}

struct TNeuralNetworksMemory {
	void* TNeuralNetworksMemory;
	void* mappedMemory;
		
};
struct TNeuralNetworksExecution {
};
struct TNeuralNetworksEvent {
};

struct Operation {
	struct OperationType type;
	vector<int> inputs; //input operand indexes at model.operands
	vector<int> outputs;
}

struct Operand {
	struct OperandType type;
	vector<void*> location;
}


int TNeuralNetworksModel_create(TNeuralNetworksModel **model)
int TNeuralNetworksModel_finish(TNeuralNetworksModel *model)
void TNeuralNetworksModel_free(TNeuralNetworksModel *model)
int TNeuralNetworksModel_identifyInputsAndOutputs(TNeuralNetworksModel *model, uint32_t inputCount, const uint32_t *inputs, uint32_t outputCount, const uint32_t *outputs)
int TNeuralNetworksModel_addOperand(TNeuralNetworksModel *model, const TNeuralNetworksOperandType *type)
int TNeuralNetworksModel_addOperation(TNeuralNetworksModel *model, TNeuralNetworksOperationType type, uint32_t inputCount, const uint32_t *inputs, uint32_t outputCount, const uint32_t *outputs)


int TNeuralNetworksCompilation_create(TNeuralNetworksModel *model, TNeuralNetworksCompilation **compilation)
int TNeuralNetworksCompilation_finish(TNeuralNetworksCompilation *compilation)
void TNeuralNetworksCompilation_free(TNeuralNetworksCompilation *compilation)


void TNeuralNetworksMemory_free(TNeuralNetworksMemory *memory)
int TNeuralNetworksMemory_createFromFd(size_t size, int protect, int fd, size_t offset, TNeuralNetworksMemory **memory)


int TNeuralNetworksExecution_create(TNeuralNetworksCompilation *compilation, TNeuralNetworksExecution **execution)
void TNeuralNetworksExecution_free(TNeuralNetworksExecution *execution)
int TNeuralNetworksExecution_startCompute(TNeuralNetworksExecution *execution, TNeuralNetworksEvent **event)
int TNeuralNetworksExecution_setInput(TNeuralNetworksExecution *execution, int32_t index, const TNeuralNetworksOperandType *type, const void *buffer, size_t length)
int TNeuralNetworksExecution_setOutput(TNeuralNetworksExecution *execution, int32_t index, const TNeuralNetworksOperandType *type, void *buffer, size_t length)
int TNeuralNetworksExecution_setInputFromMemory( TNeuralNetworksExecution *execution, int32_t index, const TNeuralNetworksOperandType *type, const TNeuralNetworksMemory *memory, size_t offset, size_t length)
int TNeuralNetworksExecution_setOutputFromMemory(TNeuralNetworksExecution *execution, int32_t index, const TNeuralNetworksOperandType *type, const TNeuralNetworksMemory *memory, size_t offset, size_t length)


int TNeuralNetworksEvent_wait(TNeuralNetworksEvent *event)
void NeuralNetworksEvent_free(TNeuralNetworksEvent *event)
