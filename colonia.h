#ifndef COLONIA_H
#define COLONIA_H

#include "utils.h"
#include "perfil.h"
//TODO:implement and rethink the colonia related classes

class BoardPiece{
protected:
    point coords;
    std::string label;
    int cost;
    int saude;
    int defesa;
public:
    virtual void display();
};

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
