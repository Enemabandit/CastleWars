#include "boardpiece.h"

//==BOARDPIECE FUNCTIONS============
int BoardPiece::getSellValue(){return 0;}
int BoardPiece::getEID(){return 0;}

Point BoardPiece::getCoords(){
    return coords;
}

//==EDIFICIO FUNCIONS===============
int Edificio::getEID(){
    return EID;
}
int Edificio::getSellValue(){
    return cost/2;
}

//==DESTRUCTORS DEFINITION==========
BoardPiece::~BoardPiece(){}
Edificio::~Edificio(){}
Torre::~Torre(){}
Quinta::~Quinta(){}
Castelo::~Castelo(){}
Ser::~Ser(){}

