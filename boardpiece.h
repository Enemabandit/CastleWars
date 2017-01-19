#ifndef BOARDPIECE_H
#define BOARDPIECE_H

#include "utils.h"
#include "perfil.h"

class BoardPiece{
protected:
    Point coords;
    int cost;
    int saude;
    int defesa;

    BoardPiece(Point p,int c,int s,int d)
        :coords(p),cost(c),saude(s),defesa(d){};
public:

    Point getCoords(){return coords;}
    //virtual void display();
};

//alias columns, refering to the vector of pointers to boardpiece
using column = std::vector<BoardPiece*>;


class Edificio: public BoardPiece{
protected:
    int nivel;

public:
    Edificio(Point p, int c,int s,int d):BoardPiece(p,c,s,d){}
};

class Quinta: public Edificio{
};

class Torre: public Edificio{
};

class Castelo: public Edificio{
public:
    Castelo(Point p): Edificio(p,0,50,10){}
};

class Ser: public BoardPiece{
private:
//    int velocidade;
//    int atack;
//    Perfil* perfil;
};

#endif
