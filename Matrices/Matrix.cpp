//-------------------------------------------------------------------------
//
// Classe Matrix (.cpp)
//
//-------------------------------------------------------------------------

#include "Matrix.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

// constructeurs :
Matrix::Matrix(){}
Matrix::Matrix(const int &l, const int &c, const std::vector<std::vector<float> > &mat) : nb_lignes(l), nb_colonnes(c), val(mat){}


//destructeur :
Matrix::~Matrix(){}


// set attributs des matrices:
void Matrix::setnb_lignes(int nb_lignes)
{
    this->nb_lignes = nb_lignes; 
}

void Matrix::setnb_colonnes(int nb_colonnes)
{
    this->nb_colonnes = nb_colonnes; 
}

void Matrix::setval(std::vector<std::vector<float> > val)
{
    this->val = val; 
}

void Matrix::change_coeff(int i, int j, float new_coeff)
{
    val[i][j] = new_coeff;
}

void Matrix::change_ligne(int i, Matrix new_line) // new_line est un vecteur colonne
                                                  // la numérotation commence toujours à 0
{
    for (int j=0; j<nb_colonnes; j++)
    {
        (*this).change_coeff(i, j, new_line.coeff(j, 0));
    }
}

void Matrix::change_colonne(int j, Matrix new_column) // new_column est un vecteur colonne 
                                                      // la numérotation commence toujours à 0
{
    for (int i=0; i<nb_colonnes; i++)
    {
        (*this).change_coeff(i, j, new_column.coeff(i, 0));
    }
}


// getteurs:
int Matrix::getnb_lignes()
{
    return nb_lignes;
}

int Matrix::getnb_colonnes()
{
    return nb_colonnes;
}

std::vector<std::vector<float> >  Matrix::getval()
{
    return val;
}

float Matrix::coeff(int i, int j)
{
    return val[i][j];
}

Matrix Matrix::ligne(int i) //retourne un vecteur colonne 
{
    Matrix ligne;
    ligne.nb_lignes = nb_colonnes;
    ligne.nb_colonnes = 1;
    for (int j=0; j<nb_colonnes; j++)
    {
        std::vector<float> coeff;
        coeff.clear();
        coeff.push_back(val[i][j]);
        (ligne.val).push_back(coeff);
    }
    return ligne;
}

Matrix Matrix::colonne(int j) //retourne un vecteur colonne
{
    Matrix colonne;
    colonne = ((*this).T()).ligne(j);
    return colonne;
}


// fonctions de saisie et d'affichage :
void Matrix::saisir()
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

void Matrix::afficher()
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


//initialisation de matrices particulières:
Matrix Matrix::matrice_nulle(int taille_y, int taille_x)
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

    Matrix Mat_nulle(taille_y, taille_x, mat);
    return Mat_nulle;
}

Matrix Matrix::matrice_identite(int taille)
{
    Matrix identite;
    identite = Matrix::matrice_nulle(taille, taille);
    
    for(int i=0; i<taille; i++)
    {
        identite.val[i][i] = 1.0;
    }
    return identite;
}


//opérations sur les matrices:
Matrix Matrix::operator+(const Matrix &M)
{
    if  (M.nb_lignes == nb_lignes && M.nb_colonnes == nb_colonnes) 
    {
        Matrix Somme;
        Somme = Matrix::matrice_nulle(nb_lignes, nb_colonnes);

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

Matrix Matrix::operator-(const Matrix &M)
{
    if  (M.nb_lignes == nb_lignes && M.nb_colonnes == nb_colonnes) 
    {
        Matrix Diff;
        Diff = Matrix::matrice_nulle(nb_lignes, nb_colonnes);

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

Matrix Matrix::operator*(const Matrix &M)
{
    if  (M.nb_lignes == nb_colonnes) 
    {
        Matrix Prod;
        Prod = Matrix::matrice_nulle(nb_lignes, M.nb_colonnes);
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

Matrix Matrix::operator*(const float &lambda)
{
    Matrix Res;
    Res = Matrix::matrice_nulle(nb_lignes, nb_colonnes);

    for(int i=0; i<nb_lignes; i++)
    {
        for (int j=0; j<nb_colonnes; j++)
        {
            Res.val[i][j]=  lambda* val[i][j];
        }
    }
    return Res;
}


void Matrix::operator=(const Matrix &M)
{
    nb_lignes = M.nb_lignes;
    nb_colonnes = M.nb_colonnes;
    val = M.val;

}

Matrix Matrix::operator^(const int &n)
{
    Matrix mat(nb_lignes, nb_colonnes, val);
    Matrix Res;
    Res = mat;

    for(int i=0; i<n; i++)
    {
        Res = Res*mat;
    }

    return Res;
}

Matrix Matrix::T()
{
    Matrix transpose;
    transpose = Matrix::matrice_nulle(nb_colonnes, nb_lignes);
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

float Matrix::Trace()
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

float Matrix::norme()
{
    return sqrt(((*this).T()*(*this)).val[0][0]);
}


// écriture dans un fichier texte
void Matrix::WriteToFile(const std::string &file_name) const
    {
        std::ofstream out(std::string("../data/") + file_name);

        for (int i = 0; i < nb_lignes; i++)
        {
            for (int j = 0; j < nb_colonnes; j++)
            {
                out << val[i][j] << ";";
            }
            out << "\n";
        }
    }