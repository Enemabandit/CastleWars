#ifndef COLONIA_H
#define COLONIA_H

#include "perfil.h"
#include "boardpiece.h"

class Colonia{
private:
    static int EID;

    int moedas;
    char label;
    const std::vector<Perfil*> perfilList;
    BoardPiece* castelo;

    std::vector<BoardPiece*> edificiosList;
    std::vector<BoardPiece*> seresList;

    int getEIDandUpdate();
    bool hasMoedas(int cost) const;

public:
    Colonia(int m,char l,std::vector<Perfil*> p,BoardPiece* c):
        moedas(m),
        label(l),
        perfilList(p),
        castelo(c){
    };

    char getLabel() const;
    BoardPiece* getCastelo() const;

    void setMoedas(int value);
    void subMoedas(int value);

    BoardPiece* createTorre(Point p);
    BoardPiece* createQuinta(Point p);
};

#endif
