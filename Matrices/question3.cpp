//-------------------------------------------------------------------------
//
// question 3 : Choix du pivot de Gauss pour résoudre Ax = b
//              Hypothèse faite : on suppose qu'on tombera quasiment toujours
//                                sur des matrices inversibles
//
//-------------------------------------------------------------------------

#include "Matrix.h"

Matrix Pivot_Gauss(Matrix A, Matrix b) //on travaille ici avec des copies de A et b donc on peut se permettre de les modifier
{
    int n = A.getnb_lignes();

    Matrix M;
    M = Matrix::nulle(n, n+1);
    for (int i=0;i < n; i++)
    {
        M.change_colonne(i, A.colonne(i));
    }
    M.change_colonne(n, b);

    for (int i=0;i < n; i++)
    {
        //on cherche un coefficient de la colonne i qui soit non nul
        int j = i;
        while (M.coeff(j,i) == 0.)
        {
            j++;
        }

        //on échange la ligne i et j
        Matrix ligne_j;
        ligne_j = M.ligne(j);
        M.change_ligne(j, M.ligne(i));
        M.change_ligne(i, ligne_j);

        //M.afficher();

        //on normalise la ligne i par rapport au coefficient (i,i) 
        //et on annule tous les autres coefficients de la colonne i de la matrice M
        M.change_ligne(i, M.ligne(i)*(1/M.coeff(i,i)));

        //M.afficher();

        for (int k=0; k<n;  k++)
        {
            if (k != i)
            {
                M.change_ligne(k, M.ligne(k) - M.ligne(i)*M.coeff(k, i));
            }
        }
    }

    return M.colonne(n);
}