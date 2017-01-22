#include "colonia.h"

int Colonia::EID = 1;

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

void Colonia::addMoedas(int value){
    moedas += value;
}

//=======================================
//==EDIFICIOS MANIPULATION===============
BoardPiece* Colonia::getCastelo() const{
    return castelo;
}

int Colonia::getEIDandUpdate() {
    return EID++;
}

//return NULL if edificio doesnt exist
BoardPiece* Colonia::getEdificio(int givenEID){
    BoardPiece* found = NULL;
    for(std::vector<BoardPiece*>::iterator it = edificiosList.begin();
        it != edificiosList.end(); ++it){
        if ((*it)->getEID() == givenEID)
            found = *it;
    }
    return found;
}

//return edificio to delete:success NULL:edificio not found
BoardPiece* Colonia::sellEdificio(int givenEID){
    BoardPiece* edificio;
    if((edificio = getEdificio(givenEID)) != NULL){
        //remove from list
        edificiosList.erase(edificiosList.begin()+getEdificioIndex(givenEID));
        //refound
        addMoedas(edificio->getSellValue());
        return edificio;
    } else {
        return NULL;
    }
}

int Colonia::getEdificioIndex(int givenEID){
    int index = 0;
    for(std::vector<BoardPiece*>::iterator it = edificiosList.begin();
        it != edificiosList.end(); ++it){
        if((*it)->getEID() == givenEID)
            return index;
        else
            index++;
    }
}

//return Torre: success, NULL:not enough money
BoardPiece* Colonia::createTorre(Point p,int freeFlag){
    if(!freeFlag){
        if(hasMoedas(30)){
            BoardPiece* newTorre = new Torre(p,getEIDandUpdate());
            subMoedas(30);
            edificiosList.push_back(newTorre);
            return newTorre;
        } else {
            return NULL;
        }
    } else {
        BoardPiece* newTorre = new Torre(p,getEIDandUpdate());
        edificiosList.push_back(newTorre);
        return newTorre;
    }
}
//return Quinta: success, NULL:not enough money
BoardPiece* Colonia::createQuinta(Point p,int freeFlag){
    if (!freeFlag){
        if(hasMoedas(20)){
            BoardPiece* newQuinta = new Quinta(p,getEIDandUpdate());
            subMoedas(20);
            edificiosList.push_back(newQuinta);
            return newQuinta;
        } else {
            return NULL;
        }
    } else {
        BoardPiece* newQuinta = new Quinta(p,getEIDandUpdate());
        edificiosList.push_back(newQuinta);
        return newQuinta;
    }
}

//=======================================
//==SERES MANIPULATION===================

//return 1: success -1:not enough money
int Colonia::createSeres(int num,Perfil* perfil){
    if(hasMoedas(num*perfil->getCost())){
        for(int i = 0; i < num;i++){
            Ser* ser = new Ser(castelo->getCoords(),perfil);
            seresList.push_back(ser);
            subMoedas(num*perfil->getCost());
        }
    }else{
        return -1;
    }
}

void Colonia::moveSeres(){
    for(std::vector<BoardPiece*>::iterator it = seresList.begin();
        it != seresList.end(); ++it){
        (*it)->move();
    }
}

//=======================================
//==Display==============================
void Colonia::display(){
    //NOTE: this was a test, it works but doesnt do much
    //      I commented so that the code compiles in windows machines
    //      (removed ncurses)

  /*initscr();
    printw("Colonia %c\n", label);
    printw("  moedas: %d\n", moedas);
    printw("  Castelo:\n");
    printw("    posicao: %d,%d\n",
           castelo->getCoords().x,castelo->getCoords().y);
    printw("    saude:   %d\n",castelo->getSaude());
    printw("    defesa:  %d\n",castelo->getDefesa());
    printw("\n");
    //printw("Edificios:\n");
    //for(std::vector<BoardPiece*>::iterator it = edificiosList.begin();
    //    it != edificiosList.end();++it){
    //    (*it)->displayInfo();
    //}
    refresh();
    getch();
    endwin();*/
}

