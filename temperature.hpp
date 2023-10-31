#include <iostream>

#include "sensor.hpp"

using namespace std;

#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

class temperature: public sensor<float>{
    protected:
    float valTemperature;

    public:
    // Forme canonique de Coplien
    temperature(){
        valTemperature = 0;
    }
    temperature(const temperature &t){
        this->valTemperature = t.valTemperature;
    }
    ~temperature(){};
    temperature &operator=(const temperature &t){
        this->valTemperature = t.valTemperature;
        return *this;
    }

    // Génère la valeur de température
    float getTemperature();

};

#endif // TEMPERATURE_HPP