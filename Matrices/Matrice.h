#ifndef _MATRICE_HPP_
#define _MATRICE_HPP_
 
#include <iostream>
#include <vector>

class Matrice
{
public:
    void setnb_lignes(int nb_lignes);
    void setnb_colonnes(int nb_lignes);
    void setval(std::vector<std::vector<float> > val);
    void saisir();
    void afficher();
    static Matrice matrice_nulle(int taille_y, int taille_x); 
    Matrice operator+(const Matrice &M);
    Matrice operator-(const Matrice &M);
    Matrice operator*(const Matrice &M);
    Matrice multiply(const float lambda);
private:
    int nb_lignes, nb_colonnes;
    std::vector<std::vector<float> > val;
};



#endif