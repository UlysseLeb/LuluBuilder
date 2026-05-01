cmake_minimum_required(VERSION 3.22)
project(LuluBuilder VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(/Users/ulysselebigre/JUCE JUCE)

juce_add_plugin(LuluBuilder
    COMPANY_NAME            "LuluPlug"
    PLUGIN_MANUFACTURER_CODE Llpl
    PLUGIN_CODE             Lulb
    FORMATS                 VST3 AU
    PRODUCT_NAME            "LuluBuilder"
    BUNDLE_ID               "com.LuluPlug.LuluBuilder"
    IS_SYNTH                FALSE
    NEEDS_MIDI_INPUT        FALSE
    NEEDS_MIDI_OUTPUT       FALSE
    IS_MIDI_EFFECT          FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    VST3_CATEGORIES         "Fx" "Analyzer"
    AU_MAIN_TYPE            kAudioUnitType_Effect
)

target_sources(LuluBuilder PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
    Source/DSP/AudioFeatureExtractor.cpp
    Source/ML/ONNXClassifier.cpp
    Source/ML/StructurePredictor.cpp
    Source/UI/StructureDisplay.cpp
)

juce_generate_juce_header(LuluBuilder)

target_include_directories(LuluBuilder PRIVATE Source)

target_compile_definitions(LuluBuilder PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(LuluBuilder PRIVATE
    juce::juce_audio_processors
    juce::juce_audio_utils
    juce::juce_dsp
    juce::juce_gui_basics
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags
)
