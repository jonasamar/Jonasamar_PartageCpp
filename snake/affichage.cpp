//---------------------------------------------------------------------------------------------
// nom : affichage
// args : gameboard
// return : rien
// intérêt : print dans le terminal l'état du jeu/ gameboard 
//---------------------------------------------------------------------------------------------


#include <iostream>
#include <vector>
#include "affichage.h"


void affichage(std::vector<std::vector<char> > gameboard)
{
    int size = gameboard.size();

    system("clear"); //on efface tout sur le terminal

    for(int i=0; i < size; i++){
        std::vector<char> l = gameboard.back();
        gameboard.pop_back();
        int size_l = l.size();
        for(int j=0; j < size_l; j++){
            std::cout << l.back() << " ";
            l.pop_back();
        }
        std::cout<<std::endl;
    }
}