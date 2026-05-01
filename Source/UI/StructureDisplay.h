#pragma once

#include <JuceHeader.h>
#include "ML/StructurePredictor.h"

// Composant qui affiche le nom de la section courante au centre de la fenêtre.
class StructureDisplay : public juce::Component
{
public:
    StructureDisplay();

    void setSection(StructurePredictor::Section newSection);
    void paint(juce::Graphics&) override;

private:
    StructurePredictor::Section section = StructurePredictor::Section::Unknown;

    juce::Font labelFont;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(StructureDisplay)
};
