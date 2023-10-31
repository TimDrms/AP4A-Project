#include "sensor.hpp"

// Génère un nombre au hasard
template <class T> 
T sensor<T>::aleaGenVal(){
    this->value = 8*(rand() / (T) rand() + 1);
    return this->value;
}

template <>
bool sensor<bool>::aleaGenVal(){
    this->value = rand()%2;
    return this->value;
}

template <>
int sensor<int>::aleaGenVal(){
    this->value = rand()%110+20;
    return this->value;
}