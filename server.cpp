/**
 * @file Server.cpp
 * @author Timothé DARMOISE (timothe.darmoise@utbm.fr)
 * @brief 
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <server.hpp>

Server::Server()
{
    this->temperature = 12;
    this->humidite = 24.86;
    this->lumiere = 92.76;
    this->sonore = 12.9;
}

Server::Server(const Server &s)
{
    this->temperature = s.temperature;
    this->humidite = s.humidite;
    this->lumiere = s.lumiere;
    this->sonore = s.sonore;
}

// Destructeur
Server::~Server()
{
    if (temperature > 50)
    {
    }
};

// Opérateur d'affectation
Server& Server::operator=(const Server &s)
{
    this->temperature = s.temperature;
    this->humidite = s.humidite;
    this->lumiere = s.lumiere;
    this->sonore = s.sonore;
    return *this;
}

// Setter temperature
void Server::setTemperature(int t)
{
    this->temperature = t;
}

// Getter temperature
int Server::getTemperature()
{
    return this->temperature;
}

// Ecrit dans la console les données
void Server::consoleWrite()
{
    cout << *this;
}

// Ecrit les données dans notre fichier de log
void Server::fileWrite()
{
    ofstream logFile;
    logFile.open("logs/log.txt", ios::app);
    if (logFile.is_open())
    {
        logFile << *this;
        logFile.close();
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier";
    }
}

// Surcharge opérateur <<
ostream &operator<<(ostream &os, const Server &srv)
{
    os << "Température : " << srv.temperature << "\nHumidité : " << srv.humidite << "\nLumière : " << srv.lumiere << "\nSonore : " << srv.sonore << endl; //<< srv.da << '/' << srv.yr;
    return os;
}