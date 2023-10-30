#include <iostream>

#include "sensor.hpp"

using namespace std;

#ifndef SOUND_HPP
#define SOUND_HPP

class sound: public sensor<int>{
    protected:
    int valSound;

    public:
    sound(){
        valSound = 0;
    }
    int getSound();

};

#endif // SOUND_HPP