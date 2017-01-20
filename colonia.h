#ifndef COLONIA_H
#define COLONIA_H

#include "perfil.h"
#include "boardpiece.h"

class Colonia{
private:
    int moedas;
    char label;
    const std::vector<Perfil*> perfilList;
    BoardPiece* castelo;

    std::vector<BoardPiece*> Edificios;
    std::vector<BoardPiece*> Seres;

public:
    Colonia(int m,char l,std::vector<Perfil*> p,BoardPiece* c):
        moedas(m),
        label(l),
        perfilList(p),
        castelo(c){
    };

    char getLabel();
    BoardPiece* getCastelo();
    bool hasMoedas(int cost);

    void setMoedas(int value);
};

#endif
