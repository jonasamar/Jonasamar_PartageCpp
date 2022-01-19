//-------------------------------------------------------------------------
//
// On remarque que Euler implicite est systématiquement plus lent que Euler
// explicite (ce qui est logique étant donné que l'un nécessite l'appel de
// Pivot de Gauss à chauque itération)
//
//-------------------------------------------------------------------------


#include <iostream>
#include <cstring>
#include <chrono>
#include "Matrix.h"
#include "tests_q1.h"
#include "question2.h"
#include "question3.h"
#include "question4.h"

int main() 
{
    int choix =1; //on initialise à une valeur non nulle
    while (choix !=0)
    {
        system("clear");
        std::cout<<""<<std::endl;
        std::cout<<"Menu"<<std::endl;
        std::cout<<""<<std::endl;
        std::cout<<"    (1) Tester la classe Matrix"<<std::endl;
        std::cout<<"    (2) Tester la fonction Pivot de Gauss (Résolution de Ax = b)"<<std::endl;
        std::cout<<"    (3) Créer un nouveau fichier des températures calculées avec Euler explicite"<<std::endl;
        std::cout<<"    (4) Créer un nouveau fichier des températures calculées avec Euler implicite"<<std::endl;
        std::cout<<"    (5) Comparer le temps d'execution d'Euler explicite et implicite"<<std::endl;
        std::cout<<"    (0) Sortie"<<std::endl;
        std::cout<<""<<std::endl;
        std::cout<<"Que souhaitez-vous faire ? (Entrez 0, 1, 2, 3, 4, ou 5)"<<std::endl;
        std::cout<<"    -> "; std::cin >> choix;

        char rep[3];

        //question 1
        
        if (choix == 1)
        {
            system("clear");
            std::cout << "Tests de la classe Matrix"<<std::endl;
            std::cout<<""<<std::endl;

            tests_q1();

            std::cout<<""<<std::endl;
            std::cout<<"Options"<<std::endl;
            std::cout<<"    (0) Sortie"<<std::endl;
            std::cout<<"    (1) Retourner au Menu"<<std::endl;
            std::cout<<""<<std::endl;
            std::cout<<"    -> "; std::cin >> choix;
        }


        //question 2 et bonnus 1
        if (choix == 3)
        {
            system("clear");
            std::cout << "Création d'un nouveau fichier des températures calculées avec Euler explicite"<<std::endl;
            std::cout<<""<<std::endl;

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
            std::cout<<""<<std::endl;
            if (std::string(rep) != "rdm" && std::string(rep) != "cst")
            {
                std::cout << "Réponse non adaptée (mode par défaut cst)";
                std::string cst = "cst";
                std::cout<<""<<std::endl;
                strcpy(rep, cst.c_str()); // rep = "cst"
            }

            std::cout << "Pas d'espace, dx = "; std::cin >> dx;
            std::cout << "Pas temporel, dt = "; std::cin >> dt;
            T = Euler_explicite(dx, dt, tf, L, rep);
            std::cout<<""<<std::endl;
            std::cout << "Nom du nouveau fichier créé : "; std::cin >> file_name;
            T.WriteToFile(file_name + methode);

            std::cout<<""<<std::endl;
            std::cout<<"Options"<<std::endl;
            std::cout<<"    (0) Sortie"<<std::endl;
            std::cout<<"    (1) Retourner au Menu"<<std::endl;
            std::cout<<""<<std::endl;
            std::cout<<"    -> "; std::cin >> choix;
        }

        //question 3
        if (choix == 2)
        {
            std::cout << "Test de la fonction Pivot de Gauss (Résolution de Ax = b)"<<std::endl;
            std::cout<<""<<std::endl;

            Matrix A, b, x;
            std::cout << "Saisir la matrice A (choisir A inversible): " <<std::endl;
            A.saisir();
            std::cout<<""<<std::endl;

            std::cout << "Saisir la matrice b (choisir un vecteur colonne de même taille que A):" <<std::endl;
            b.saisir();
            std::cout<<""<<std::endl;

            x = Pivot_Gauss(A, b);
            std::cout << "Solution x = " <<std::endl;
            x.afficher();
            std::cout << "Vérification :\nAx = " <<std::endl;
            (A*x).afficher();
            std::cout << "et b = " <<std::endl;
            b.afficher();

            std::cout<<""<<std::endl;
            std::cout<<"Options"<<std::endl;
            std::cout<<"    (0) Sortie"<<std::endl;
            std::cout<<"    (1) Retourner au Menu"<<std::endl;
            std::cout<<""<<std::endl;
            std::cout<<"    -> "; std::cin >> choix;
        }

        //question 4 et bonnus 1
        if (choix == 4)
        {
            std::cout << "Création d'un nouveau fichier des températures calculées avec Euler implicite"; std::cin >> rep;
            std::cout<<""<<std::endl;

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
            std::cout<<""<<std::endl;
     
            if (std::string(rep) != "rdm" && std::string(rep) != "cst")
            {
                std::cout << "Réponse non adaptée (mode par défaut cst)";
                std::string cst = "cst";
                std::cout<<""<<std::endl;
                strcpy(rep, cst.c_str()); // rep = "cst"
            }

            std::cout << "Pas d'espace, dx = "; std::cin >> dx;
            std::cout << "Pas temporel, dt = "; std::cin >> dt;
            std::cout<<""<<std::endl;

            T = Euler_implicite(dx, dt, tf, L, rep);
            std::cout << "Nom du nouveau fichier créé : "; std::cin >> file_name;
            T.WriteToFile(file_name + methode);

            std::cout<<""<<std::endl;
            std::cout<<"Options"<<std::endl;
            std::cout<<"    (0) Sortie"<<std::endl;
            std::cout<<"    (1) Retourner au Menu"<<std::endl;
            std::cout<<""<<std::endl;
            std::cout<<"    -> "; std::cin >> choix;   
        }

        //question bonnus 2 (début...)
        if (std::string(rep) == "oui")
        {
            
            std::cout << "Comparaison du temps d'execution de Euler explicite et Euler implicite"<<std::endl;
            std::cout<<""<<std::endl;

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
            std::cout<<""<<std::endl;
            std::cout << "Temps d'execution : "<<std::endl;

            std::chrono::time_point<std::chrono::system_clock> start1 = std::chrono::system_clock::now();
            Euler_explicite(dx, dt, tf, L, rep);
            std::chrono::time_point<std::chrono::system_clock> stop1 = std::chrono::system_clock::now();
            int duration1 = std::chrono::duration_cast<std::chrono::seconds>(stop1 - start1).count();
            std::cout << " -> Euler explicite : "<< duration1 << "s"<<std::endl;

            std::chrono::time_point<std::chrono::system_clock> start2 = std::chrono::system_clock::now();
            Euler_implicite(dx, dt, tf, L, rep);
            std::chrono::time_point<std::chrono::system_clock> stop2 = std::chrono::system_clock::now();
            int duration2 = std::chrono::duration_cast<std::chrono::seconds>(stop2 - start2).count();
            std::cout << " -> Euler implicite : "<< duration1 << "s"<<std::endl;

            std::cout<<""<<std::endl;
            std::cout<<"Options"<<std::endl;
            std::cout<<"    (0) Sortie"<<std::endl;
            std::cout<<"    (1) Retourner au Menu"<<std::endl;
            std::cout<<""<<std::endl;
            std::cout<<"    -> "; std::cin >> choix; 
        }

    }

    return 0;
}