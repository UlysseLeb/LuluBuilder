#pragma once

#include <vector>
#include "ONNXClassifier.h"

// Traduit les features audio en label de section musicale.
// Pour l'instant : retourne toujours Unknown (modèle non chargé).
class StructurePredictor
{
public:
    enum class Section { Unknown, Intro, Verse, Chorus, Bridge };

    StructurePredictor();

    void update(const std::vector<float>& features);
    Section currentSection() const { return section; }

    static const char* sectionName(Section s);

private:
    ONNXClassifier classifier;
    Section        section = Section::Unknown;
};
