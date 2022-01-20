//-------------------------------------------------------------------------
//
// Tests des différentes opérations sur les matrices correspondant à la 
// question 1 du sujet.
//
//-------------------------------------------------------------------------

#include <iostream>
#include "Matrix.h"
#include "Matrix_creux.h"
#include "tests_class.h"

void tests_class(int choix)
{
    float lambda;
    if (choix ==1)
    {
        Matrix A, B, ligne, colonne;
        std::cout << "Matrix A" << std::endl;
        A.saisir();
        std::cout << "Matrix B" << std::endl;
        B.saisir();
        std::cout << "A = " << std::endl;
        A.afficher();
        std::cout << "B = " << std::endl;
        B.afficher();
        std::cout << "Transposée de B = " << std::endl;
        (B.T()).afficher();
        std::cout << "2A - B = " << std::endl;
        (A*2-B).afficher();
        std::cout << "A + B = " << std::endl;
        (A+B).afficher();
        std::cout << "A - B = " << std::endl;
        (A-B).afficher();
        std::cout << "A*B = "<< std::endl;
        (A*B).afficher();
        std::cout<<"valeur de lambda : "; std::cin >> lambda;
        std::cout << lambda << "A = " << std::endl;
        (A*lambda).afficher();
        std::cout << "1ere ligne de A = " << std::endl;
        (A.ligne(1)).afficher();
        std::cout << "0eme colonne de B = " << std::endl;
        (B.colonne(0)).afficher();
        std::cout << "changement de B : 1ere ligne B <- 1ere ligne de A = " << std::endl;
        B.change_ligne(1, A.ligne(1));
        B.afficher();
    }
    if (choix ==2) //je mets un if et non un else pour des éventuels ajouts de choix
    {
        Matrix_creux A, B, ligne, colonne;
        std::cout << "Matrix A" << std::endl;
        A.saisir();
        std::cout << "Matrix B" << std::endl;
        B.saisir();
        std::cout << "A = " << std::endl;
        A.afficher();
        std::cout << "B = " << std::endl;
        B.afficher();
        std::cout << "Transposée de B = " << std::endl;
        (B.T()).afficher();
        std::cout << "2A - B = " << std::endl;
        (A*2-B).afficher();
        std::cout << "A + B = " << std::endl;
        (A+B).afficher();
        std::cout << "A - B = " << std::endl;
        (A-B).afficher();
        std::cout << "A*B = "<< std::endl;
        (A*B).afficher();
        std::cout<<"valeur de lambda : "; std::cin >> lambda;
        std::cout << lambda << "A = " << std::endl;
        (A*lambda).afficher();
        std::cout << "1ere ligne de A = " << std::endl;
        (A.ligne(1)).afficher();
        std::cout << "0eme colonne de B = " << std::endl;
        (B.colonne(0)).afficher();
        std::cout << "changement de B : 1ere ligne B <- 1ere ligne de A = " << std::endl;
        B.change_ligne(1, A.ligne(1));
        B.afficher();
    }
    
}