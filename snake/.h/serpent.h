//---------------------------------------------------------------------------------------------
// nom : init_serpent
// args : serpent, x, y (vecteurs contenant les abscisses et ordonnées initiales des points du
//        serpent)
// return : rien
// intérêt : initialise le serpent, la variable serpent est donc ici un vecteur contenant les 
//           coordonnées de chacun des points du serpent.
//---------------------------------------------------------------------------------------------

#include <vector>

void init_serpent(std::vector<std::vector<int> > &serpent, std::vector<int> x, std::vector<int> y);