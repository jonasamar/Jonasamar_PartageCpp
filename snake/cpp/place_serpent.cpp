//---------------------------------------------------------------------------------------------
// nom : place_serpent
// args : gameboard, serpent (vecteur contenant les coordonnées de tous les points du serpent)
// return : rien
// intérêt : modifie gameboard pour faire apparaître le serpent en appelant la fonction 
//           place_point_serpent
//---------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include "place_point_serpent.h"
#include "place_serpent.h"


void place_serpent(std::vector<std::vector<char> > &gameboard, std::vector<std::vector<int> > serpent)
{
    int size_serpent = serpent.size();

    for (int i=0; i<size_serpent; i++)
    {
        place_point_serpent(gameboard, serpent.back());
        serpent.pop_back(); // on travaille ici avec une copie de serpent donc pas besoin de conserver le contenu de serpent
    }
}

   

