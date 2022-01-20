//-------------------------------------------------------------------------
//
// Classe Matrix_creux (.h)
//
//-------------------------------------------------------------------------

#ifndef _MATRICE_CREUX_
#define _MATRICE_CREUX_
 
#include <iostream>
#include <vector>
#include "Matrix.h"

class Matrix_creux
{
private:
    int nb_lignes, nb_colonnes;
    std::vector<float>  val; //contient les valeurs non nuls de la matrice
    std::vector<int> I; //contient les numéros des lignes des coeff non nuls
    std::vector<int> J; //contient les numéros des colonnes des coeff non nuls

public:
    // contrsucteurs
    Matrix_creux();
    Matrix_creux(const int &l, const int &c, const std::vector<float> &mat, const std::vector<int> &I, const std::vector<int> &J);

    // destructeur
    ~Matrix_creux();

    // set attribus des matrices
    void setnb_lignes(int nb_lignes);
    void setnb_colonnes(int nb_lignes);
    void setval(std::vector<float> val);
    void setI(std::vector<int> I);
    void setJ(std::vector<int> J);
    void change_coeff(int i, int j, float new_coeff); // modifie le coefficient i,j de la matrice par la valeur new_coeff
    void change_colonne(int j, Matrix_creux new_column); // modifie la colonne  j de la matrice par la colonne new_column
    void change_ligne(int i, Matrix_creux new_line); // modifie la ligne i de la matrice par la ligne new_line

    // getteurs 
    int getnb_lignes();
    int getnb_colonnes();
    std::vector<float>  getval();
    std::vector<int>  getI();
    std::vector<int>  getJ();
    float coeff(int i, int j); // donne la valeur du coefficient i,j de la matrice
    Matrix_creux ligne(int i); // permet de sélectionner la i-ieme ligne de la matrice (en commençant par la ligne 0)
    Matrix_creux colonne(int j); // permet de sélectionner la j-ieme colonne de la matrice (en commençant par la colonne 0)

    // fonctions d'affichage et de saisie
    void saisir();
    void afficher();

    // initialisation de matrices particulières
    static Matrix_creux nulle(int taille_y, int taille_x); 
    static Matrix_creux identite(int taille);
    static Matrix_creux graduation(float pas, float min, float max);//fonction qui permet la création d'un vecteur colonne 
                                                                    //contenant des valeurs à pas régulier entre min et max

    // operations sur les matrices
    void operator=(const Matrix_creux &M); //affectation
    Matrix_creux operator+(const Matrix_creux &M); //somme
    Matrix_creux operator-(const Matrix_creux &M); //différence
    Matrix_creux operator*(const Matrix_creux &M); //produit matriciel
    Matrix_creux operator*(const float &lambda); //produit par un scalaire
    Matrix_creux operator^(const int &n); //puissance n
    Matrix_creux T(); //transposée
    float Trace(); //trace
    float norme(); //norme infinie

    //convertire une Matrix et Matrix_creux
    Matrix convert_to_Matrix();
};


#endif