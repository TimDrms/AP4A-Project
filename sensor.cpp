/**
 * @file Sensor.cpp
 * @author Timothé DARMOISE (timothe.darmoise@utbm.fr)
 * @brief 
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "sensor.hpp"
/*#include "temperature.hpp"
#include "sound.hpp"
#include "humidity.hpp"
#include "light.hpp"*/ // Normalement il n'y a pas besoin d'include les 4 types de sensor

// Génère un nombre au hasard
template <class T> 
T sensor<T>::aleaGenVal(){
    this->value = 8*(rand() / (T) rand() + 1);
    cout << this->value << endl; // La valeur générée pourra être modifiée par la suite.
    return this->value;
}

template <>
bool sensor<bool>::aleaGenVal(){
    this->value = rand()%2;
    cout << this->value << endl;
    return this->value;
}

template <>
int sensor<int>::aleaGenVal(){
    this->value = rand()%110+20;
    cout << this->value << endl;
    return this->value;
}