#include <iostream>

#include "sensor.hpp"

using namespace std;

#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP

class humidity: public sensor<float>{
    protected:
    float valHumidity;

    public:
    // Forme canonique de Coplien
    humidity(){
        valHumidity = 0;
    }
    humidity(const humidity &h){
        this->valHumidity = h.valHumidity;
    }
    ~humidity(){};
    humidity &operator=(const humidity &h){
        this->valHumidity = h.valHumidity;
        return *this;
    }

    // Génère la valeur d'humidité
    float getHumidity();

};

#endif // HUMIDITY_HPP