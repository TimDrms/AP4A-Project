#include <iostream>

#include "sensor.hpp"

using namespace std;

#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP

class humidity: public sensor<float>{
    protected:
    float valHumidity;

    public:
    humidity(){
        valHumidity = 0;
    }
    float getHumidity();

};

#endif // HUMIDITY_HPP