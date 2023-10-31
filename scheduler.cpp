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

scheduler::~scheduler(){};

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