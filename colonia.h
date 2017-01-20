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
    int getEdificioIndex(int givenEID);
    bool hasMoedas(int cost) const;

    void subMoedas(int value);
    void addMoedas(int value);

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

    //return NULL if edificio doesnt exist
    BoardPiece* getEdificio(int givenEID);
    BoardPiece* createTorre(Point p,int freeFlag);
    BoardPiece* createQuinta(Point p,int freeFlag);
    //return edificio to delete:success NULL:edificio not found
    BoardPiece* sellEdificio(int givenEID);

};

#endif
