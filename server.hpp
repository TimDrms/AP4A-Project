/**
 * @file Server.hpp
 * @author Timothé DARMOISE (timothe.darmoise@utbm.fr)
 * @brief 
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>


using namespace std;

class Server{
    private:
    float temperature;
    float humidite;
    float lumiere;
    float sonore;

    public:
    Server();
    Server(const Server &s);
    ~Server();

    Server &operator=(const Server& s);
    friend ostream &operator<<(ostream &os, const Server &dt);
    
    void setTemperature(int t);
    int getTemperature();

    void consoleWrite();
    void fileWrite();

};