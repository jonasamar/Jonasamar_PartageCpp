//---------------------------------------------------------------------------------------------
// nom : init_background
// args : gameboard, size 
// return : rien
// intérêt : initialise gameboard : le background est un carré de coté size rempli par des '~' 
//           et bordé par des '*' à l'instant initial. gameboard sera modifié par la suite pour  
//           faire apparaître le serpent.
//---------------------------------------------------------------------------------------------

#include <vector>

void init_background(std::vector<std::vector<char> > &gameboard, int size);
