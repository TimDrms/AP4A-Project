#include "server.hpp"

int main()
{
    srand(time(NULL));
    int nbCaptures = 0;
    Server s1;

    s1.initialisation();

    cout << "Combien de captures voulez-vous faire au total ? (Maximum 1000)" << endl;
    cin >> nbCaptures;

    for(int i = 0; i < nbCaptures; i++){
        s1.dataRcv();
    }
}