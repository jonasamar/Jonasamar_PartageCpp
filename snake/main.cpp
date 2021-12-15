//---------------------------------------------------------------------------------------------
// nom : main
// args : arguments par défaut
// return : 0
// But : générer une partie de snake dans le terminal
// Conventions : la variable direction contient la direction dans laquelle le serpent avance : 
//                  - 1 = gauche
//                  - 2 = droite
//                  - 3 = haut
//                  - 4 = bas
//---------------------------------------------------------------------------------------------

#include <future> // pour la fonction sleep_for

#include <iostream>
#include <vector>

#include "init_game.h"
#include "move_left.h"
#include "move_right.h"
#include "move_up.h"
#include "move_down.h"
#include "keyboard.h"

#define UP_ARROW    65
#define LEFT_ARROW  68
#define DOWN_ARROW  66
#define RIGHT_ARROW 67


std::vector<std::vector<char> > gameboard;
std::vector<std::vector<int> > serpent;
int game_over = {0}; // variable qui nous permettra de savoir quans le serpent sors de la zone de jeu
int size_board = 25;
int direction = LEFT_ARROW;
int speed = 10;

int main(int argc, char **argv)
{
    init_game(gameboard, serpent, size_board);
    
    
    while (game_over == 0)
    {
        keyboard_init();
        direction = keyboard_scan();
        std::this_thread::sleep_for(std::chrono::seconds(1/10));

        if (direction == LEFT_ARROW)
        {
            
            move_left(gameboard, serpent, game_over);
        }
        else if (direction == RIGHT_ARROW)
        {
            
            move_right(gameboard, serpent, game_over);
        }
        else if (direction == UP_ARROW)
        {
            
            move_up(gameboard, serpent, game_over);
        }
        else if (direction == DOWN_ARROW)
        {
            
            move_down(gameboard, serpent, game_over);
        }
        keyboard_end();
    }

    std::cout << "GAME OVER" << std::endl;

    return 0;
}