#include "Matrice.h"
#include <iostream>
#include <vector>

void Matrice::setnb_lignes(int nb_lignes)
{
    this->nb_lignes = nb_lignes; 
}

void Matrice::setnb_colonnes(int nb_colonnes)
{
    this->nb_colonnes = nb_colonnes; 
}

void Matrice::setval(std::vector<std::vector<float> > val)
{
    this->val = val; 
}

void Matrice::saisir()
{
    float coeff;
    std::cout<<"Nombre de lignes de la matrice :"; std::cin >> nb_lignes;
    std::cout<<"Nombre de colonnes de la matrice :"; std::cin >> nb_colonnes;

    val.clear();
    for (int i=1; i<=nb_lignes; i++)
    {
        std::vector<float> ligne;
        ligne.clear();
        for (int j=1; j<=nb_colonnes; j++)
        {
            std::cout<<"Coefficient ("<<i<<","<<j<<") :"; std::cin >> coeff;
            ligne.push_back(coeff);
        }
        val.push_back(ligne);
    }

}

void Matrice::afficher()
{
    for (int i=0; i<nb_lignes; i++)
    {
        std::cout<<"|";
        for (int j=0; j<nb_colonnes; j++)
        {
            std::cout<<" "<<val[i][j]<<" ";
        }
        std::cout<<"|"<<std::endl;
    }
}

Matrice Matrice::matrice_nulle(int taille_y, int taille_x)
{
    Matrice Mat_nulle;
    Mat_nulle.nb_lignes = taille_x;
    Mat_nulle.nb_colonnes = taille_y;
    std::vector<float> ligne;
    ligne.clear();
    for(int j=0; j<taille_y; j++)
    {
        ligne.push_back(0.0);
    }
    for (int i=0; i<taille_x; i++)
    {
        Mat_nulle.val.push_back(ligne);
    }
    return Mat_nulle;
}

Matrice Matrice::operator+(const Matrice &M)
{
    if  (M.nb_lignes == nb_lignes && M.nb_colonnes == nb_colonnes) 
    {
        Matrice Somme;
        Somme = Matrice::matrice_nulle(nb_lignes, nb_colonnes);

        for(int i=0; i<nb_lignes; i++)
        {
            for (int j=0; j<nb_colonnes; j++)
            {
                Somme.val[i][j]=  M.val[i][j] + val[i][j] ;
            }
        }
           return Somme;
    }
    std::cout << " Impossible (la matrice retournée par défaut est la matrice de gauche)" << std::endl ;
    return M;
}

Matrice Matrice::operator-(const Matrice &M)
{
    if  (M.nb_lignes == nb_lignes && M.nb_colonnes == nb_colonnes) 
    {
        Matrice Diff;
        Diff = matrice_nulle(nb_lignes, nb_colonnes);

        for(int i=0; i<nb_lignes; i++)
        {
            for (int j=0; j<nb_colonnes; j++)
            {
                Diff.val[i][j]=  val[i][j] - M.val[i][j] ;
            }
        }
           return Diff;
    }
    std::cout << " Impossible (la matrice retournée par défaut est la matrice de gauche)" << std::endl ;
    return M;
}

Matrice Matrice::operator*(const Matrice &M)
{
    if  (M.nb_lignes == nb_colonnes) 
    {
        Matrice Prod;
        Prod = matrice_nulle(nb_lignes, M.nb_colonnes);

        for(int i=0; i<nb_lignes; i++)
        {
            
            for (int j=0; j<nb_colonnes; j++)
            {
                float coeff=0;
                for (int k=0; k<nb_colonnes; k++)
                {
                    coeff = coeff + val[i][k]*M.val[k][j];

                }
                Prod.val[i][j]=  coeff ;
            }
        }
           return Prod;
    }
    std::cout << " Impossible (la matrice retournée par défaut est la matrice de gauche)" << std::endl ;
    return M;
}

Matrice Matrice::multiply(const float lambda)
{
    Matrice Res;
    Res = Matrice::matrice_nulle(nb_lignes, nb_colonnes);

    for(int i=0; i<nb_lignes; i++)
    {
        for (int j=0; j<nb_colonnes; j++)
        {
            Res.val[i][j]=  lambda* val[i][j];
        }
    }
    return Res;
}
