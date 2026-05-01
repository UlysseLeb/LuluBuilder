#include "PluginProcessor.h"
#include "PluginEditor.h"

LuluBuilderProcessor::LuluBuilderProcessor()
    : AudioProcessor(BusesProperties()
        .withInput("Input",  juce::AudioChannelSet::stereo(), true)
        .withOutput("Output", juce::AudioChannelSet::stereo(), true))
{
}

void LuluBuilderProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    analysisIntervalSamples = static_cast<int>(sampleRate * analysisIntervalSeconds);
    samplesSinceLastAnalysis = 0;

    // 2 secondes de buffer audio suffisent pour l'extraction de features
    audioBuffer.resize(static_cast<int>(sampleRate * 2.0));
    featureExtractor.prepare(sampleRate, samplesPerBlock);
}

void LuluBuilderProcessor::releaseResources()
{
}

void LuluBuilderProcessor::processBlock(juce::AudioBuffer<float>& buffer,
                                        juce::MidiBuffer&)
{
    juce::ScopedNoDenormals noDenormals;

    // On travaille sur le canal gauche (ou le seul canal dispo)
    const float* channelData = buffer.getReadPointer(0);
    const int numSamples = buffer.getNumSamples();

    audioBuffer.write(channelData, numSamples);
    samplesSinceLastAnalysis += numSamples;

    if (samplesSinceLastAnalysis >= analysisIntervalSamples)
    {
        samplesSinceLastAnalysis = 0;

        auto features = featureExtractor.extract(audioBuffer);
        predictor.update(features);
    }
}

StructurePredictor::Section LuluBuilderProcessor::getCurrentSection() const
{
    return predictor.currentSection();
}

juce::AudioProcessorEditor* LuluBuilderProcessor::createEditor()
{
    return new LuluBuilderEditor(*this);
}

void LuluBuilderProcessor::getStateInformation(juce::MemoryBlock&)
{
    // Pas de paramètres à sauvegarder pour l'instant
}

void LuluBuilderProcessor::setStateInformation(const void*, int)
{
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new LuluBuilderProcessor();
}
