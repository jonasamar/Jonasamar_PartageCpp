//---------------------------------------------------------------------------------------------
// nom : init_serpent
// args : serpent, x, y (vecteurs contenant les abscisses et ordonnées initiales des points du
//        serpent)
// return : rien
// intérêt : initialise le serpent, la variable serpent est donc ici un vecteur contenant les 
//           coordonnées de chacun des points du serpent.
//---------------------------------------------------------------------------------------------

#include <vector>
#include "serpent.h"


void init_serpent(std::vector<std::vector<int> > &serpent, std::vector<int> x, std::vector<int> y)
{
    int taille_init = x.size();
    std::vector<int> coord;

    serpent.clear();

    for (int i=0; i < taille_init; i++){ 
        coord.clear();
        coord.push_back(x.back());
        coord.push_back(y.back());
        serpent.push_back(coord);
        x.pop_back();
        y.pop_back();
    } // à la fin de la boucle for serpent contient un vecteur de vecteurs (= coordonnées des points de son corps)

}