#include "humidity.hpp"

// Génère la valeur d'humidité
float humidity::getHumidity(){
    this->valHumidity = aleaGenVal();
    // Pour assurer la cohérence des valeurs
    while(this->valHumidity >= 100){
        this->valHumidity = this->valHumidity/4;
    }
    return this->valHumidity;
}

