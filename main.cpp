#include"grid.hh"
#include <iostream>

using namespace std;

int main()
{


    const unsigned int largeur = 20;  // Choisissez la largeur de la grille
    const unsigned int hauteur = 20;  // Choisissez la hauteur de la grille

        // Création de la grille et de la grille de prochaine évolution
        grille G(largeur, hauteur);
        grille prochaineG(largeur, hauteur);

        G.ajouterstructure(structure::scillateurligne, largeur / 2, hauteur / 2);

        // Boucle pour calculer et afficher l'évolution
        std::string s;
        while (true) {
            // Afficher l'état actuel de la grille
            G.afficher();

            // Attendre un appui sur Entrée
            std::cout << "Appuyez sur Entrée pour continuer..." << std::endl;
            std::getline(std::cin, s);

            // Calculer l'évolution de la grille et l'affecter à la prochaineGrille
            G.evolution(prochaineG);

            // Mettre à jour la grille courante avec la prochaineGrille
            G = prochaineG;
        }

    return 0;
}
