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

using namespace std;

template <class T> class sensor{
    private:
        float valTemperature;
        
        int valSound;
        bool valLight;

    public:
    sensor(){
        valTemperature = 0;
        //float humidity = 0;
        valSound = 0;
        valLight = false;
    };

    sensor(const sensor &s){
        this->valTemperature = s.valTemperature;

        this->valSound = s.valSound;
        this->valLight = s.valLight;
        //etc
    }

    ~sensor(){

    }


    T aleaGenVal(int factor);
    T getValues();

};

template class sensor<int>;
template class sensor<float>;
template class sensor<bool>;