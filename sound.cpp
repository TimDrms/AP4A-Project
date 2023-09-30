#include <sound.hpp>
#include <sensor.hpp>

// Génère la température
int sound::getSound(){
    sensor<int> s1;
    this->valSound = s1.aleaGenVal(SOUNDFACTOR);
    return this->valSound;
}

