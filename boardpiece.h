#ifndef COLONIA_H
#define COLONIA_H

#include "utils.h"
#include "perfil.h"
//TODO:implement and rethink the colonia related classes

class BoardPiece{
protected:
    Point coords;
    int cost;
    int saude;
    int defesa;

    BoardPiece();
//    BoardPiece(Point p,int c,int s,int d)
//        :coords(p),cost(c),saude(s),defesa(d){};
public:
    virtual void display();
};

//alias columns, refering to the vector of pointers to boardpiece
using column = std::vector<BoardPiece*>;

//class Empty: public BoardPiece{
//public:
//    Empty():BoardPiece( ,0,0,0){}
//};

class Edificio: public BoardPiece{
protected:
    int nivel;
};

class Quinta: public Edificio{
};

class Torre: public Edificio{
};

//TODO: should castelo be here?
class Castelo: public Edificio{
};

class Ser: public BoardPiece{
private:
    int velocidade;
    int atack;
    Perfil* perfil;
};

#endif
