//---------------------------------------------------------------------------------------------
// nom : place_point_background
// args : gameboard, coords (vecteur contenant les coordonnées d'un point du background)
// return : rien
// intérêt : modifie gameboard pour faire apparaître un point du background au point de  
//           coordonnées coords avec le caractère '~'.
//---------------------------------------------------------------------------------------------

#include <vector>
 
void place_point_background(std::vector<std::vector<char> > &gameboard, std::vector<int> coords);