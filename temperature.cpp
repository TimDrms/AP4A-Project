#include <temperature.hpp>
#include <sensor.hpp>

// Génère la température
float temperature::getTemperature(){
    sensor<float> s1;
    this->valTemperature = s1.aleaGenVal(FACTOR);
    return this->valTemperature;
}

