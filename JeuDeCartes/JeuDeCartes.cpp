#include <iostream>
#include <random>
using namespace std;

/*
CREER UN JEU DE 52 CARTES

Votre programme propose un tirage aléatoire de 2 x 5 cartes.

Joueur 1 : Carte 1 + carte 2 + carte3 + carte 4 + carte 5
Joueur 2 : Carte 1 + carte 2 + carte3 + carte 4 + carte 5

Vous vérifiez qui gagne le point carte contre carte.

Le joueur qui cumule le plus de point sur le tirage a gagné.
*/

int main()
{
    default_random_engine moteur(time(0));
    uniform_int_distribution<int> distribution{ 2, 14 };
    

    int J1[5] = {};
    int J2[5] = {};
    int scoreJ1 = 0, scoreJ2 = 0;

    for(int i=0; i<5; i++){
        J1[i] = distribution(moteur);
        J2[i] = distribution(moteur);
    }

    for (int i = 0; i < 5; i++)
    {
        //cout << "Carte J1 : ";

        switch (J1[i])
        {
            case 11:
                cout << "Valet";
                break;
            case 12:
                cout << "Dame";
                break;
            case 13:
                cout << "Roi";
                break;
            case 14:
                cout << "As";
                break;

            default:
                cout << J1[i];
                break;
        }

        //cout << " vs Carte J2 : ";
        cout << " vs ";

        switch (J2[i])
        {
            case 11:
                cout << "Valet";
                break;
            case 12:
                cout << "Dame";
                break;
            case 13:
                cout << "Roi";
                break;
            case 14:
                cout << "As";
                break;

            default:
                cout << J2[i];
                break;
        }

        cout << endl;

        cout << "Resultat tour " << i+1 << endl;
        if (J1[i] == J2[i]){
            cout << "Egalite.\n" << endl;
        }
        else
        {
            J1[i] > J2[i] ? scoreJ1++ : scoreJ2++;
            cout << "Score J1 : " << scoreJ1 << " - ";
            printf_s("Score J2 : %d\n\n", scoreJ2);
        }
    }

    if(scoreJ1 > scoreJ2){
        cout << endl << "Victoire du Joueur 1." << endl;
    } else {
        cout << endl << "Victoire du Joueur 2." << endl;
    }

    system("pause");
    return 0;
}
