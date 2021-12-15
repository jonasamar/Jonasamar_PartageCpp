//---------------------------------------------------------------------------------------------
// nom : init_game
// args : gameboard, serpent, size_square (taille du gameboard)
// return : rien
// intérêt : appelle toutes les fonctions nécessaires à l'initiatisation du jeu, permettant : 
//              - création du gameboard
//              - création du serpent
//              - affichage de la position de démarrage du jeu
//---------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>

void init_game(std::vector<std::vector<char> > &gameboard, std::vector<std::vector<int> > &serpent, int size_board);