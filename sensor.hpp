/**
 * @file sensor.hpp
 * @author Timothé DARMOISE (timothe.darmoise@utbm.fr)
 * @brief 
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstdlib>
#include <random>

#ifndef SENSOR_HPP
#define SENSOR_HPP

using namespace std;

template <class T> class sensor{
    protected:
    T value;
    public:
    sensor(){
       
    };

    sensor(const sensor &s){
        
    }

    ~sensor(){

    }


    T aleaGenVal();
};

template class sensor<int>;
template class sensor<float>;
template class sensor<bool>;
#endif // SENSOR_HPP