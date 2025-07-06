//
// Medication.h
//
#ifndef MEDICATION_H
#define MEDICATION_H

#include "MedicalItem.h"

namespace Medical {

    class Medication : public MedicalItem {
    //Medication è la realizzazione di un farmaco
    private:
        std::string principio_attivo;
        float dosaggio_mg;
        std::string forma_farmaceutica;
        bool prescrizione_medica;

    public:
        Medication(int n_oggetti, int max_oggetti,float volume_occupato, float peso_tara,
                  float peso_singolo_oggetto, std::string marca, MeseAnno scadenza,
                  std::string principio_attivo, float dosaggio_mg,
                  std::string forma_farmaceutica, bool prescrizione_medica)
            : MedicalItem(n_oggetti, max_oggetti, volume_occupato, peso_tara, peso_singolo_oggetto, marca, scadenza) {
            this->principio_attivo = std::move(principio_attivo);
            //uso std::move() per spostare il valore all'interno del membro della classe e per evitare una copia
            //di quel valore


            this->dosaggio_mg = dosaggio_mg;
            this->forma_farmaceutica = std::move(forma_farmaceutica);
            this->prescrizione_medica = prescrizione_medica;
        }

        ~Medication() {
            std::cout << "  -> Sto distruggendo un Medication: " << principio_attivo << std::endl;
        }

        std::string getItemType() {
            return "Medication";
        }



        void printDetails() {
            std::cout << "=== FARMACO ===" << std::endl;
            MedicalItem::printDetails();
            std::cout << "Princio Attivo: " << principio_attivo << std::endl;
            std::cout << "Dosaggio: " << dosaggio_mg << "mg" << std::endl;
            std::cout << "Forma: " << forma_farmaceutica << std::endl;
            if (prescrizione_medica) {
                std::cout << "Prescrizione medica: Si" << std::endl;
            } else {
                std::cout << "Prescrizione medica: No" << std::endl;
            }
        }

        // metodi getter
        std::string getPrincipioAttivo() const{ return principio_attivo; }
        float getDosaggio() const{ return dosaggio_mg; }
        std::string getFormaFarmaceutica() const{ return forma_farmaceutica; }
        bool requiresPrescription() const{ return prescrizione_medica; }
    };

    bool operator==(const Medication& lMed, const Medication& rMed);
    //consideriamo due farmaci uguali se hanno lo stesso principio attivo e se entrambi hanno bisogno entrambi
    //di una prescrizione medica
}

#endif //MEDICATION_H
