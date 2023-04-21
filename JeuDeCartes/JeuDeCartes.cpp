#include <iostream>
#include <random>
#include <string>
using namespace std;

/*
CREER UN JEU DE 52 CARTES

Votre programme propose un tirage aléatoire de 2 x 5 cartes.

Joueur 1 : Carte 1 + carte 2 + carte3 + carte 4 + carte 5
Joueur 2 : Carte 1 + carte 2 + carte3 + carte 4 + carte 5

Vous vérifiez qui gagne le point carte contre carte.

Le joueur qui cumule le plus de point sur le tirage a gagné.
*/

string carte(int value)
{
    switch (value)
    {
        case 11:
            return "Valet";
        case 12:
            return "Dame";
        case 13:
            return "Roi";
        case 14:
            return "As";

        default:
            return to_string(value);
    }
}

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

    cout << "Tirage J1 : " << "{" << carte(J1[0]) << " - " << carte(J1[1]) << " - " << carte(J1[2]) << " - " << carte(J1[3]) << " - " << carte(J1[4]) << "}" << endl;
    cout << "Tirage J2 : " << "{" << carte(J2[0]) << " - " << carte(J2[1]) << " - " << carte(J2[2]) << " - " << carte(J2[3]) << " - " << carte(J2[4]) << "}" << endl << endl;


    for (int i = 0; i < 5; i++)
    {
        cout << endl << "Resultat tour " << i+1 << endl;
        cout << carte(J1[i]) << " vs " << carte(J2[i]) << endl;

        if (J1[i] == J2[i]){
            cout << "Egalite." << endl << endl;
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
