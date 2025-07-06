//
// MedicalItem.h
//
#ifndef MEDICALITEM_H
#define MEDICALITEM_H

#include <string>
#include <iostream>
#include <vector>

namespace Medical {

    struct MeseAnno {
        int mese;
        int anno;

        MeseAnno() {
            mese = 1;
            anno = 2025;
        }

        MeseAnno(int m, int a) {
            mese = m;
            anno = a;
        }

        bool operator==(const MeseAnno& other) const {
            return mese == other.mese && anno == other.anno;
        }

    };

    class MedicalItem {
    private:
        int n_oggetti;
        int max_oggetti;
        float volume_occupato;
        float peso_tara;
        float peso_singolo_oggetto;
        std::string marca;
        MeseAnno scadenza;

    public:
        MedicalItem(int n_oggetti, int max_oggetti,float volume_occupato, float peso_tara,
                   float peso_singolo_oggetto, std::string marca, MeseAnno scadenza) {
            if (n_oggetti > max_oggetti) {
                throw std::invalid_argument("n_oggetti non può superare max_oggetti");
            }
            //per impedire l'inserimento di un oggetto che ha n_oggetti > max_oggetti

            this->n_oggetti = n_oggetti;
            this->max_oggetti = max_oggetti;
            this->volume_occupato = volume_occupato;
            this->peso_tara = peso_tara;
            this->peso_singolo_oggetto = peso_singolo_oggetto;
            this->marca = std::move(marca);
            //uso std::move() per spostare il valore all'interno del membro della classe e per evitare una copia
            //di quel valore

            this->scadenza = scadenza;
        }

        virtual ~MedicalItem() {
            std::cout << "  -> Sto distruggendo un MedicalItem: " << marca << std::endl;
        }

        // Metodi getter
        int getNOggetti() const { return n_oggetti; }
        int getMaxOggetti() const {return max_oggetti; }
        float getVolumeOccupato() const { return volume_occupato; }
        float getPesoTara() const { return peso_tara; }
        float getPesoSingoloOggetto() const { return peso_singolo_oggetto; }
        std::string getMarca() const { return marca; }
        MeseAnno getScadenza() const { return scadenza; }


        virtual std::string getItemType() = 0;
        virtual void printDetails() {
            std::cout << "Brand: " << marca << std::endl;
            std::cout << "Quantità: " << n_oggetti << std::endl;
            std::cout << "Peso: " << peso_tara + (peso_singolo_oggetto * n_oggetti) << "g" << std::endl;
            std::cout << "Scadenza: " << scadenza.mese << "/" << scadenza.anno << std::endl;
        }

        //per semplicità considero un medicinale scaduto quando l'anno è minore di 2025
        bool isExpired() const{

            if (scadenza.anno < 2025) {
                return true;
            }
            return false;
        }
    };


    //std::ostream& operator<<(std::ostream& os, MedicalItem& item);
}

#endif //MEDICALITEM_H