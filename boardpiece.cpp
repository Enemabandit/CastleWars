#include "boardpiece.h"

//==BOARDPIECE FUNCTIONS============
int BoardPiece::getSellValue(){return 0;}
int BoardPiece::getEID(){return 0;}

Point BoardPiece::getCoords(){
    return coords;
}

void BoardPiece::setCost(int c){
    cost = c;
}
void BoardPiece::setSaude(int s){
    saude = s;
}
void BoardPiece::setDefesa(int d){
    defesa = d;
}
void BoardPiece::setAtaque(int a){
    ataque = a;
}

//==EDIFICIO FUNCIONS===============
int Edificio::getEID(){
    return EID;
}
int Edificio::getSellValue(){
    return cost/2;
}

//==SER FUNCIONS====================
void BoardPiece::move(){
}

void Ser::move(){
    //TODO:check if space occupied, hard to do without Board class
      //modifier->move()
      //updatecoords
    Point newP = perfil->getCoordsToMove(coords);
    coords = newP;
}

//==DESTRUCTORS DEFINITION==========
BoardPiece::~BoardPiece(){}
Edificio::~Edificio(){}
Torre::~Torre(){}
Quinta::~Quinta(){}
Castelo::~Castelo(){}
Ser::~Ser(){}

