#include "temperature.hpp"

// Génère la température
float temperature::getTemperature(){
    this->valTemperature = aleaGenVal();
    // Pour assurer la cohérence des valeurs
    while(this->valTemperature >= 40){
        this->valTemperature = this->valTemperature/4;
    }
    return this->valTemperature;
}