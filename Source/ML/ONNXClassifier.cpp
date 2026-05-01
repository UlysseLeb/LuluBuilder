#include "ONNXClassifier.h"

bool ONNXClassifier::loadModel(const std::string& /*modelPath*/)
{
    // Stub : ONNX Runtime sera initialisé ici
    modelLoaded = false;
    return false;
}

int ONNXClassifier::predict(const std::vector<float>& /*features*/) const
{
    if (!modelLoaded)
        return -1;

    return 0; // placeholder
}
