//
// main.cpp
//
#include "MedicalItem.h"
#include "Medication.h"
#include "MedicalEquipment.h"
#include <iostream>

using namespace Medical;

std::ostream& operator<<(std::ostream& os, MedicalItem& item) {
    os << item.getItemType() << " - " << item.getMarca();
    return os;
}

MedicalEquipment* operator+(const MedicalEquipment& a, const MedicalEquipment& b) {
    if (
        (a.getTipoDispositivo() != b.getTipoDispositivo()) ||
        a.getNOggetti() + b.getNOggetti() > a.getMaxOggetti() ||
        a.isExpired() || b.isExpired() || (a.isSterile() != b.isSterile()) ||
        (a.getMarca() != b.getMarca()) || !(a.getScadenza() == b.getScadenza())
    ) {
        throw std::invalid_argument("I due dispositivi non possono essere uniti");
    }
    MedicalEquipment* nuovo = new  MedicalEquipment(
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

    return nuovo;
}


int main() {
    std::cout << "\n-----Inizio-----!" << std::endl;

    MedicalItem* items[4];


    // Medications
    items[0] = new Medication(50, 50, 200.0, 10.0, 0.5, "Bayer", MeseAnno(12, 2025),
                             "Acido Acetilsaliciclico", 500.0, "compresse", false);

    items[1] = new Medication(20, 20, 150.0, 25.0, 2.0, "Pfizer", MeseAnno(6, 2024),
                             "Amoxicillina", 250.0, "sciroppo", true);

    // MedicalEquipment
    items[2] = new MedicalEquipment(100, 100, 300.0, 50.0, 0.8, "BD Medical", MeseAnno(3, 2026),
                                   "siringa", true, false, "plastica");

    items[3] = new MedicalEquipment(5, 5, 100.0, 200.0, 15.0, "Welch Allyn", MeseAnno(12, 2028),
                                   "termometro", false, true, "metallo");

    // Display all items
    std::cout << "=== KIT MEDICO ===" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "\n--- Item " << (i + 1) << " ---" << std::endl;
        items[i]->printDetails();

        // Test operator<<
        std::cout << "Quick info: " << *items[i] << std::endl;

        // Check if expired
        if (items[i]->isExpired()) {
            std::cout << "WARNING: OGGETTO SCADUTO"<< std::endl;
        }
    }
    std::cout << "==================" << std::endl;

    // pulizia memoria
    for (int i = 0; i < 4; i++) {
        delete items[i];
    }

    items[0] = new Medication(50, 50, 200.0, 10.0, 0.5, "Bayer", MeseAnno(12, 2025),
                             "Acido Acetilsaliciclico", 500.0, "compresse", false);

    items[1] = new Medication(50, 50, 200.0, 10.0, 0.5, "Bayer", MeseAnno(12, 2025),
                                 "Acido Acetilsaliciclico", 500.0, "compresse", false);

    items[2] = new Medication(50, 50, 200.0, 10.0, 0.5, "Bayer", MeseAnno(12, 2025),
                                 "Ibuprofene", 500.0, "compresse", false);

    // Verifica dell'operatore == sovraccaricato

    for (int i = 0; i < 2; i++) {
        if (items[0] == items[i]) {
            std::cout << "--> I due farmaci sono equivalenti"<<std::endl;
        }
        else {
            std::cout << "--> I due farmaci non sono equivalenti"<<std::endl;
        }
    }

    for (int i = 0; i < 3; i++) {
        delete items[i];
    }

    MedicalEquipment *obj1 = new MedicalEquipment(10, 100, 300.0, 5.0, 0.8, "BD Medical", MeseAnno(3, 2026),
                                                  "siringa", true, false, "plastica");

    MedicalEquipment *obj2 = new MedicalEquipment(50, 100, 300.0, 25.0, 0.8, "BD Medical", MeseAnno(3, 2026),
                                   "siringa", true, false, "plastica");

    MedicalEquipment *obj3 = new MedicalEquipment(100, 100, 300.0, 25.0, 0.8, "BD Medical", MeseAnno(3, 2026),
                                   "siringa", true, false, "plastica");

    // provo a sommare due oggetti con l'operatore sovraccaricato

    //questi si possono unire
    try {
        MedicalEquipment* nuovo1 = *obj1 + *obj2;

        nuovo1->printDetails();
        delete nuovo1;
    } catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }

    //questi due non si potranno unire
    try {
        MedicalEquipment* nuovo2 = *obj2 + *obj3;

        nuovo2->printDetails();
        delete nuovo2;
    } catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }

    delete obj1;
    delete obj2;
    delete obj3;


    std::cout << "\n-----Fine-----!" << std::endl;
    return 0;
}