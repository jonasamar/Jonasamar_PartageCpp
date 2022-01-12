//---------------------------------------------------------------------------------------------
// nom : place_point_background
// args : gameboard, coords (vecteur contenant les coordonnées d'un point du background)
// return : rien
// intérêt : modifie gameboard pour faire apparaître un point du background au point de
//           coordonnées coords avec le caractère '~'.
//---------------------------------------------------------------------------------------------

#include <vector>
#include "place_point_background.h"
 
void place_point_background(std::vector<std::vector<char> > &gameboard, std::vector<int> coords)
{
    int y = coords.back();
    coords.pop_back();
    int x = coords.back(); // on a récupéré les coordonnées du point
    int size_gameboard = gameboard.size();

    std::vector<char> line = gameboard[y]; //ligne que l'on va remplacer
    
    std::vector<char> new_line = line;

    new_line[x] = '~';

    gameboard[y] = new_line;
}