#include <iostream>

#define FACTOR 15

using namespace std;

class temperature{
    private:
    float valTemperature;

    public:
    temperature(){
        valTemperature = 0;
    }
    float getTemperature();

};