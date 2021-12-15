//---------------------------------------------------------------------------------------------
// nom : next_move
// args : direction
// return : rien
// intérêt : * récupère les commandes effectuées par l'utilisateur et les associe à unedirection :
//              - flèche vers le haut pour up
//              - flèche vers le bas pour down
//              - flèche vers la gauche pour left
//              - flèche vers le droite pour right
//            * ne change pas de direction si l'utilisateur souhaite passer d'un opposer à un 
//              autre, par ex : impossible de faire up puis down, ou left puis right.
//---------------------------------------------------------------------------------------------

#include <iostream>
#include "next_move.h"

void next_move(int &direction)
{
    int asci;
    int new_direction;
    std::cin >> new_direction; /// on aimerait que l'uutilisateur rentre une direction et qu'elle soit enregistrer sans entrer tabuler
    

    //int new_asci = int(new_direction); ///// on veut le code asci...
    
    //asci de direction
    //if (direction == 1)
    //{
    //   asci = 37; 
    //}
    //if (direction == 3)
    //{
    //   asci = 38; 
    //}
    //if (direction == 2)
    //{
    //   asci = 39; 
    //}
    //if (direction == 4)
    //{
    //   asci = 40; 
    //}

    //on vérifie que la nouvelle direction convient
    //if (new_asci != asci && new_asci <= 40 && new_asci >= 37)
    //{
    //   if (direction == 1 && new_asci != 39)
    //    {
    //        direction = new_direction;
    //    }
    //    if (direction == 2 && new_asci != 37)
    //    {
    //        direction = new_direction;
    //    }
    //    if (direction == 3 && new_asci != 40)
    //    {
    //        direction = new_direction;
    //    }
    //    if (direction == 4 && new_asci != 36)
    //    {
    //        direction = new_direction;
    //    }
    //}

}

/// A reprendre...