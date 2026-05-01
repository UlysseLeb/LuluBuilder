#pragma once

#include <JuceHeader.h>
#include "DSP/RingBuffer.h"
#include "DSP/AudioFeatureExtractor.h"
#include "ML/StructurePredictor.h"

class LuluBuilderProcessor : public juce::AudioProcessor
{
public:
    LuluBuilderProcessor();
    ~LuluBuilderProcessor() override = default;

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    const juce::String getName() const override { return "LuluBuilder"; }
    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return false; }
    double getTailLengthSeconds() const override { return 0.0; }

    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int) override {}
    const juce::String getProgramName(int) override { return "Default"; }
    void changeProgramName(int, const juce::String&) override {}

    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    // L'éditeur lit cette valeur pour afficher la section courante
    StructurePredictor::Section getCurrentSection() const;

private:
    RingBuffer<float>        audioBuffer;
    AudioFeatureExtractor    featureExtractor;
    StructurePredictor       predictor;

    // Compte les samples pour déclencher l'analyse à intervalle fixe
    int samplesSinceLastAnalysis = 0;
    int analysisIntervalSamples  = 0;

    static constexpr double analysisIntervalSeconds = 0.5;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LuluBuilderProcessor)
};
