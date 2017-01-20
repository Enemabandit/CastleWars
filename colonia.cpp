#include "colonia.h"

BoardPiece* Colonia::getCastelo(){
    return castelo;
}

char Colonia::getLabel(){
    return label;
}

void Colonia::setMoedas(int value){
    moedas = value;
}

bool Colonia::hasMoedas(int cost){
    if (moedas >= cost)
        return true;
    else
        return false;
}
