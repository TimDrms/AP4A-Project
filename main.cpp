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

int main()
{
    Server s1;
    // s1.setTemperature(30);
    // s1.getTemperature();
    s1.consoleWrite();
    s1.fileWrite();
    // cout << s1;
};