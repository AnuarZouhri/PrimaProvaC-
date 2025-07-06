//
// MedicalEquipment.h - Second derived class
//
#ifndef MEDICALEQUIPMENT_H
#define MEDICALEQUIPMENT_H

#include "MedicalItem.h"

namespace Medical {

    class MedicalEquipment : public MedicalItem {
    private:
        std::string tipo_dispositivo;
        bool sterile;
        bool riutilizzabile;
        std::string materiale;

    public:
        MedicalEquipment(int n_oggetti, int max_oggetti, float volume_occupato, float peso_tara,
                        float peso_singolo_oggetto, std::string marca, MeseAnno scadenza,
                        std::string tipo_dispositivo, bool sterile, bool riutilizzabile,
                        std::string materiale)
            : MedicalItem(n_oggetti, max_oggetti, volume_occupato, peso_tara, peso_singolo_oggetto, marca, scadenza) {
            this->tipo_dispositivo = std::move(tipo_dispositivo);
            this->materiale = std::move(materiale);
            //uso std::move() per spostare il valore all'interno del membro della classe e per evitare una copia
            //di quel valore

            this->sterile = sterile;
            this->riutilizzabile = riutilizzabile;

        }

        ~MedicalEquipment() {
            std::cout << "  -> Sto distruggendo un MedicalEquipment: " << tipo_dispositivo << std::endl;
        }

        std::string getItemType() {
            return "Equipaggiamento Medico";
        }

        void printDetails() {
            std::cout << "=== Equipaggiamento Medico ===" << std::endl;
            MedicalItem::printDetails();
            std::cout << "Tipo di sispositivo: " << tipo_dispositivo << std::endl;
            std::cout << "Materiale: " << materiale << std::endl;
            if (sterile) {
                std::cout << "Sterile: Si" << std::endl;
            } else {
                std::cout << "Sterile: No" << std::endl;
            }
            if (!riutilizzabile) {
                std::cout << "Monouso: Si" << std::endl;
            } else {
                std::cout << "Monouso: No" << std::endl;
            }
        }

        // Getters
        std::string getTipoDispositivo() const{ return tipo_dispositivo; }
        bool isSterile() const { return sterile; }
        bool isRiutilizzabile() const { return riutilizzabile; }
        std::string getMateriale() const{ return materiale; }
    };

    //MedicalEquipment* operator+(const MedicalEquipment& a, const MedicalEquipment& b);
}

#endif //MEDICALEQUIPMENT_H