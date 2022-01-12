//---------------------------------------------------------------------------------------------
// nom : init_background
// args : gameboard, size 
// return : rien
// intérêt : initialise gameboard : le background est un carré de coté size rempli par des '~' 
//           et bordé par des '*' à l'instant initial. gameboard sera modifié par la suite pour  
//           faire apparaître le serpent.
//---------------------------------------------------------------------------------------------

#include <vector>
#include "init_background.h"

void init_background(std::vector<std::vector<char> > &gameboard, int size_board)
{
    std::vector<char> l_center;
    std::vector<char> l_edge;

    l_center.clear();
    l_edge.clear();
    gameboard.clear();

    for (int i=0; i < size_board ; i++){ 
        l_edge.push_back('*');
    }

    l_center.push_back('*');
    for (int i=0; i < size_board - 2 ; i++){
        l_center.push_back('~');
    }
    l_center.push_back('*');

    gameboard.push_back(l_edge);
    for (int j=0; j < size_board - 2 ; j++){
        gameboard.push_back(l_center);
    }
    gameboard.push_back(l_edge);
}