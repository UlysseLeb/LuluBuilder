#pragma once

#include <vector>
#include "RingBuffer.h"

// Stub — retourne un vecteur de zéros tant qu'Essentia n'est pas intégré.
// À terme : RMS, spectral centroid, MFCC, zero-crossing rate, etc.
class AudioFeatureExtractor
{
public:
    static constexpr int featureCount = 13; // identique à la dim d'entrée du modèle ONNX

    void prepare(double sampleRate, int samplesPerBlock);

    // Lit les derniers samples du buffer et retourne un vecteur de features normalisées.
    std::vector<float> extract(const RingBuffer<float>& buffer) const;

private:
    double sampleRate    = 44100.0;
    int    samplesPerBlock = 512;
};
