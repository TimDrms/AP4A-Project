#include <iostream>

#include "sensor.hpp"

using namespace std;

#ifndef SOUND_HPP
#define SOUND_HPP

class sound: public sensor<int>{
    protected:
    int valSound;

    public:
    // Forme canonique de Coplien
    sound(){
        valSound = 0;
    }
    sound(const sound &s){
        this->valSound = s.valSound;
    }
    ~sound(){};
    sound &operator=(const sound &s){
        this->valSound = s.valSound;
        return *this;
    }

    // Génère la valeur du son
    int getSound();

};

#endif // SOUND_HPP