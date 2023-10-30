#include <iostream>

#include "sensor.hpp"

using namespace std;

#ifndef LIGHT_HPP
#define LIGHT_HPP

class light: public sensor<bool>{
    protected:
    bool valLight;

    public:
    light(){
        valLight = false;
    }
    bool getLight();

};

#endif // LIGHT_HPP