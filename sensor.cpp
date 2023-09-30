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

#include <sensor.hpp>
#include <temperature.hpp>
#include <sound.hpp>

// Génère un nombre au hasard
// Problème : Lorsque c'est un int ça donne souvent 0 à cause de la division.
template <class T> T sensor<T>::aleaGenVal(int factor){
    T value = factor*(rand() / (T) rand());
    cout << value << endl;
    return value;
}

// Récupère les valeurs des différents capteurs. Ca devrait retourner void, non ?
template <class T> T sensor<T>::getValues(){
    temperature tempe1;
    sound sound1;

    this->valTemperature = tempe1.getTemperature();
    this->valSound = sound1.getSound();
    return 0;
}

