#include "StructureDisplay.h"

StructureDisplay::StructureDisplay()
    : labelFont(juce::FontOptions(48.0f).withStyle("Bold"))
{
}

void StructureDisplay::setSection(StructurePredictor::Section newSection)
{
    if (newSection != section)
    {
        section = newSection;
        repaint();
    }
}

void StructureDisplay::paint(juce::Graphics& g)
{
    const char* label = StructurePredictor::sectionName(section);

    g.setFont(labelFont);
    g.setColour(juce::Colours::white.withAlpha(section == StructurePredictor::Section::Unknown ? 0.3f : 1.0f));
    g.drawText(label, getLocalBounds(), juce::Justification::centred, false);
}
