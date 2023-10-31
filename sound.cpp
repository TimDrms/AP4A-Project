#include "sound.hpp"

// Génère la valeur du son
int sound::getSound(){
    this->valSound = aleaGenVal();
    return this->valSound;
}