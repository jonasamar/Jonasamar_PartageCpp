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

void next_move(std::string &direction);