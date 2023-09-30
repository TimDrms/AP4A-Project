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

    // Constructeurs et destructeur
    Server();
    Server(const Server &s);
    ~Server();

    // Opérateurs d'affectations
    Server &operator=(const Server& s);
    friend ostream &operator<<(ostream &os, const Server &dt);
    
    // Setter et Getter pour la température
    void setTemperature(int t);
    int getTemperature();

    // Méthodes pour écrire les données dans la console et dans notre fichier de logs.
    void consoleWrite();
    void fileWrite();

};