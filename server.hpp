#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip> // Pour la fonction setprecision()
#include <chrono> // Pour savoir quand est-ce que les mesures sont faites
#include <ctime>

#include "scheduler.hpp"

using namespace std;

class Server: public scheduler{
    private:
    float temperature;
    float humidite;
    bool lumiere;
    int sonore;
    char yesOrNo[4]; // Permet de savoir si on doit capturer la valeur ou non pour chaque capteur

    public:

    // Constructeurs et destructeur
    Server();
    Server(const Server &s);
    ~Server();

    // Opérateur d'affectation et surcharge de l'opérateur <<
    Server &operator=(const Server& s);
    friend ostream &operator<<(ostream &os, const Server &dt);

    // Méthodes pour écrire les données dans la console et dans notre fichier de logs.
    void consoleWrite();
    void fileWrite();

    // Méthode pour capturer les données
    void dataRcv(); 

    // Méthode pour initialiser notre serveur avec les données que l'on veut capturer
    void initialisation();

};