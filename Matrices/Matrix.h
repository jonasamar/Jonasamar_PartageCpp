//-------------------------------------------------------------------------
//
// Classe Matrix (.h)
//
//-------------------------------------------------------------------------

#ifndef _MATRICE_
#define _MATRICE_
 
#include <iostream>
#include <vector>

class Matrix
{
private:
    int nb_lignes, nb_colonnes;
    std::vector<std::vector<float> > val;

public:
    // contrsucteurs
    Matrix();
    Matrix(const int &l, const int &c, const std::vector<std::vector<float> > &mat);

    // destructeur
    ~Matrix();

    // set attribus des matrices
    void setnb_lignes(int nb_lignes);
    void setnb_colonnes(int nb_lignes);
    void setval(std::vector<std::vector<float> > val);
    void change_coeff(int i, int j, float new_coeff); // modifie le coefficient i,j de la matrice par la valeur new_coeff
    void change_colonne(int j, Matrix new_column); // modifie la colonne  j de la matrice par la colonne new_column
    void change_ligne(int i, Matrix new_line); // modifie la ligne i de la matrice par la ligne new_line

    // getteurs 
    int getnb_lignes();
    int getnb_colonnes();
    std::vector<std::vector<float> >  getval();
    float coeff(int i, int j); // donne la valeur du coefficient i,j de la matrice
    Matrix ligne(int i); // permet de sélectionner la i-ieme ligne de la matrice (en commençant par la ligne 0)
    Matrix colonne(int j); // permet de sélectionner la j-ieme colonne de la matrice (en commençant par la colonne 0)

    // fonctions d'affichage et de saisie
    void saisir();
    void afficher();

    // initialisation de matrices particulières
    static Matrix nulle(int taille_y, int taille_x); 
    static Matrix identite(int taille);
    static Matrix graduation(float pas, float min, float max);//fonction qui permet la création d'un vecteur colonne 
                                                              //contenant des valeurs à pas régulier entre min et max

    // operations sur les matrices
    void operator=(const Matrix &M); //affectation
    Matrix operator+(const Matrix &M); //somme
    Matrix operator-(const Matrix &M); //différence
    Matrix operator*(const Matrix &M); //produit matriciel
    Matrix operator*(const float &lambda); //produit par un scalaire
    Matrix operator^(const int &n); //puissance n
    Matrix T(); //transposée
    float Trace(); //trace
    float norme(); //norme infinie

    // écriture dans un fichier texte
    void WriteToFile(const std::string &file_name) const;
};



#endif