#include "Matrice.h"
#include <iostream>

int main() 
{
    Matrice A, B, C, nulle;
    A.saisir();
    B.saisir();
    A.afficher();
    nulle = Matrice::matrice_nulle(3, 3); 
    nulle.afficher();
    C = A-B;
    C.afficher();
    C = A+B;
    C.afficher();
    C = A*B;
    C.afficher();
    C = A.multiply(10);
    C.afficher();
    return 0;
}