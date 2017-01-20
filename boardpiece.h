#ifndef BOARDPIECE_H
#define BOARDPIECE_H

#include "utils.h"
#include "perfil.h"
//==CLASS BOARDPIECE==================
class BoardPiece{
protected:
    Point coords;
    int cost;
    int saude;
    int defesa;

    BoardPiece(Point p,int c,int s,int d)
        :coords(p),cost(c),saude(s),defesa(d){};
public:

    virtual ~BoardPiece();

    Point getCoords();
    //TODO: rething getSellValue() to incorporate saude%
    virtual int getSellValue();
    //virtual void display();
    virtual int getEID();
};

//==SUBCLASS EDIFICIO==================
class Edificio: public BoardPiece{
protected:
    int nivel;
    int const EID;
    Edificio(Point p,int id, int c,int s,int d):BoardPiece(p,c,s,d),EID(id){
        nivel = 1;}
public:
    virtual ~Edificio();

    int getEID();
    int getSellValue();
};

//==SUBCLASS EDIFICIO / QUINTA=========
class Quinta: public Edificio{
public:
    Quinta(Point p,int id):Edificio(p,id,20,20,10){};
    ~Quinta();
};

//==SUBCLASS EDIFICIO / TORRE==========
class Torre: public Edificio{
public:
    Torre(Point p,int id): Edificio(p,id,30,20,10){};
    ~Torre();
};

//==SUBCLASS EDIFICIO / CASTELO========
class Castelo: public Edificio{
public:
    Castelo(Point p): Edificio(p,0,0,50,10){}
    ~Castelo();
};

//==SUBCLASS SER=======================
class Ser: public BoardPiece{
private:
    ~Ser();
//    int velocidade;
//    int atack;
//    Perfil* perfil;
};

//alias columns, refering to the vector of pointers to boardpiece
using column = std::vector<BoardPiece*>;
#endif
