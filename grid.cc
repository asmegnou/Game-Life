#include"grid.hh"
#include<iostream>
#include<vector>


grille::grille(int ligne, int colonnes): _lignes(ligne), _colonnes(colonnes),
    _grille(ligne, std::vector<etatcellule>(colonnes, etatcellule::mort)){}


void grille::vider(){
    for (int i = 0; i < _lignes; i++) {
        for (int j = 0; j < _colonnes; j++) {
            _grille[i][j] = etatcellule::mort;  // Marquer chaque cellule comme morte
        }
    }
}

bool grille::vivante(coordonnee x  , coordonnee y) const{
    if (x >= 0 && x < _lignes && y >= 0 && y < _colonnes) {
        return _grille[x][y]==etatcellule::vivant;
    } else {
        std::cout << "Indices hors limites!" << std::endl;
        return false;
    }
}

void grille::generer(coordonnee x, coordonnee y) {
    if (x >= 0 && x < _lignes && y >= 0 && y < _colonnes) {
        _grille[x][y]=etatcellule::vivant;
    } else {
        std::cout << "Indices hors limites!" << std::endl;
    }
}


void grille::tuer(coordonnee x, coordonnee y) {
    if (x >= 0 && x < _lignes && y >= 0 && y < _colonnes) {
        _grille[x][y]=etatcellule::mort;
    } else {
        std::cout << "Indices hors limites!" <<std::endl;
    }
}

void grille::afficher() const{
    for (int i = 0; i < _lignes; i++) {
        for (int j = 0; j < _colonnes; j++) {
            if(vivante(i,j)){
                std::cout<<"*";
            }else{
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }
}

//dans ce cas la on ne fait pas de verification sur x et y

void grille::ajouterstructure(structure s, coordonnee x, coordonnee y){
    switch (s){
    case structure::scillateurligne :
            for(coordonnee i =0; i<3; i++)
                generer(x,y+i);
            break;
        case structure::floraison :
            ajouterstructure(structure::scillateurligne,x, y+1);
            ajouterstructure(structure::scillateurligne, x+2,y+1);
            for(coordonnee i=0; i<=4; i+=2)
                generer(x+1,y+i);
            break;
        case structure::planeur :
            ajouterstructure(structure::scillateurligne,x,y);
            generer(x+1,y+2);
            generer(x+2,y+1);
            break;
        case structure::oscilateurcroix:
            ajouterstructure(structure::scillateurligne,x+1,y);
            generer(x,y+1);
            generer(x+2, y+1);
            break;

    }

}

int grille::vivantes(coordonnee x, coordonnee y) const{
    int compte=0;
    for(int dx=-1; dx<=1; dx++){
        for(int dy=-1; dy<=1;dy++){
            if(dx==0 && dy==0) continue ;//passer la cellue centrale
            int nx=dx + static_cast<int> (x);
            int ny=dy + static_cast<int> (y);
            //verifier qu'on est dans la grille
            if(nx>=0 && ny>=0 && ny <_colonnes && nx<_lignes){
                if(_grille[nx][ny]==etatcellule::vivant) compte++;
            }
         }
    }
    return compte;
}


void grille::evolution(grille & g ){
    for(int i=0;i<_lignes; i++){
        for(int j=0;j<_colonnes; j++){
            int nbVoisin = vivantes(i,j);
            //appliquer les regles
            if(_grille[i][j] == etatcellule ::vivant){ //si la cellule est vivante
                if(nbVoisin<2){//la cellule meur d'isolement
                    g._grille[i][j]=etatcellule::mort;
                }
                if(nbVoisin>=4){ //meurt d'etoufement
                    g._grille[i][j]=etatcellule::mort;
                }
            }else{//si la cellule est morte
                if(nbVoisin==3){//la cellule revis
                    g._grille[i][j]=etatcellule::vivant;
                }
            }
        }
    }
}
