//---------------------------------------------------------------------------------------------
// nom : place_point_serpent
// args : gameboard, coords (vecteur contenant les coordonnées d'un point du serpent)
// return : rien
// intérêt : modifie gameboard pour faire apparaître un morceau/ point du serpent au point de 
//           coordonnées coords avec le caractère 'X'.
//---------------------------------------------------------------------------------------------

#include <vector>
#include "place_point_serpent.h"
 
void place_point_serpent(std::vector<std::vector<char> > &gameboard, std::vector<int> coords)
{
    int y = coords.back();
    coords.pop_back();
    int x = coords.back(); // on a récupéré les coordonnées du point

    std::vector<char> line = gameboard[y]; //ligne que l'on va remplacer
    
    std::vector<char> new_line = line;

    new_line[x] = 'X'; 

    gameboard[y] = new_line;
}