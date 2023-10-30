#include "temperature.hpp"

// Génère la température
float temperature::getTemperature(){
    this->valTemperature = aleaGenVal();
    while(this->valTemperature >= 40){
        this->valTemperature = this->valTemperature/4; // Pour assurer la cohérence des valeurs
    }
    return this->valTemperature;
}

