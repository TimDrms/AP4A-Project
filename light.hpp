#include <iostream>

#include "sensor.hpp"

using namespace std;

#ifndef LIGHT_HPP
#define LIGHT_HPP

class light: public sensor<bool>{
    protected:
    bool valLight;

    public:
    // Forme canonique de Coplien
    light(){
        valLight = false;
    }
    light(const light &l){
        this->valLight = l.valLight;
    }
    ~light(){};
    light &operator=(const light &l){
        this->valLight = l.valLight;
        return *this;
    }

    // Génère la valeur de luminosité
    bool getLight();

};

#endif // LIGHT_HPP