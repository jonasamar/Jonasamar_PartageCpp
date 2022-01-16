//-------------------------------------------------------------------------
//
// Aucun des tests réalisés pour représenter T(x,t) n'a été satisfaisant 
// en raison de la possible erreur dans le sujet (ou mauvaise compréhension
// de ma part) que j'expose dans la fonction Euler_explicite (question2)
//
//-------------------------------------------------------------------------

#include "Matrix.h"
#include <iostream>
#include <cstring>
#include <chrono>
#include "tests_q1.h"
#include "question2.h"
#include "question3.h"
#include "question4.h"

int main() 
{
    char rep[3];

    //question 1
    std::cout << "Voulez-vous tester les opérations de la classe Matrix ? (oui/non) : "; std::cin >> rep;
    if (std::string(rep) == "oui")
    {
        tests_q1();
    }

    std::cout<<""<<std::endl;
    std::cout<<""<<std::endl;

    //question 2 et bonnus 1
    std::cout << "Voulez-vous créer un nouveau fichier des températures calculées avec Euler explicite (T(x,t)) ? (oui/non) : "; std::cin >> rep;
    if (std::string(rep) == "oui")
    {
        Matrix T;
        float dt, dx, L = 1., tf = 0.05;
        std::string file_name;
        std::string methode = "_Euler_explicite.txt";

        std::cout << "tf = 0.05s par défaut, souhaitez vous modifier cette valeur ? (oui/non) : "; std::cin >> rep;
        if (std::string(rep) == "oui")
        {
            std::cout << "tf = "; std::cin >> tf;
        }
        std::cout << "L = 1.0m par défaut, souhaitez vous modifier cette valeur ? (oui/non) : "; std::cin >> rep;
        if (std::string(rep) == "oui")
        {
            std::cout << "L = "; std::cin >> L;
        }
        std::cout<<""<<std::endl;
        std::cout << "Choisir un mode:" << std::endl;
        std::cout<<" -> cst : D(x) = 1. pour tout x"<< std::endl;
        std::cout<<" -> rdm : D(x) aléatoire entre 0.5 et 1.5"<<std::endl; 
        std::cout<<"mode : "; std::cin >> rep;       
        if (std::string(rep) != "rdm" && std::string(rep) != "cst")
        {
            std::cout << "Réponse non adaptée (mode par défaut cst)";
            std::string cst = "cst";
            strcpy(rep, cst.c_str()); // rep = "cst"
        }

        std::cout << "Pas d'espace, dx = "; std::cin >> dx;
        std::cout << "Pas temporel, dt = "; std::cin >> dt;
        T = Euler_explicite(dx, dt, tf, L, rep);
        std::cout << "Nom du nouveau fichier créé : "; std::cin >> file_name;
        T.WriteToFile(file_name + methode);
    }

    std::cout<<""<<std::endl;
    std::cout<<""<<std::endl;

    //question 3
    std::cout << "Voulez-vous tester la fonction pivot de Gauss (pour résoudre Ax = b) ? (oui/non) : "; std::cin >> rep;
    if (std::string(rep) == "oui")
    {
        Matrix A, b, x;
        std::cout << "Saisir la matrice A (choisir A inversible): " <<std::endl;
        A.saisir();
        std::cout << "Saisir la matrice b (choisir un vecteur colonne de même taille que A): " <<std::endl;
        b.saisir();

        x = Pivot_Gauss(A, b);
        std::cout << "Solution x = " <<std::endl;
        x.afficher();
        std::cout << "Vérification :\nAx = " <<std::endl;
        (A*x).afficher();
        std::cout << "et b = " <<std::endl;
        b.afficher();
    }

    std::cout<<""<<std::endl;
    std::cout<<""<<std::endl;

    //question 4 et bonnus 1
    std::cout << "Voulez-vous créer un nouveau fichier des températures (T(x,t)) calculées avec Euler implicite ? (oui/non) : "; std::cin >> rep;
    if (std::string(rep) == "oui")
    {
        Matrix T;
        float dt, dx, L = 1., tf = 0.05;
        std::string file_name;
        std::string methode = "_Euler_implicite.txt";

        std::cout << "tf = 0.05s par défaut, souhaitez vous modifier cette valeur ? (oui/non) : "; std::cin >> rep;
        if (std::string(rep) == "oui")
        {
            std::cout << "tf = "; std::cin >> tf;
        }
        std::cout << "L = 1.0m par défaut, souhaitez vous modifier cette valeur ? (oui/non) : "; std::cin >> rep;
        if (std::string(rep) == "oui")
        {
            std::cout << "L = "; std::cin >> L;
        }
        std::cout<<""<<std::endl;
        std::cout << "Choisir un mode:" << std::endl;
        std::cout<<" -> cst : D(x) = 1. pour tout x"<< std::endl;
        std::cout<<" -> rdm : D(x) aléatoire entre 0.5 et 1.5"<<std::endl;
        std::cout<<"mode : "; std::cin >> rep;       
        if (std::string(rep) != "rdm" && std::string(rep) != "cst")
        {
            std::cout << "Réponse non adaptée (mode par défaut cst)";
            std::string cst = "cst";
            strcpy(rep, cst.c_str()); // rep = "cst"
        }

        std::cout << "Pas d'espace, dx = "; std::cin >> dx;
        std::cout << "Pas temporel, dt = "; std::cin >> dt;
        T = Euler_implicite(dx, dt, tf, L, rep);
        std::cout << "Nom du nouveau fichier créé : "; std::cin >> file_name;
        T.WriteToFile(file_name + methode);
    }

    std::cout<<""<<std::endl;
    std::cout<<""<<std::endl;

    //question bonnus 2 (début...)
    std::cout << "Voulez-vous comparer le temps d'execution de Euler_implicite et Euler_explicite ? (oui/non) : "; std::cin >> rep;
    if (std::string(rep) == "oui")
    {
        Matrix T;
        float dt, dx, L = 1., tf = 0.05;
        std::string file_name;
        std::string methode = "_Euler_implicite.txt";

        std::cout << "tf = 0.05s par défaut, souhaitez vous modifier cette valeur ? (oui/non) : "; std::cin >> rep;
        if (std::string(rep) == "oui")
        {
            std::cout << "tf = "; std::cin >> tf;
        }
        std::cout << "L = 1.0m par défaut, souhaitez vous modifier cette valeur ? (oui/non) : "; std::cin >> rep;
        if (std::string(rep) == "oui")
        {
            std::cout << "L = "; std::cin >> L;
        }
        std::cout<<""<<std::endl;
        std::cout << "Choisir un mode:" << std::endl;
        std::cout<<" -> cst : D(x) = 1. pour tout x"<< std::endl;
        std::cout<<" -> rdm : D(x) aléatoire entre 0.5 et 1.5"<<std::endl;
        std::cout<<"mode : "; std::cin >> rep;       
        if (std::string(rep) != "rdm" && std::string(rep) != "cst")
        {
            std::cout << "Réponse non adaptée (mode par défaut cst)";
            std::string cst = "cst";
            strcpy(rep, cst.c_str()); // rep = "cst"
        }

        std::cout << "Pas d'espace, dx = "; std::cin >> dx;
        std::cout << "Pas temporel, dt = "; std::cin >> dt;
        auto start1 = std::chrono::high_resolution_clock::now();
        Euler_implicite(dx, dt, tf, L, rep);
        auto stop1 = std::chrono::high_resolution_clock::now();
        auto start2 = std::chrono::high_resolution_clock::now();
        Euler_explicite(dx, dt, tf, L, rep);
        auto stop2 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::seconds>(stop1 - start1);
        auto duration2 = std::chrono::duration_cast<std::chrono::seconds>(stop2 - start2);

        std::cout << "Temps d'execution : "<<std::endl;
        std::cout << " -> Euler implicite : "<< duration1.count() << "s"<<std::endl;
        std::cout << " -> Euler explicite : "<< duration2.count() << "s"<<std::endl;
    }

    return 0;
}