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

string couleur(int value)
{
    string couleur;
    couleur = value;
    return couleur;
}


int main()
{
    default_random_engine moteur(time(0));
    uniform_int_distribution<int> distribution{ 2, 14 };
    uniform_int_distribution<int> couleurCartes{ 3, 6 };
    const int taille = 5;
    

    int J1[taille] = {};
    int J2[taille] = {};
    int J1couleur[taille] = {};
    int J2couleur[taille] = {};
    int scoreJ1 = 0, scoreJ2 = 0;

    for(int i = 0; i < taille; i++){
        J1[i] = distribution(moteur);
        J2[i] = distribution(moteur);
        J1couleur[i] = couleurCartes(moteur);
        J2couleur[i] = couleurCartes(moteur);

        for (int j = 0; j < i; j++)
        {
            if ((J1[i] == J1[j] && J1couleur[i] == J1couleur[j]) || (J1[i] == J2[j] && J1couleur[i] == J2couleur[j]))
            {
                i--;
            }

            if ((J2[i] == J2[j] && J2couleur[i] == J2couleur[j]) || (J2[i] == J1[j] && J2couleur[i] == J1couleur[j]))
            {
                i--;
            }
        }
    }

    cout << "Tirage J1 : " << "{";
    for(int i=0; i<taille; i++){
        cout << carte(J1[i]) << couleur(J1couleur[i]);

        if (i != taille-1){
            cout << " - ";
        }
    }
    cout << "}" << endl;

    cout << "Tirage J2 : " << "{";
    for (int i = 0; i < taille; i++)
    {
        cout << carte(J2[i]) << couleur(J2couleur[i]);

        if (i != taille - 1)
        {
            cout << " - ";
        }
    }
    cout << "}" << endl;

    for (int i = 0; i < taille; i++)
    {
        cout << endl << "Resultat tour " << i+1 << endl;
        cout << carte(J1[i]) << couleur(J1couleur[i]) << " vs " << carte(J2[i]) << couleur(J2couleur[i]) << endl;

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
        cout << endl << "Victoire du Joueur 1 !" << endl;
    } else if (scoreJ2 > scoreJ1)  {
        cout << endl << "Victoire du Joueur 2 !" << endl;
    } else {
        cout << "Egalite !" << endl;
    }

    system("pause");
    return 0;
}
