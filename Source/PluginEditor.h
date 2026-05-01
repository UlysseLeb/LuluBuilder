#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/StructureDisplay.h"

class LuluBuilderEditor : public juce::AudioProcessorEditor,
                          private juce::Timer
{
public:
    explicit LuluBuilderEditor(LuluBuilderProcessor&);
    ~LuluBuilderEditor() override = default;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    // Appelé toutes les 200ms pour rafraîchir l'affichage
    void timerCallback() override;

    LuluBuilderProcessor& luluProcessor;
    StructureDisplay      sectionDisplay;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LuluBuilderEditor)
};
