#include "MedicalEquipment.h"
#include <stdexcept>

namespace Medical {

    MedicalEquipment* operator+(const MedicalEquipment& a, const MedicalEquipment& b) {
        if (
            (a.getTipoDispositivo() != b.getTipoDispositivo()) ||
            a.getNOggetti() + b.getNOggetti() > a.getMaxOggetti() ||
            a.isExpired() || b.isExpired() || (a.isSterile() != b.isSterile()) ||
            (a.getMarca() != b.getMarca()) || !(a.getScadenza() == b.getScadenza())
        ) {
            throw std::invalid_argument("I due dispositivi non possono essere uniti");
        }
        MedicalEquipment nuovo(
            a.getNOggetti() + b.getNOggetti(),
            a.getMaxOggetti(),
            a.getVolumeOccupato(),
            a.getPesoTara() + b.getPesoTara(),
            a.getPesoSingoloOggetto(),
            a.getMarca(),
            a.getScadenza(),
            a.getTipoDispositivo(),
            a.isSterile(),
            a.isRiutilizzabile(),
            a.getMateriale()
        );

        return nuovo*;
    }

}