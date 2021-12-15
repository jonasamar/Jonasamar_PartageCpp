//---------------------------------------------------------------------------------------------
// nom : move_left
// args : gameboard, serpent, out
// return : rien
// intérêt :  - fait avancer de 1 case le serpent vers la gauche  
//            - fait prendre à out la valeur 1 si on sort de l'espace de jeu
//---------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <iostream>
#include "move_left.h"
#include "place_serpent.h"
#include "place_point_background.h"
#include "affichage.h"

void move_left(std::vector<std::vector<char> > &gameboard,std::vector<std::vector<int> > &serpent,int &game_over)
{
    int speed = 1;
    int size_serpent = serpent.size();
    int size_board = gameboard.size();
    std::vector<std::vector<int> > serpent_transvase;
    std::vector<int> old_coord = serpent.back(); // on conserve les anciennes coordonnées de la tête
    std::vector<int> new_coord;

    // on récupère les coordonnées de la tête
    new_coord.clear(); 
    new_coord = serpent.back();
    serpent.pop_back();
    int y_head = new_coord.back();
    new_coord.pop_back();
    int x_head = new_coord.back();
    new_coord.pop_back();

    //nouvelle coordonnées de la tête
    new_coord.push_back(x_head + 1);
    new_coord.push_back(y_head);
    serpent.push_back(new_coord);

    //le reste du serpent suit la tête
    for (int i=2; i<=size_serpent; i++)
    {
        new_coord = serpent[size_serpent - i];
        serpent[size_serpent - i] = old_coord;
        old_coord = new_coord;
    }

    //Informe si on est sorti du gameboard
    if (x_head + 1 <= 0 || x_head + 1 >= size_board -1)
    {
        game_over++;
    }

    //Affichage du nouvel état du jeu 
    place_serpent(gameboard, serpent);
    place_point_background(gameboard, old_coord);
    affichage(gameboard);
}