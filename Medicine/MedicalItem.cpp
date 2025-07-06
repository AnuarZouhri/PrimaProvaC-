//
// Created by anuar on 06/07/2025.
//

#include "MedicalItem.h"

namespace Medical {
    std::ostream& operator<<(std::ostream& os, MedicalItem& item) {
        os << item.getItemType() << " - " << item.getMarca();
        return os;
    }
} // Medical