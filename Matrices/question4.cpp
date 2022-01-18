//-------------------------------------------------------------------------
//
// question 4 : Euler implicite
//
//-------------------------------------------------------------------------

#include <cmath>
#include "Matrix.h"
#include "question2.h" //pour récupérer la fonction d
#include "question3.h" //pour récupérer le pivot de gauss

float _pi=3.14159265358979323846;

Matrix Euler_implicite(float dx, float dt, float tf, float L, char * mode)
{
    //discrétisation spatiale
    Matrix x;
    x = Matrix::graduation(dx,0., L);
    int N_x = x.getnb_lignes();

    //discrétisation temporelle
    int N_tps = int(tf/dt) + 1; //il faut que t(N_tps - 1) = (N_tps - 1)dt <= tf < (N_tps)dt

    //initialisation de la matrice des températures
    Matrix T;
    T = Matrix::nulle(N_x, N_tps);

    for (int i=1; i<N_x -1; i++) // on sait déjà que la première et dernière ligne sont des 0
    {
        T.change_coeff(i, 0, 0.5 + sin(2*_pi*x.coeff(i,0)) - 0.5*cos(2*_pi*x.coeff(i,0)));
    }

    //création de la matrice K
    Matrix K, D;
    D = d(N_x + 1, mode); // (N_x - 1) + 1 doit être défini
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

    //Euler implicite
    for (int k=0; k<N_tps - 1; k++) //il faut qu'au dernier passage k+1 = N_tps - 1
    {
        T.change_colonne(k+1, Pivot_Gauss(Matrix::identite(N_x) - K*dt, T.colonne(k)));
        T.change_coeff(0, k+1, 0.); // T(0, t) = 0
        T.change_coeff(N_x - 1, k+1, 0.); // T(L, t) = 0
    }

    return T;
}