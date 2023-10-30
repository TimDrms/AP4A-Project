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

#include "server.hpp"

Server::Server()
{
    this->temperature = 0;
    this->humidite = 0;
    this->lumiere = false;
    this->sonore = 0;
    //strcpy(this->yesOrNo, "n");
}

Server::Server(const Server &s)
{
    this->temperature = s.temperature;
    this->humidite = s.humidite;
    this->lumiere = s.lumiere;
    this->sonore = s.sonore;
    //strcpy(this->yesOrNo, s.yesOrNo);
}

// Destructeur
Server::~Server(){};

// Opérateur d'affectation
Server &Server::operator=(const Server &s)
{
    this->temperature = s.temperature;
    this->humidite = s.humidite;
    this->lumiere = s.lumiere;
    this->sonore = s.sonore;
    //strcpy(this->yesOrNo, s.yesOrNo);
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
    /*os << "Température : " << srv.temperature << "°C\nHumidité : " << srv.humidite << "%\nLumière : "; // << srv.lumiere << "\nSonore : " << srv.sonore << "dB" << endl;

    if (srv.lumiere)
    {
        os << "true";
    }
    else
    {
        os << "false";
    }

    os << "\nSonore : " << srv.sonore << "dB" << endl;
    return os;*/
    /*time_t t; // t passed as argument in function time()
    struct tm * tt; // decalring variable for localtime()
    time (&t); //passing argument to time()
    tt = localtime(&t);
    os << "Current Day, Date and Time is = "<< asctime(tt);*/

    // Obtenir la date et heure à laquelle les mesures ont été faites
    auto currentTime = chrono::system_clock::now();
    time_t currentTime_t = chrono::system_clock::to_time_t(currentTime);
    os << ctime(&currentTime_t);

    if (srv.yesOrNo[0] == 'y' || srv.yesOrNo[0] == 'Y')
    {
        os << setprecision(3) << "Température : " << srv.temperature << "°C" << endl;
    }
    if (srv.yesOrNo[1] == 'y' || srv.yesOrNo[1] == 'Y')
    {
        os << setprecision(3) << "Humidité : " << srv.humidite << "%" << endl;
    }
    if (srv.yesOrNo[2] == 'y' || srv.yesOrNo[2] == 'Y')
    {
        os << "Sonore : " << srv.sonore << "dB" << endl;
    }
    if (srv.yesOrNo[3] == 'y' || srv.yesOrNo[3] == 'Y')
    {
        os << "Lumière : ";
        if (srv.lumiere)
        {
            os << "true" << endl;
        }
        else
        {
            os << "false" << endl;
        }
    }
    return os;
}

void Server::dataRcv()
{
    if (yesOrNo[0] == 'y' || yesOrNo[0] == 'Y')
    {
        this->temperature = getTemperatureValue();
    }
    if (yesOrNo[1] == 'y' || yesOrNo[1] == 'Y')
    {
        this->humidite = getHumidityValue();
    }
    if (yesOrNo[2] == 'y' || yesOrNo[2] == 'Y')
    {
        this->sonore = getSoundValue();
    }
    if (yesOrNo[3] == 'y' || yesOrNo[3] == 'Y')
    {
        this->lumiere = getLightValue();
    }
    cout << *this; // Permet de print toutes les valeurs d'un seul coup
    fileWrite();   // Permet d'écrire les nouvelles valeurs dans le fichier de log.
}

void Server::initialisation()
{
    cout << "Bienvenue dans ce simulateur de qualité de l'air.\nAvant de commencer nous avons quelques questions à vous poser afin de savoir quels capteurs vous aimeriez utiliser. Répondez toujours par la lettre y ou la lettre n (respectivement pour yes ou no)." << endl;
    cout << "Voulez-vous utilisez le capteur de température ? y/n" << endl;
    cin >> yesOrNo[0];
    cout << "Voulez-vous utilisez le capteur d'humidité ? y/n" << endl;
    cin >> yesOrNo[1];
    cout << "Voulez-vous utilisez le capteur sonore ? y/n" << endl;
    cin >> yesOrNo[2];
    cout << "Voulez-vous utilisez le capteur de son ? y/n" << endl;
    cin >> yesOrNo[3];
    /*for (int i = 0; i <= 3; i++)
    {
        if (yesOrNo[i] == 'y' || yesOrNo[i] == 'Y')
        {
            cout << "La réponse est oui.0" << endl;
        }
        else
        {
            cout << "La réponse est non.0" << endl;
        }
    }*/
}