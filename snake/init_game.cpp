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
#include "init_game.h"
#include "init_background.h"
#include "affichage.h"
#include "serpent.h"
#include "place_serpent.h"

void init_game(std::vector<std::vector<char> > &gameboard, std::vector<std::vector<int> > &serpent, int size_board)
{
    std::vector<int> x_init; //initialisation de la position du serpent
    std::vector<int> y_init;

    x_init.clear();
    x_init.push_back(10);
    x_init.push_back(9);
    x_init.push_back(8);

    y_init.clear();
    y_init.push_back(10);
    y_init.push_back(10);
    y_init.push_back(10);

    init_background(gameboard, size_board);
    init_serpent(serpent, x_init, y_init);
    place_serpent(gameboard, serpent);
    affichage(gameboard);
}