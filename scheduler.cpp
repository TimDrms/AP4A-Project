/**
 * @file scheduler.cpp
 * @author Timothé DARMOISE (timothe.darmoise@utbm.fr)
 * @brief
 * @version 0.1
 * @date 2023-09-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "scheduler.hpp"

scheduler::scheduler(){
    valTemperature = 0;
    valHumidite = 0;
    valLumiere = false;
    valSonore = 0;
}

scheduler::scheduler(const scheduler &s){
    this->valTemperature = s.valTemperature;
    this->valHumidite = s.valHumidite;
    this->valLumiere = s.valLumiere;
    this->valSonore = s.valSonore;
}

scheduler& scheduler::operator=(const scheduler &s){
    this->valTemperature = s.valTemperature;
    this->valHumidite = s.valHumidite;
    this->valLumiere = s.valLumiere;
    this->valSonore = s.valSonore;
    return *this;
}

void scheduler::getAllValues() // Je pourrai surement remplacer par un appel des 4 fonctions en-dessous
{
    temperature tempe1;
    sound sound1;
    humidity humidity1;
    light light1;

    usleep(TEMPERATUREDELAY*1000); // usleep prend en paramètre des microsecondes. On multiplie par 1000 pour avoir des millisecondes.
    this->valTemperature = tempe1.getTemperature();
    cout << "Valeur finale de la température : " << this->valTemperature << endl;
    usleep(SONOREDELAY*1000);
    this->valSonore = sound1.getSound();
    cout << "Valeur finale du son : " << this->valSonore << endl;
    usleep(HUMIDITEDELAY*1000);
    this->valHumidite = humidity1.getHumidity();
    cout << "Valeur finale de l'humidité : " << this->valHumidite << endl;
    usleep(LUMIEREDELAY*1000);
    this->valLumiere = light1.getLight();
    cout << "Valeur finale de la lumière : " << this->valLumiere << endl;
}

float scheduler::getTemperatureValue(){
    temperature temperatureCaptor;
    usleep(TEMPERATUREDELAY*1000);
    this->valTemperature = temperatureCaptor.getTemperature();
    return this->valTemperature;
}

float scheduler::getHumidityValue(){
    humidity humidityCaptor;
    usleep(HUMIDITEDELAY*1000);
    this->valHumidite = humidityCaptor.getHumidity();
    return this->valHumidite;
}

int scheduler::getSoundValue(){
    sound soundCaptor;
    usleep(SONOREDELAY*1000);
    this->valSonore = soundCaptor.getSound();
    return this->valSonore;
}

bool scheduler::getLightValue(){
    light lightCaptor;
    usleep(LUMIEREDELAY*1000);
    this->valLumiere = lightCaptor.getLight();
    return this->valLumiere;
}