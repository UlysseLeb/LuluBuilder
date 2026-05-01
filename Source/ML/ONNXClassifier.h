#pragma once

#include <vector>
#include <string>

// Stub — wrappera ONNX Runtime quand la lib sera installée.
// Interface volontairement simple : on passe des features, on reçoit un index de classe.
class ONNXClassifier
{
public:
    bool loadModel(const std::string& modelPath);

    // Retourne l'index de la classe prédite, ou -1 si le modèle n'est pas chargé.
    int predict(const std::vector<float>& features) const;

    bool isLoaded() const { return modelLoaded; }

private:
    bool modelLoaded = false;
};
