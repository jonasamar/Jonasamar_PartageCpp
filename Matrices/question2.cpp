//-------------------------------------------------------------------------
//
// question 2 : Euler explicit
//
//-------------------------------------------------------------------------

#include <iostream>
#include <cmath>
#include "Matrix.h"
#include "question2.h"

float pi=3.14159265358979323846;

float D(float x)
{
    return 1.;
}

Matrix Euler_explicit(float dx, float dt, float tf)
{
    //discrétisation spatiale
    int N_x = int(1/dx) + 1; //il faut que x(N_x - 1) = (N_x - 1)dx <= 1 < (N_x)dx
    Matrix x;
    x = Matrix::matrice_nulle(1, N_x);
    for (int i=0; i<N_x - 1; i++)
    {
        x.change_coeff(0, i, i*dx);
    }
    x.change_coeff(0, N_x - 1, 1.);

    //x.afficher();
    //std::cout << "x contruit"<<std::endl;

    //discrétisation temporelle
    int N_tps = int(tf/dt) + 1; //il faut que t(N_tps - 1) = (N_tps - 1)dt <= 1 < (N_tps)dt
    Matrix t;
    t = Matrix::matrice_nulle(1, N_tps);
    for (int i=0; i<N_tps - 1; i++)
    {
        t.change_coeff(0, i, i*dt);
    }
    t.change_coeff(0, N_tps - 1, tf);

    //t.afficher();
    //std::cout << "t contruit"<<std::endl;

    //initialisation de la matrice des températures
    Matrix T;
    T = Matrix::matrice_nulle(N_x, N_tps);

    for (int i=1; i<N_x -1; i++) // on sait déjà que la première et dernière ligne sont des 0
    {
        T.change_coeff(i, 0, 0.5 + sin(2*pi*x.coeff(0,i)) - 0.5*cos(2*pi*x.coeff(0,i)));
    }

    //T.afficher();
    //std::cout << "T contruit"<<std::endl;


    //création de la matrice K
    Matrix K;
    K = Matrix::matrice_nulle(N_x, N_x);
    for (int i=0; i<N_x; i++)
    {
        for (int j=0; j<N_x; j++)
        {
            if (j == i - 1)
            {
                K.change_coeff(i, j, D(x.coeff(0, i))); 
            }
            if (j == i && i + 1 < N_x)
            {
                K.change_coeff(i, j, - D(x.coeff(0, i)) - D(x.coeff(0, i+1))); // (N_x - 1) + 1 sort de la taille de x...
            }
            if (j == i + 1 && i + 1 < N_x)
            {
                K.change_coeff(i, j, D(x.coeff(0, i + 1)));
            }
        }
    }

    //K.afficher();
    //std::cout << "K contruit"<<std::endl;

    //Euler explicit
    for (int k=0; k<N_tps - 1; k++) //il faut qu'au dernier passage k+1 = N_x - 1
    {
        //std::cout << k << " passages dans la boucle"<<std::endl;
        T.change_colonne(k+1, T.colonne(k) - K*T.colonne(k)*dt);
    }
    T.change_ligne(0, Matrix::matrice_nulle(N_tps, 1)); // T(0, t) = 0
    //std::cout << " bord 0 corrigé "<<std::endl;
    T.change_ligne(N_x - 1, Matrix::matrice_nulle(N_tps, 1)); // T(L, t) = 0
    //std::cout <<" bord 1 corrigé"<<std::endl;

    return T;
}


