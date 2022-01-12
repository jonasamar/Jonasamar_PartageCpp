//---------------------------------------------------------------------------------------------
// nom : place_serpent
// args : gameboard, serpent (vecteur contenant les coordonnées de tous les points du serpent)
// return : rien
// intérêt : modifie gameboard pour faire apparaître le serpent en appelant la fonction 
//           place_point_serpent
//---------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>

void place_serpent(std::vector<std::vector<char> > &gameboard, std::vector<std::vector<int> > serpent);