# Rapport d'AP4A
## Introduction
Avant de commencer la réalisation de ce projet d'AP4A, il fallait réfléchir à la manière dont j'allais traiter le problème. Pour cela j'ai suivi en grande partie les indications qui ont été donné dans le sujet et dans le diagramme UML distribué en cours. Voici comment j'ai fait : 
+ Une classe Server qui permet de recevoir les données et de les stocker dans un fichier de log ainsi qu'une visualisation dans la console.
+ Une classe Scheduler qui récupère chaque information mesuré avant de les envoyer au serveur, avec un intervalle de temps défini à l'avance dans le code.
+ Une classe Sensor qui permet justement d'effectuer les mesures.
+ Enfin, 4 classes qui héritent chacune de Sensor (Sensor est donc la classe mère). Ces 4 classes vont être précisément les différents types de capteurs, c'est-à-dire que l'on aura une classe Temperature pour capturer la température, une classe Humidity pour capturer l'humidité, etc. 

Voici donc le diagramme UML de ce projet.
Insérer l'image.
Désormais, il est temps d'expliquer clairement comment fonctionne chacune des classes. Pour cela, je vais à chaque fois montrer le prototype de la classe, puis expliquer la manière dont j'ai décidé d'implémenter chaque classe.

## Sensor
```C++
using namespace std;

template <class T> class sensor{
    protected:
    T value;
    
    public:
    sensor(){};
    sensor(const sensor &s){}
    ~sensor(){}

    T aleaGenVal();
};
```
J'ai décidé de faire une classe template pour mon sensor. L'énorme avantage des classes templates est qu'on ne précise pas de type en paramètre, afin de le définir uniquement lorsqu'on va instancier la classe. Cela est extrêmement utile, étant donné qu'on aura des valeurs de 3 types différents (`int, float et bool`), la classe va donc s'adapter afin qu'elle fonctionne pour tous les types (dans les faits, nous pourrions même utiliser d'autres types).
Cela explique pourquoi notre variable value est de type `T`, c'est parce qu'elle peut devenir un entier, un float, un bool, etc. Il en est de même pour la méthode `aleaGenVal()` qui permet de générer une valeur capturée. Celle-ci va renvoyer une valeur de type `T` en fonction de ce qu'on veut comme type de valeur. 
A part cela, la classe contient également tout ce qu'il faut pour respecter la forme canonique de Coplien.

## Les filles de Sensor
Parlons désormais des filles de Sensor, qui correspondent aux types de valeur que l'on capture. En accord avec le sujet, elles sont au nombre de 4 :
+ Temperature
+ Humidity
+ Sound
+ Light

Il y aura donc 4 classes, une pour chaque unité à capturer. Voici par exemple le prototype de la classe Temperature.
```CPP
class temperature: public sensor<float>{
    protected:
    float valTemperature;

    public:
    // Forme canonique de Coplien
    temperature(){
        valTemperature = 0;
    }
    temperature(const temperature &t){
        this->valTemperature = t.valTemperature;
    }
    ~temperature(){};
    temperature &operator=(const temperature &t){
        this->valTemperature = t.valTemperature;
        return *this;
    }

    // Génère la valeur de température
    float getTemperature();

};
```
Encore une fois, nous retrouvons la forme canonique de Coplien, mais nous voyons aussi dans la déclaration de la classe que celle-ci hérite de sensor. Cela va donc permettre d'utiliser sensor pour faire la capture. De plus, on précise que c'est un float car la valeur souhaitée sera un float. Une fois cela, notre classe template Sensor va s'adapter à notre requête qui est d'utiliser un float. 
Notre classe Temperature a donc une méthode `getTemperature()` qui permet de capturer une température grâce à la classe Sensor et de renvoyer cette valeur, qui est ici un float. 
Le fonctionne est à peu près identique pour les classes Humidity, Sound et Light. L'avantage d'un tel fonctionnement est qu'il est extrêmement simple de rajouter d'autres capteurs, même s'ils ont un type différent.

