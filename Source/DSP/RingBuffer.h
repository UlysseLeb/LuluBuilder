#pragma once

#include <vector>
#include <algorithm>

// Buffer circulaire non thread-safe — à utiliser uniquement depuis l'audio thread.
// writePos avance modulo capacity ; read() copie les N derniers samples écrits.
template <typename SampleType>
class RingBuffer
{
public:
    void resize(int capacity)
    {
        data.assign(capacity, SampleType(0));
        writePos = 0;
    }

    void write(const SampleType* samples, int numSamples)
    {
        const int capacity = static_cast<int>(data.size());
        for (int i = 0; i < numSamples; ++i)
        {
            data[writePos] = samples[i];
            writePos = (writePos + 1) % capacity;
        }
    }

    // Copie les N derniers samples dans dest (du plus ancien au plus récent).
    void readLast(SampleType* dest, int numSamples) const
    {
        const int capacity = static_cast<int>(data.size());
        numSamples = std::min(numSamples, capacity);

        int readStart = (writePos - numSamples + capacity) % capacity;
        for (int i = 0; i < numSamples; ++i)
            dest[i] = data[(readStart + i) % capacity];
    }

    int size() const { return static_cast<int>(data.size()); }

private:
    std::vector<SampleType> data;
    int writePos = 0;
};
