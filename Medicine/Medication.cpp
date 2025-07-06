//
// Created by anuar on 06/07/2025.
//

#include "Medication.h"

namespace Medical{
    bool Medical::operator==(const Medication& lMed, const Medication& rMed) {
        return lMed.getPrincipioAttivo() == rMed.getPrincipioAttivo() &&
               lMed.requiresPrescription() == rMed.requiresPrescription();
    }
}