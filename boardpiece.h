#ifndef BOARDPIECE_H
#define BOARDPIECE_H

#include <iostream>

class BoardPiece {
protected:
    int coords[2];
    std::string label;
    Colonia owner;
    int cost;
    int health;
    int defence;
};

class Edificio: public BoardPiece{
protected:
    int level;
};
//child classes of edificio
class Quinta: public Edificio{
    
};

class Torre: public Edificio{
    
};

class Castelo: public Edificio{
    
};

class Ser: public BoardPiece{
    int speed;
    int atack;
    Perfil perfil;
}

#endif
