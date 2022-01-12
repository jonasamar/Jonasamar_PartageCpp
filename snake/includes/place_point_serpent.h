//---------------------------------------------------------------------------------------------
// nom : place_point_serpent
// args : gameboard, coords (vecteur contenant les coordonnées d'un point du serpent)
// return : rien
// intérêt : modifie gameboard pour faire apparaître un morceau/ point du serpent au point de 
//           coordonnées coords avec le caractère 'X'.
//---------------------------------------------------------------------------------------------

#include <vector>
 
void place_point_serpent(std::vector<std::vector<char> > &gameboard, std::vector<int> coords);