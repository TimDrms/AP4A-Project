#include "server.hpp"

// Constructeur par défaut
Server::Server()
{
    this->temperature = 0;
    this->humidite = 0;
    this->lumiere = false;
    this->sonore = 0;
    strcpy(this->yesOrNo, "n");
}

// Constructeur par recopie
Server::Server(const Server &s)
{
    this->temperature = s.temperature;
    this->humidite = s.humidite;
    this->lumiere = s.lumiere;
    this->sonore = s.sonore;
    strcpy(this->yesOrNo, s.yesOrNo);
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
    strcpy(this->yesOrNo, s.yesOrNo);
    return *this;
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

/*
Cette fonction permet de print les valeurs de notre serveur dans la console grâce à la surcharge de l'opérateur <<.
Elle est appelée par la fonction consoleWrite() et par la fonction fileWrite().
*/
ostream &operator<<(ostream &os, const Server &srv)
{
    // Obtenir la date et heure à laquelle les mesures ont été faites
    auto currentTime = chrono::system_clock::now();
    time_t currentTime_t = chrono::system_clock::to_time_t(currentTime);
    os << ctime(&currentTime_t);

    // Renvoie chaque valeur que l'on a décidé de capturer. On utilise srv.yesOrNo[0] == 'y' || srv.yesOrNo[0] == 'Y' pour savoir si on doit afficher la valeur ou non
    // On utilise setprecision(3) pour avoir 3 chiffres après la virgule
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

// Capture chaque valeur que l'on a décidé de capturer.
void Server::dataRcv()
{
    if (yesOrNo[0] == 'y' || yesOrNo[0] == 'Y')
    {
        this->temperature = getTemperatureValue(); // On utilise la fonction getTemperatureValue() pour obtenir la valeur de la température
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

// Initialisation du programme. On demande à l'utilisateur quels capteurs il aimerait utiliser.
void Server::initialisation()
{
    cout << "Bienvenue dans ce simulateur de qualité de l'air.\nAvant de commencer, nous avons quelques questions à vous poser afin de savoir quels capteurs vous aimeriez utiliser. Répondez toujours par la lettre y ou la lettre n (respectivement pour yes ou no)." << endl;
    cout << "Voulez-vous utilisez le capteur de température ? y/n" << endl;
    cin >> yesOrNo[0];
    cout << "Voulez-vous utilisez le capteur d'humidité ? y/n" << endl;
    cin >> yesOrNo[1];
    cout << "Voulez-vous utilisez le capteur sonore ? y/n" << endl;
    cin >> yesOrNo[2];
    cout << "Voulez-vous utilisez le capteur de lumière ? y/n" << endl;
    cin >> yesOrNo[3];

    /* Lexique pour la variable yesOrNo :
    yesOrNo[0] : capteur de température
    yesOrNo[1] : capteur d'humidité
    yesOrNo[2] : capteur sonore
    yesOrNo[3] : capteur de lumière
    */
}