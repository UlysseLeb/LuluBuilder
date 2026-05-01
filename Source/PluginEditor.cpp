#include "PluginEditor.h"

LuluBuilderEditor::LuluBuilderEditor(LuluBuilderProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{
    addAndMakeVisible(sectionDisplay);
    setSize(400, 300);
    startTimerHz(5); // 5 rafraîchissements par seconde
}

void LuluBuilderEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(0xff1a1a2e));
}

void LuluBuilderEditor::resized()
{
    sectionDisplay.setBounds(getLocalBounds());
}

void LuluBuilderEditor::timerCallback()
{
    sectionDisplay.setSection(processor.getCurrentSection());
}
