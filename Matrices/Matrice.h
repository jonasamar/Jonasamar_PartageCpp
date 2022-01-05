#ifndef _MATRICE_
#define _MATRICE_
 
#include <iostream>
#include <vector>

class Matrice
{
private:
    int nb_lignes, nb_colonnes;
    std::vector<std::vector<float> > val;

public:
    Matrice();
    Matrice(const int &l, const int &c, const std::vector<std::vector<float> > &mat);
    ~Matrice();

    void setnb_lignes(int nb_lignes);
    void setnb_colonnes(int nb_lignes);
    void setval(std::vector<std::vector<float> > val);
    
    void saisir();
    void afficher();

    static Matrice matrice_nulle(int taille_y, int taille_x); 
    static Matrice matrice_identite(int taille);

    void operator=(const Matrice &M);
    Matrice operator+(const Matrice &M);
    Matrice operator-(const Matrice &M);
    Matrice operator*(const Matrice &M);
    Matrice operator*(const float &lambda);
    Matrice operator^(const int &n);

    Matrice T();
    float Trace();
    float norme();
};



#endif