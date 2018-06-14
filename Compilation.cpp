
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
