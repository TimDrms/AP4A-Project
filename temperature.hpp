#include <iostream>

#include "sensor.hpp"

using namespace std;

#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

class temperature: public sensor<float>{
    protected:
    float valTemperature;

    public:
    temperature(){
        valTemperature = 0;
    }
    float getTemperature();

};

#endif // TEMPERATURE_HPP