#include "game.h"

void Game::Builder::setOpponents (const int o){
    numOpponents = o;
}

bool Game::Builder::coloniaExists(const char c){
    if(c <= 'a' + numOpponents)
        return true;
    return false;
}

//tests the validity of a point(if inside board and if not occupied)
bool Game::Builder::isPointValid(Point p){
    //is out board dimensions
    if(p.x > height || p.y > width) return false;
    //is it occupied by another castelo?
    for(std::map<char,Point>::iterator it=casteloList.begin()
            ; it != casteloList.end() ; ++it)
        //TODO: review overload operators for this!
        if(it->second.x == p.x && it->second.y == p.y) return false;

    return true;
}
//tests if the castelo for that colonia was already placed
bool Game::Builder::isCasteloPlaced(const char c){
    for(std::map<char,Point>::iterator it=casteloList.begin()
            ; it != casteloList.end() ; ++it){
        if(it->first == c) return true;
    }
    return false;
}

//return 1:success -1:colonia doesn exist -2:posicao invalida
int Game::Builder::setCastelo(const char label, const int x, const int y){
    Point p;
    p.x = x;
    p.y = y;

    if(coloniaExists(label)){
        if(isPointValid(p)){
            if(isCasteloPlaced(label)){
                casteloList[label]=p;
                return 1;
            } else {
                casteloList.insert(std::pair<char,Point>(label,p));
                return 1;
            }
        } else {
            return -2;
        }
    } else {
        return -1;
    }
}

//==PERFIL MANIPULATION==================
int Game::Builder::setPerfil (const char p){
    Perfil* newPerfil = new Perfil(p);
    if(!perfilExists(p)){
        perfilList.push_back(newPerfil);
        return 1;
    } else {
        return 0;
    }
}

int Game::Builder::perfilExists(const char p){
    for(std::vector<Perfil*>::iterator it = perfilList.begin();
        it != perfilList.end(); ++it){
        if ((*it)->getLabel() == p)
            return 1;
    }
    return 0;
}

Perfil* Game::Builder::getPerfilFromList(const char p){
    int index=0;
    for(std::vector<Perfil*>::iterator it = perfilList.begin();
        it != perfilList.end(); ++it){
        if ((*it)->getLabel() == p){
            Perfil* found = perfilList[index];
            return found;
        }
        index++;
    }
}

//adds new modifier a a perfil
//return 1:added -1:perfil doesnt exist -2:forca unavailable
int Game::Builder::addModifierToPerfil(char label, int id){
    if(perfilExists(label))
    {
        if(getPerfilFromList(label)->addModifier(id)){
            return 1;
        } else {
            return -2;
        }
    } else {
        return -1;
    }
}

//return 1:removed -1:perfil doesnt exist -2:Modifier doesnt exist
int Game::Builder::rmModifierFromPerfil(char label,int id){
    if(perfilExists(label)){
        if (getPerfilFromList(label)->rmModifier(id)){
            return 1;
        } else {
            return -2;
        }
    } else {
        return -1;
    }
}

//return 1:removed 0:perfil not found
//TODO: check for memory leaks
int Game::Builder::rmPerfil(char label){
    int index;
    if(perfilExists(label)){
        getPerfilFromList(label)->deleteLists();
        index = getPerfilIndex(label);
        delete (getPerfilFromList(label));
        perfilList.erase(perfilList.begin()+index);
        return 1;
    } else {
        return 0;
    }
}

int Game::Builder::getPerfilIndex(const char label){
    int index = 0;
    for(std::vector<Perfil*>::iterator it = perfilList.begin();
        it != perfilList.end(); ++it){
        if ((*it)->getLabel() != label)
            index++;
        else
            return index;
    }
}
//=======================================
//==BOARD MANIPULATION===================
void Game::Builder::createBoard(){
    //initialization to NULL of all the board pointers
    //NOTE: column(height,0) is init with NULL all the pointers in column
    std::vector<column> b(width, column(height,0));
    board = b;
}

//=======================================
//==GAME BUILD===========================
Game* Game::Builder::build(){
    return new Game(height,
                    width,
                    initMoedas,
                    numOpponents,
                    perfilList,
                    board);
}
