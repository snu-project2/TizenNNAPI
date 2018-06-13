#include "NeuralNetworks.h"

using namespace::android;



class Compilation{
public:
    Compilation(){}
    ~Compilation();

    int create(Model* model, Compilation** compilation);
    int setPreference(Compilation* compilation, int32_t preference);
    int finish(Compilation* compilation);
    void free(Compilation* compilation);

private:
    const Model* mModel;
    int32_t mPreference = ANEURALNETWORKS_PREFER_FAST_SINGLE_ANSWER;
    bool mFinished = false;
};
