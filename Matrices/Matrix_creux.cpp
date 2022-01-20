//-------------------------------------------------------------------------
//
// Classe Matrix_creux (.cpp)
// Pour éviter toute confusion, on gardera les mêmes conventions que pour 
// la classe Matrix (ie que les indexations commencent par 0)
//
//-------------------------------------------------------------------------

#include "Matrix_creux.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

// constructeurs :
Matrix_creux::Matrix_creux(){};
Matrix_creux::Matrix_creux(const int &l, const int &c, const std::vector<float> &mat, const std::vector<int> &indice_l, const std::vector<int> &indice_c) : nb_lignes(l), nb_colonnes(c), val(mat), I(indice_l), J(indice_c){};


//destructeur :
Matrix_creux::~Matrix_creux(){};


// set attributs des matrices:
void Matrix_creux::setnb_lignes(int nb_lignes)
{
    this->nb_lignes = nb_lignes; 
}

void Matrix_creux::setnb_colonnes(int nb_colonnes)
{
    this->nb_colonnes = nb_colonnes; 
}

void Matrix_creux::setval(std::vector<float> val)
{
    this->val = val; 
}

void Matrix_creux::setI(std::vector<int> I)
{
    this->I = I; 
}

void Matrix_creux::setJ(std::vector<int> J)
{
    this->J = J; 
}

void Matrix_creux::change_coeff(int i, int j, float new_coeff)
{
    int k=0;

    if (i< nb_lignes && j<nb_colonnes && new_coeff != 0.)
    {
        while (k<I.size() && (I[k] != i || J[k] != j))
        {
            k++;
        }
        if (k == I.size())
        {
            val.push_back(new_coeff);
            I.push_back(i);
            J.push_back(j);
        }
        else
        {
            val[k] = new_coeff;
        }
    }
    if (i>= nb_lignes || j >= nb_colonnes)
    {
        std::cout<<"("<<i<<","<<j<<") sort de la taille de la matrice (aucun coefficient de la matrice n'a été modifié"<<std::endl;
    }
}

void Matrix_creux::change_ligne(int i, Matrix_creux new_line) // new_line est un vecteur colonne
                                                              // la numérotation commence toujours à 0
{
    if (i<nb_lignes)
    {
        for (int k=0; k<(new_line.I).size(); k++)
        {
            int j=new_line.I[k];
            (*this).change_coeff(i, j, new_line.val[k]);
        }
    }
    else
    {
        std::cout<<"La ligne "<<i<<" de la matrice n'exite pas (aucune modification réalisée)"<<std::endl;
    }
}

void Matrix_creux::change_colonne(int j, Matrix_creux new_column) // new_column est un vecteur colonne 
                                                                  // la numérotation commence toujours à 0
{
    if (j<nb_colonnes)
    {
        for (int k=0; k<(new_column.I).size(); k++)
        {
            int i=new_column.I[k];
            (*this).change_coeff(i, j, new_column.coeff(i, 0));
        }
    }
    else
    {
        std::cout<<"La ligne "<<j<<" de la matrice n'exite pas (aucune modification réalisée)"<<std::endl;
    }
}


// getteurs:
int Matrix_creux::getnb_lignes()
{
    return nb_lignes;
}

int Matrix_creux::getnb_colonnes()
{
    return nb_colonnes;
}

std::vector<float>  Matrix_creux::getval()
{
    return val;
}

float Matrix_creux::coeff(int i, int j)
{
    int k=0;
    while (k<I.size() && (I[k]!= i || J[k] != j))
    {
        k++;
    }
    if (k == I.size())
    {
        return 0.;
    }
    return val[k];
}

Matrix_creux Matrix_creux::ligne(int i) //retourne un vecteur colonne 
{
    Matrix_creux ligne;
    ligne = Matrix_creux::nulle(nb_colonnes, 1);
    if (i<nb_lignes)
    {
        for (int k=0; k<I.size(); k++)
        {
            if (I[k] == i)
            {
                ligne.change_coeff(J[k], 0, val[k]);
            }
        }
    }
    else
    {
        std::cout<<"La ligne (ou colonne) "<<i<<" de la matrice considérée n'existe pas (colonne de 0 retourné par défaut)"<<std::endl;
    }
    return ligne;
}

Matrix_creux Matrix_creux::colonne(int j) //retourne un vecteur colonne
{
    Matrix_creux colonne;
    colonne = ((*this).T()).ligne(j);
    return colonne;
}


// fonctions de saisie et d'affichage :
void Matrix_creux::saisir()
{
    float coeff;

    std::cout<<"Nombre de lignes de la matrice :"; std::cin >> nb_lignes;
    std::cout<<"Nombre de colonnes de la matrice :"; std::cin >> nb_colonnes;

    val.clear();
    I.clear();
    J.clear();

    for (int i=1; i<=nb_lignes; i++)
    {
        std::vector<float> ligne;
        ligne.clear();
        for (int j=1; j<=nb_colonnes; j++)
        {
            std::cout<<"Coefficient ("<<i<<","<<j<<") :"; std::cin >> coeff;
            if (coeff != 0)
            {
                val.push_back(coeff);
                I.push_back(i - 1);
                J.push_back(j - 1);
            }
        }
    }
}

