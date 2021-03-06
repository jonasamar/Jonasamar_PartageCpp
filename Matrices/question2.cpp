//-------------------------------------------------------------------------
//
// question 2 : Euler explicit
//
//-------------------------------------------------------------------------

#include <iostream>
#include <cmath>
#include <random>
#include "Matrix.h"
#include "Matrix_creux.h"
#include "question2.h"

float pi=3.14159265358979323846;


Matrix d(int N, char * mode)  //on peut étoffer d avec d'autres modes
{
    Matrix D;
    D = Matrix::nulle(N, 1);
    if (std::string(mode) == "cst") //création d'une matrice Nx1 remplie de 1.
    {
        for (int i=0; i<N; i++)
        {
            D.change_coeff(i, 0, 1.);
        }
    }
    if (std::string(mode) == "rdm") //création d'une matrice Nx1 remplie de valeurs aléatoires entre 0.5 et 1.5
    {
        std::random_device rd;  
        std::mt19937 gen(rd()); 
        std::uniform_real_distribution<> dis(0.5, 1.5);
        for (int i=0; i<N; i++)
        {
            D.change_coeff(i, 0, dis(gen));
        }
    }
    return D;
}

Matrix Euler_explicite(float dx, float dt, float tf, float L, char * mode, int choix) 
{
    if (choix == 1) // choix de la classe Matrix
    {
        //discrétisation spatiale
        Matrix x;
        x = Matrix::graduation(dx, 0., L);
        int N_x = x.getnb_lignes();

        //discrétisation temporelle
        int N_tps = int(tf/dt) + 1; //il faut que t(N_tps - 1) = (N_tps - 1)dt <= tf < (N_tps)dt

        //initialisation de la matrice des températures
        Matrix T;
        T = Matrix::nulle(N_x, N_tps);

        for (int i=1; i<N_x -1; i++) // on sait déjà que la première et dernière ligne sont des 0
        {
            T.change_coeff(i, 0, 0.5 + sin(2*pi*x.coeff(i,0)) - 0.5*cos(2*pi*x.coeff(i,0)));
        }

        //création de la matrice K
        Matrix D, K;
        D = d(N_x + 1, mode); // (N_x - 1) + 1 doit être bien défini
        K = Matrix::nulle(N_x, N_x);
        for (int i=0; i<N_x; i++)
        {
            for (int j=0; j<N_x; j++)
            {
                if (j == i - 1)
                {
                    K.change_coeff(i, j, D.coeff(i, 0)/(dx*dx)); 
                }
                if (j == i) 
                {
                    K.change_coeff(i, j, (- D.coeff(i, 0) - D.coeff(i+1, 0))/(dx*dx)); 
                }
                if (j == i + 1)
                {
                    K.change_coeff(i, j, D.coeff(i + 1, 0)/(dx*dx));
                }
            }
        }

        //Euler explicit
        for (int k=0; k<N_tps - 1; k++) //il faut qu'au dernier passage k+1 = N_tps - 1
        {
            T.change_colonne(k+1, T.colonne(k) + K*T.colonne(k)*(dt));
            T.change_coeff(0, k+1, 0.); // T(0, t) = 0
            T.change_coeff(N_x - 1, k+1, 0.); // T(L, t) = 0
        }
        return T;
    }   
    else //choix == 2 ie classe Matrix
    {
        //discrétisation spatiale
        Matrix x;
        x = Matrix::graduation(dx, 0., L); //pas de réel intérêt à considérer une Matrice creuse ici... (1 seule valeur nulle)
        int N_x = x.getnb_lignes();

        //discrétisation temporelle
        int N_tps = int(tf/dt) + 1; //il faut que t(N_tps - 1) = (N_tps - 1)dt <= tf < (N_tps)dt

        //initialisation de la matrice des températures
        Matrix_creux T;
        T = Matrix_creux::nulle(N_x, N_tps);

        for (int i=1; i<N_x -1; i++) // on sait déjà que la première et dernière ligne sont des 0
        {
            T.change_coeff(i, 0, 0.5 + sin(2*pi*x.coeff(i,0)) - 0.5*cos(2*pi*x.coeff(i,0)));
        }

        //création de la matrice K
        Matrix_creux K;
        Matrix D; //on continue de créer D comme avec Matrix car elle ne contient qu'un coeff nul 
                  //(pas de réel intérêt à utiliser Matrix_creux)
        D = d(N_x + 1, mode); // (N_x - 1) + 1 doit être bien défini
        K = Matrix_creux::nulle(N_x, N_x);
        for (int i=0; i<N_x; i++)
        {
            for (int j=0; j<N_x; j++)
            {
                if (j == i - 1)
                {
                    K.change_coeff(i, j, D.coeff(i, 0)/(dx*dx)); 
                }
                if (j == i) 
                {
                    K.change_coeff(i, j, (- D.coeff(i, 0) - D.coeff(i+1, 0))/(dx*dx)); 
                }
                if (j == i + 1)
                {
                    K.change_coeff(i, j, D.coeff(i + 1, 0)/(dx*dx));
                }
            }
        }

        //Euler explicit
        for (int k=0; k<N_tps - 1; k++) //il faut qu'au dernier passage k+1 = N_tps - 1
        {
            T.change_colonne(k+1, T.colonne(k) + K*T.colonne(k)*(dt));
            T.change_coeff(0, k+1, 0.); // T(0, t) = 0
            T.change_coeff(N_x - 1, k+1, 0.); // T(L, t) = 0
        }
        return T.convert_to_Matrix();
    }
}


