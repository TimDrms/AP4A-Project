/**
 * @file scheduler.hpp
 * @author Timothé DARMOISE (timothe.darmoise@utbm.fr)
 * @brief 
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <unistd.h> // Pour la fonction sleep. /!\ Ne fonctionne qu'avec Linux !

#include "sensor.hpp"

#include "temperature.hpp"
#include "sound.hpp"
#include "humidity.hpp"
#include "light.hpp"

// Intervalle de temps d'attente pour chaque capteur. Les valeurs sont en millisecondes
#define TEMPERATUREDELAY 568
#define HUMIDITEDELAY 342
#define LUMIEREDELAY 847
#define SONOREDELAY 345

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

class scheduler{
    protected:
    float valTemperature;
    float valHumidite;
    bool valLumiere;
    int valSonore;

    public:

    scheduler();

    scheduler(const scheduler& s);

    scheduler &operator=(const scheduler& s);

    void getAllValues();
    float getTemperatureValue();
    float getHumidityValue();
    int getSoundValue();
    bool getLightValue();
};

#endif // SCHEDULER_HPP