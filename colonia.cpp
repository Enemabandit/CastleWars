#include "colonia.h"

int Colonia::EID = 1;

BoardPiece* Colonia::getCastelo() const{
    return castelo;
}

char Colonia::getLabel() const{
    return label;
}

void Colonia::setMoedas(int value){
    moedas = value;
}

bool Colonia::hasMoedas(int cost) const{
    if (moedas >= cost)
        return true;
    else
        return false;
}

void Colonia::subMoedas(int value){
    moedas -= value;
}

int Colonia::getEIDandUpdate() {
    return EID++;
}

//return Torre: success, NULL:not enough money
BoardPiece* Colonia::createTorre(Point p){
    if(hasMoedas(30)){
        BoardPiece* newTorre = new Torre(p,getEIDandUpdate());
        subMoedas(30);
        edificiosList.push_back(newTorre);
        return newTorre;
    } else {
        return NULL;
    }
}
//return Quinta: success, NULL:not enough money
BoardPiece* Colonia::createQuinta(Point p){
    if(hasMoedas(20)){
        BoardPiece* newQuinta = new Quinta(p,getEIDandUpdate());
        subMoedas(20);
        edificiosList.push_back(newQuinta);
        return newQuinta;
    } else {
        return NULL;
    }
}
