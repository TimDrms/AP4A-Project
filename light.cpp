#include "light.hpp"

// Génère la valeur du son
bool light::getLight(){
    this->valLight = aleaGenVal();
    return this->valLight;
}

