#include "Matrix.h"
#include <iostream>
#include "tests_q1.h"
#include "question2.h"

int main() 
{
    char rep[3];

    std::cout << "Voulez-vous tester les opérations de la classe Matrix ? (oui/non) : "; std::cin >> rep;
    if (std::string(rep) == "oui")
    {
        tests_q1();
    }

    std::cout << "Voulez-vous créer un nouveau fichier des températures (T(x,t)) ? (oui/non) : "; std::cin >> rep;
    if (std::string(rep) == "oui")
    {
        Matrix T;
        float dt, dx, tf = 0.05;
        std::string file_name;

        std::cout << "Pas d'espace, dx = "; std::cin >> dx;
        std::cout << "Pas temporel, dt = "; std::cin >> dt;
        T = Euler_explicit(dx, dt, tf);
        std::cout << "Nom du nouveau fichier créé : "; std::cin >> file_name;
        T.WriteToFile(file_name);
    }
    return 0;
}