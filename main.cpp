/**
 * @file main.cpp
 * @author Timothé DARMOISE (timothe.darmoise@utbm.fr)
 * @brief 
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <server.hpp>
#include <sensor.hpp>
#include <temperature.hpp>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));
    Server s1;
    sensor<float> sensor1;
    temperature t1;
    
    // s1.setTemperature(30);
    // s1.getTemperature();
    s1.consoleWrite();
    s1.fileWrite();
    //sensor1.aleaGenVal();
    // cout << s1;

    //t1.getTemperature();
    sensor1.getValues();
}