#pragma once
#include <vector>

// Définition de l'énumération pour les états des cellules (vivante ou morte)
enum class etatcellule {
    vivant, mort
};
enum class structure {
    scillateurligne,
    floraison,
    planeur,
    oscilateurcroix
};

using coordonnee =  unsigned int;

class grille {
public:
    grille(int hauteur, int largeur);

    ~grille() = default;
    void vider();
    bool vivante(coordonnee x, coordonnee y) const;
    void generer(coordonnee x, coordonnee y);
    void tuer(coordonnee x, coordonnee y);
    void afficher() const;
    void ajouterstructure(structure s ,coordonnee x, coordonnee y);
    int vivantes(coordonnee x, coordonnee y) const;
    void evolution(grille & g );

private:
    int _lignes;
    int _colonnes;
    std::vector<std::vector<etatcellule>> _grille;  // La grille représentée comme une matrice 2D d'états de cellules
};


