#include "AudioFeatureExtractor.h"

void AudioFeatureExtractor::prepare(double sr, int blockSize)
{
    sampleRate     = sr;
    samplesPerBlock = blockSize;
}

std::vector<float> AudioFeatureExtractor::extract(const RingBuffer<float>& /*buffer*/) const
{
    // Stub : retourne des features nulles jusqu'à l'intégration d'Essentia
    return std::vector<float>(featureCount, 0.0f);
}
