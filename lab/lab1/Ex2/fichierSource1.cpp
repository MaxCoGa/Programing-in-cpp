#include <iostream>
#include "fichierEntete.h"

int main(int argc, char* argv[])
{
    // Verifier que le nombre de parametres est 2,
    // plus le nom du programme appele,
    // donc argc doit etre egal a 3, Sinon afficher message d'erreur et sortir
    if (argc != 3) {
        std::cerr << "Le programme prend deux entiers comme arguments" << std::endl;

        return 1;
    }

    // A ce niveau, je sais que argc est egal a 3, et argv contient trois chaines de caracteres
    // argv[0] contient le nom du programme appele
    int v1, v2;
    v1 = atoi(argv[1]); // atoi permet de convertir une chaine de caracteres a un entier
    v2 = atoi(argv[2]);

    // use smaller number as lower bound // for printing the range
    // and larger number as upper bound
    int lower, upper;
    if (v1 <= v2) {
       lower = v1;
       upper = v2;
    } else {
       lower = v2;
       upper = v1;
    }

    affiche(lower, upper);

    return 0;
}

