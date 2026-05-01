#include "StructurePredictor.h"

static constexpr int sectionCount = 5; // Unknown + 4 sections

StructurePredictor::StructurePredictor()
{
    // Le modèle sera chargé ici quand ONNX Runtime sera intégré
    // classifier.loadModel("path/to/model.onnx");
}

void StructurePredictor::update(const std::vector<float>& features)
{
    int classIndex = classifier.predict(features);

    // Mapping index → Section (dépend de l'ordre d'entraînement du modèle)
    switch (classIndex)
    {
        case 0:  section = Section::Intro;   break;
        case 1:  section = Section::Verse;   break;
        case 2:  section = Section::Chorus;  break;
        case 3:  section = Section::Bridge;  break;
        default: section = Section::Unknown; break;
    }
}

const char* StructurePredictor::sectionName(Section s)
{
    switch (s)
    {
        case Section::Intro:   return "Intro";
        case Section::Verse:   return "Verse";
        case Section::Chorus:  return "Chorus";
        case Section::Bridge:  return "Bridge";
        default:               return "Unknown";
    }
}
