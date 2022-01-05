#include "Matrice.h"
#include <iostream>
#include <vector>
#include <cmath>

Matrice::Matrice(){}

Matrice::Matrice(const int &l, const int &c, const std::vector<std::vector<float> > &mat) : nb_lignes(l), nb_colonnes(c), val(mat){}

Matrice::~Matrice(){}

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
    std::vector<float> ligne;
    std::vector<std::vector<float> > mat;

    ligne.clear();
    for(int j=0; j<taille_x; j++)
    {
        ligne.push_back(0.0);
    }

    mat.clear();
    for (int i=0; i<taille_y; i++)
    {
        mat.push_back(ligne);
    }

    Matrice Mat_nulle(taille_y, taille_x, mat);
    return Mat_nulle;
}

Matrice Matrice::matrice_identite(int taille)
{
    Matrice identite;
    identite = Matrice::matrice_nulle(taille, taille);
    
    for(int i=0; i<taille; i++)
    {
        identite.val[i][i] = 1.0;
    }
    return identite;
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
        Diff = Matrice::matrice_nulle(nb_lignes, nb_colonnes);

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
        Prod = Matrice::matrice_nulle(nb_lignes, M.nb_colonnes);
        //Prod.afficher();

        for(int i=0; i<nb_lignes; i++)
        {
            for (int j=0; j<M.nb_colonnes; j++)
            {
                for (int k=0; k<nb_colonnes; k++)
                {
                    Prod.val[i][j] = Prod.val[i][j] + val[i][k]*M.val[k][j];
                }
                //std::cout<<Prod.val[i][j]<<std::endl;
            }
        }
           return Prod;
    }
    std::cout << " Impossible (la matrice retournée par défaut est la matrice de gauche)" << std::endl ;
    return M;
}

Matrice Matrice::operator*(const float &lambda)
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


void Matrice::operator=(const Matrice &M)
{
    nb_lignes = M.nb_lignes;
    nb_colonnes = M.nb_colonnes;
    val = M.val;

}

Matrice Matrice::operator^(const int &n)
{
    Matrice mat(nb_lignes, nb_colonnes, val);
    Matrice Res;
    Res = mat;

    for(int i=0; i<n; i++)
    {
        Res = Res*mat;
    }

    return Res;
}

Matrice Matrice::T()
{
    Matrice transpose;
    transpose = Matrice::matrice_nulle(nb_colonnes, nb_lignes);
    //transpose.afficher();

    for(int i=0; i<nb_lignes; i++)
    {
        for (int j=0; j<nb_colonnes; j++)
        {
            transpose.val[j][i]=  val[i][j];
        }
    }
    return transpose;
}

float Matrice::Trace()
{
    if (nb_lignes == nb_colonnes)
    {
        float trace=0;

        for(int i=0; i<nb_lignes; i++)
        {
            trace = trace + val[i][i];
        }
        return trace;
    }
    std::cout<<"La matrice n'est pas carrée ! (la valeur retournée par défaut est 0)"<< std::endl;
    return 0;
}

float Matrice::norme()
{
    return sqrt(((*this).T()*(*this)).val[0][0]);
}