## Scheduler
```CPP
class scheduler{
    protected:
    float valTemperature;
    float valHumidite;
    bool valLumiere;
    int valSonore;

    public:
    scheduler();
    scheduler(const scheduler& s);
    scheduler &operator=(const scheduler& s);
    ~scheduler();

    float getTemperatureValue();
    float getHumidityValue();
    int getSoundValue();
    bool getLightValue();
};
```
La classe Scheduler n'hérite pas directement de sensor, cependant j'utilise du layering. C'est-à-dire que pour chaque type de capteur qui existe, j'en crée un. Par exemple dans la méthode `getTemperatureValue()`, je vais créer un capteur de température qui va capturer une valeur, et la stocker dans mon scheduler, qui l'enverra plus tard à ma classe Server. 
De ce fait, j'ai réalisé une méthode pour chaque type de capteur qui existe. Cela est également utile car si l'on ne veut pas utiliser tous les capteurs, on n'appelera que les méthodes nécessaires.
De plus, afin de respecter ce qui nous était demandé dans le sujet, les informations sont récupérées et transmises à des intervalles de temps différent. Le temps d'attente pour chaque capteur est défini dans le prototype du scheduler, ce qui fait qu'il est très facilement modifiable, voici comment il est défini :
```CPP
// Intervalle de temps d'attente pour chaque capteur. Les valeurs sont en millisecondes
#define TEMPERATUREDELAY 568
#define HUMIDITEDELAY 342
#define LUMIEREDELAY 847
#define SONOREDELAY 345
```
Enfin, voici un exemple d'une des méthodes permettant la capteur de valeur, avec celle qui permet de capturer une température.
```CPP
float scheduler::getTemperatureValue(){
    temperature temperatureCaptor;
    usleep(TEMPERATUREDELAY*1000);
    this->valTemperature = temperatureCaptor.getTemperature();
    return this->valTemperature;
}
```
On crée donc notre capteur de température grâce au layering, puis on attend durant un certain temps étant donné qu'on veut que les valeurs soient transmises à des intervalles de temps différent (à noter que `usleep` prend en paramètre des microsecondes, c'est pour cela que la valeur est multipliée par 1000). En suite, on fait la capture de la température, et enfin on renvoie cette valeur, tout simplement.
## Server
```CPP
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
```
La classe Server est donc celle qui récupère les données et va s'occuper de les afficher dans la console, mais aussi de les stocker dans un fichier de logs. 
Avant de commencer, on voit que la classe Server hérite de la classe Scheduler afin de pouvoir utiliser les différentes méthodes du scheduler. L'intérêt étant qu'on va appeler les méthodes du scheduler pour recevoir les données dans notre méthode `dataRcv()`. Par exemple, si l'on veut utiliser le capteur de température, on appelera la méthode `getTemperatureValue()` de la classe Scheduler.
## Interlude : la surcharge des opérateurs << et ==
#### Surcharge de l'opérateur <<
Je me permets de faire un petit aparté afin de parler de la surcharge des opérateurs << et == dans la classe Server, en commençant par parler de la surcharge de l'opérateur <<.
```CPP
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
```
L'opérateur << a été pensé pour renvoyer correctement et d'une manière plus stylisé nos données. Dans un premier temps, la date ainsi que l'heure de la mesure est affiché afin de savoir quand est-ce que la mesure a été effectué. En suite, on affiche les valeurs des capteurs qu'on utilise, en précisant à chaque fois à quelle type de capture cela correspond. On remarque également plusieurs fois une instruction `if (srv.yesOrNo[i] == 'y' || srv.yesOrNo[i] == 'Y')`. Celle-ci permet de vérifier si l'on utilise ou non le capteur en question, de cette manière, si on n'utilise pas un des capteurs, on ne vas pas afficher de résultats pour un capteur. Par exemple si l'on décide de ne pas utiliser le capteur de température, on ne va pas afficher des mesures pour la température. Cela permet d'améliorer la qualité de vie du programme pour l'utilisateur. 
#### Surcharge de l'opérateur =
```CPP
Server &Server::operator=(const Server &s)
{
    this->temperature = s.temperature;
    this->humidite = s.humidite;
    this->lumiere = s.lumiere;
    this->sonore = s.sonore;
    strcpy(this->yesOrNo, s.yesOrNo);
    return *this;
}
```
L'opérateur = a donc aussi été surchargé. La raison principale qui explique cette surcharge est le fait que pour respecté la forme canonique de Coplien, il faut redéfinir cet opérateur. Cependant, dans ce programme l'opérateur d'affectation n'est pas utilisé, ce qui rend sa définition inutile dans l'état actuel. Cela étant, il est utile d'avoir d'ores et déjà surchargé cet opérateur-là dans le cadre de la maintenance du programme. En effet, si le programme évolue et que l'opérateur = devient nécessaire, celui-ci aura déjà été surchargé. 
Pour revenir rapidement sur son utilisation tout de même, il va tout simplement copier les valeurs des attributs d'un objet de la class Server vers un autre objet de cette même classe.
## Server (suite)
Grâce à la surcharge de l'opérateur <<, les méthodes `consoleWrite()` et `fileWrite()` (qui permettent respectivement d'écrire les résultats des captures dans la console, et dans un fichier de log) ont pu être grandement simplifiées. La première consiste juste en un `cout << *this;`, et pour la seconde, même s'il faut tout de même ouvrir le fichier pour pouvoir écrire dedans, la phase d'écriture ne se fait qu'avec un `logFile << *this`, où logFile est notre fichier de logs.
Il y a aussi une méthode `initialisation()` qui permet, comme son nom l'indique, d'initialiser le programme. C'est-à-dire que lorsqu'on exécute le programme, celui-ci va demander à l'utilisateur quel capteur ce dernier aimerait utiliser. Pour retenir cela en mémoire, la variable `yesOrNo` est utilisé. C'est un tableau de char, où chaque valeur détermine si l'on doit utiliser le capteur ou non. Par exemple, si l'utilisateur a indiqué vouloir utiliser le capteur de température, cela sera stocké dans `yesOrNo[0]`, car l'utilisateur aura répondu "y" ou "Y" pour indiquer qu'il veut utiliser ce capteur. De ce fait, il suffit de vérifier au moment de la capture des données si l'utilisateur a indiqué vouloir utiliser ce capteur. S'il a indiqué vouloir l'utiliser, alors on fait la capture, sinon on ne fait rien et on passe au prochain capteur. On vérifie donc `yesOrNo[1]`, et ainsi de suite pour tous les capteurs. Voici un exemple d'utilisation dans la méthode `dataRcv()` :
```CPP
if (yesOrNo[0] == 'y' || yesOrNo[0] == 'Y')
{
    this->temperature = getTemperatureValue(); // On utilise la fonction getTemperatureValue() pour obtenir la valeur de la température
}
```
## Utilisation du programme
Pour utiliser ce programme un fichier main a été crée. Celui-ci est extrêment simple car il crée tout simplement un serveur, puis initialise le programme, demande à l'utilisateur combien de mesures celui-ci aimerait faire, et fait le nombre de mesures demandés grâce à la méthode `dataRcv()` dans la classe Server. 
Cela étant, pour compiler le programme, il suffit d'écrire `make` dans notre invite de commandes lorsqu'on est un dans le dossier. Cela est dû au fichier Makefile qui permet de compiler directement tous les fichiers dont on a besoin. Attention tout de même, la compilation ne marche que sous Linux. 
Une fois le programme compilé, il suffit d'écrire `./main` dans notre invite de commandes pour l'exécuter. 
Voici un exemple d'exécution de ce programme :
```xl
Bienvenue dans ce simulateur de qualité de l'air.
Avant de commencer, nous avons quelques questions à vous poser afin de savoir quels capteurs vous aimeriez utiliser. Répondez toujours par la lettre y ou la lettre n (respectivement pour yes ou no).
Voulez-vous utilisez le capteur de température ? y/n
y
Voulez-vous utilisez le capteur d'humidité ? y/n
n
Voulez-vous utilisez le capteur sonore ? y/n
n
Voulez-vous utilisez le capteur de lumière ? y/n
y
Combien de captures voulez-vous effectuer au total ? (Maximum 1000)
3
Wed Nov  1 23:31:31 2023
Température : 19.5°C
Lumière : true
Wed Nov  1 23:31:32 2023
Température : 25.7°C
Lumière : false
Wed Nov  1 23:31:34 2023
Température : 18.4°C
Lumière : false
```
De plus, une démonstration vidéo est disponible sur Youtube : 