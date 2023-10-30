#include "humidity.hpp"

// Génère la valeur d'humidité
float humidity::getHumidity(){
    this->valHumidity = aleaGenVal();
    while(this->valHumidity >= 100){
        this->valHumidity = this->valHumidity/4; // Pour assurer la cohérence des valeurs
    }
    return this->valHumidity;
}