void Matrix_creux::afficher()
{
    for (int i=0; i<nb_lignes; i++)
    {
        std::cout<<"|";
        for (int j=0; j<nb_colonnes; j++)
        {
            std::cout<<" "<<(*this).coeff(i,j)<<" ";
        }
        std::cout<<"|"<<std::endl;
    }
}


//initialisation de matrices particulières:
Matrix_creux Matrix_creux::nulle(int taille_y, int taille_x)
{
    std::vector<float> vect_vide_float;
    vect_vide_float.clear();
    std::vector<int> vect_vide_int;
    vect_vide_int.clear();
    Matrix_creux Mat_nulle;
    Mat_nulle.setval(vect_vide_float);
    Mat_nulle.setI(vect_vide_int);
    Mat_nulle.setJ(vect_vide_int);
    Mat_nulle.setnb_lignes(taille_y);
    Mat_nulle.setnb_colonnes(taille_x);
    return Mat_nulle;
}

Matrix_creux Matrix_creux::identite(int taille)
{
    Matrix_creux identite;
    identite = Matrix_creux::nulle(taille, taille);
    
    for(int i=0; i<taille; i++)
    {
        (identite.val).push_back(1.0);
        (identite.I).push_back(i);
        (identite.J).push_back(i);
    }
    return identite;
}

Matrix_creux Matrix_creux::graduation(float pas, float min, float max) //retourne un vecteur colonne
{
    Matrix_creux ax;
    int N = int((max-min)/pas) + 1; //il faut que x(N - 1) = (N - 1)*pas + min <= max < N*pas + min
    ax = Matrix_creux::nulle(N, 1);
    for (int i=0; i<N - 1; i++)
    {
        (ax.val).push_back(i*pas + min);
    }
    (ax.val).push_back(max);

    return ax;
}


//opérations sur les matrices:
Matrix_creux Matrix_creux::operator+(const Matrix_creux &M)
{    
    Matrix_creux M_copy = M; 

    if  (M.nb_lignes == nb_lignes && M.nb_colonnes == nb_colonnes) 
    {
        Matrix_creux Somme;
        Somme = Matrix_creux::nulle(nb_lignes, nb_colonnes);

        for(int k=0; k<I.size(); k++)
        {
            int i =I[k];
            int j =J[k];
            float coeff = M_copy.coeff(i,j) + val[k];
            if (coeff !=0)
            {
                (Somme.val).push_back(coeff);
                (Somme.I).push_back(i);
                (Somme.J).push_back(j);
            }
        }
           return Somme;
    }
    std::cout << " Impossible (la matrice retournée par défaut est la matrice de droite)" << std::endl ;
    return M;
}

Matrix_creux Matrix_creux::operator-(const Matrix_creux &M)
{
    Matrix_creux M_copy = M; 

    if  (M.nb_lignes == nb_lignes && M.nb_colonnes == nb_colonnes) 
    {
        Matrix_creux Diff;
        Diff = Matrix_creux::nulle(nb_lignes, nb_colonnes);

        for(int k=0; k<I.size(); k++)
        {
            int i =I[k];
            int j =J[k];
            float coeff = val[k] - M_copy.coeff(i,j);
            if (coeff !=0)
            {
                (Diff.val).push_back(coeff);
                (Diff.I).push_back(i);
                (Diff.J).push_back(j);
            }
        }
           return Diff;
    }
    std::cout << " Impossible (la matrice retournée par défaut est la matrice de droite)" << std::endl ;
    return M;
}

Matrix_creux Matrix_creux::operator*(const Matrix_creux &M)
{
    if  (M.nb_lignes == nb_colonnes) 
    {
        Matrix_creux Prod;
        Prod = Matrix_creux::nulle(nb_lignes, M.nb_colonnes);

        
        for (int k=0; k<I.size(); k++)
        {
            for (int l=0; k<(M.I).size(); l++)
            {
                if (I[k] == (M.J)[l] && (M.I)[l] == J[k])
                {
                    Prod.change_coeff(I[k],(M.J)[l], Prod.coeff(I[k],(M.J)[l]) + val[k]*((M.val)[l])); 
                }
            }
        }
        
        return Prod;
    }
    std::cout << " Impossible (la matrice retournée par défaut est la matrice de droite)" << std::endl ;
    return M;
}

Matrix_creux Matrix_creux::operator*(const float &lambda)
{
    Matrix_creux Res = *this;

    for(int k=0; k<I.size(); k++)
    {
        (Res.val)[k] = (Res.val)[k]*lambda;
    }
    return Res;
}


void Matrix_creux::operator=(const Matrix_creux &M)
{
    nb_lignes = M.nb_lignes;
    nb_colonnes = M.nb_colonnes;
    val = M.val;
    I = M.I;
    J = M.J;
}

Matrix_creux Matrix_creux::T()
{
    Matrix_creux transpose = *this;
    transpose.I = J;
    transpose.J = I;
    return transpose;
}

float Matrix_creux::Trace()
{
    if (nb_lignes == nb_colonnes)
    {
        float trace=0;

        for(int k=0; k<I.size(); k++)
        {
            if (I[k] == J[k])
            {
                trace = trace + val[k];
            }
        }
        return trace;
    }
    std::cout<<"La matrice n'est pas carrée ! (la valeur retournée par défaut est 0)"<< std::endl;
    return 0;
}

float Matrix_creux::norme()
{
    return sqrt(((*this).T()*(*this)).val[0]);
}

