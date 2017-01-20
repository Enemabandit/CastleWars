#include "game.h"

//=======================GAME BUILDER================================
//===================================================================
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
    //TODO: establish a limit to the number of perfils
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

void Game::Builder::placeCastelosOnBoard(){
    Point p;
    for(int i=0;i<numOpponents;i++){
        p = coloniasList[i]->getCastelo()->getCoords();
        board[(p.x)-1][(p.y)-1] = coloniasList[i]->getCastelo();
    }
}

//=======================================
//==COLONIA MANIPULATION=================
int Game::Builder::createColonias(){
    Colonia* newColonia;
    for (char i = 'a'; i <= 'a'+numOpponents; i++){
        if (i == 'a'){
            //user controled colonia

            newColonia = new Colonia(initMoedas,i,perfilList,createCastelo(i));
        } else {
            //computer controled colonia
            //TODO: alterar a lista de perfis dos BOTS
            newColonia = new Colonia(initMoedas,i,perfilList,createCastelo(i));
        }
        coloniasList.push_back(newColonia);
    }

    if(coloniasList.size() != (unsigned int)(numOpponents +1))
        return 0;
    else
        return 1;
}

//TODO: think and implement minimum distance between castles
BoardPiece* Game::Builder::createCastelo(char label){
    BoardPiece* newCastelo;
    std::map<char,Point>::iterator it = casteloList.find(label);

    if(it != casteloList.end())
        newCastelo = new Castelo(it->second);
    else {
        newCastelo = new Castelo(getRandomPosition(height,width));
    }

    return newCastelo;
}


//=======================================
//==GAME BUILD===========================
Game* Game::Builder::build(){
    return new Game(height,
                    width,
                    initMoedas,
                    numOpponents,
                    perfilList,
                    board,
                    coloniasList);
}

//=======================GAME========================================
//===================================================================

void Game::run(){

    //Game Menu
    std::cout << "***Game Menu***" << std::endl;
    std::cout << "" << std::endl;
    std::string fullCommand;
    do{
        std::cout << "game-run: ";
        std::getline(std::cin,fullCommand);
        Command command = Command(fullCommand);
        if(command.validate()){
            switch(command.getC()){
            case invalid:
                break;
            case setmoedas:
                setMoedas(command.getArgVector()[0][0],
                          stringToPositiveInt(command.getArgVector()[1]));
                break;
            //TODO: reorganize code!!! really ugly
            case build:
            {
                //variables created for ease of code reading
                std::string type = command.getArgVector()[0];
                int y = stringToPositiveInt(command.getArgVector()[1]);
                int x = stringToPositiveInt(command.getArgVector()[2]);
                Colonia* c = getColoniaFromList('a');

                if(coordsInbounds(y,x)){
                    if(coordsInRangeOfCastle(y,x,c)){
                        if(isSpaceFree(y,x)){
                            if (makeBuilding(type,y,x,c)){
                                std::cout<< "Success: " << type << " created!"
                                         << std::endl;
                            } else {
                                std::cout << "invalid: not enought money!"
                                          << std::endl;
                            }
                        } else {
                            std::cout <<"invalid: coordinates already ocupied!"
                                      << std::endl;
                        }
                    } else {
                        std::cout<< "invalid: Coords out of range of Castle! "
                                 << std::endl;
                    }
                }else {
                    std::cout<< "invalid : Coords out of bounds!" << std::endl;
                }
            }
            break;
            case mkbuild:
            {
                //variables created for ease of code reading
                std::string type = command.getArgVector()[0];
                int y = stringToPositiveInt(command.getArgVector()[1]);
                int x = stringToPositiveInt(command.getArgVector()[2]);
                char c = command.getArgVector()[3][0];


                if(coordsInbounds(y,x)){
                    //TODO: should it override other buildings?
                    if(isSpaceFree(y,x)){
                        if(coloniaExists(c)){
                            makeBuilding(type,y,x,getColoniaFromList(c),1);
                        } else {
                            std::cout <<"invalid: Colonia " << c
                                      << " doesnt exist!" << std::endl;
                        }
                    } else {
                        std::cout << "invalid: Coordinates already ocupied!"
                                  << std::endl;
                    }
                } else {
                    std::cout << "invalid: Coords out of bounds!" << std::endl;
                }
            }
            break;
            case sell:
            {
                Colonia* colonia = getColoniaFromList('a');
                BoardPiece* edificio;

                edificio = colonia->sellEdificio(
                    stringToPositiveInt(command.getArgVector()[0]));
                //make board point to null
                deleteBuildingFromBoard(edificio);
                //free memory
                delete(edificio);
            }
            break;
            default:
                std::cout << "Command: " << command.getCommandToExecute()
                          << " is not from configuration fase!" << std::endl;
                break;
            }
        }
    } while (fullCommand != "fim");
}

//=======================================
//==COLONIA FUNCTIONS====================
bool Game::coloniaExists(char c){
    if(c > 'a' + numOpponents)
        return false;
    else
        return true;
}

Colonia* Game::getColoniaFromList(char c){
    Colonia* coloniaFound;
    for (std::vector<Colonia*>::iterator it = colonias.begin();
         it != colonias.end(); ++it){
        if ((*it)->getLabel() == c){
            coloniaFound=*it;
        }
    }
    return coloniaFound;
}


//defines the number os moedas a colonia has (debug porposes)
//return 1: value set / return 0: colonia not found
int Game::setMoedas(char c, int value){
    Colonia* colonia;
    if (coloniaExists(c)){
        colonia = getColoniaFromList(c);
        colonia->setMoedas(value);
        return 1;
    } else {
        return 0;
    }
}

//=======================================
//==BOARDPIECE FUNCTIONS=================

bool Game::coordsInRangeOfCastle(int y,int x,Colonia* colonia){
    if(x <= (colonia->getCastelo()->getCoords().x + 10) &&
       x >= (colonia->getCastelo()->getCoords().x - 10) &&
       y <= (colonia->getCastelo()->getCoords().y + 10) &&
       y >= (colonia->getCastelo()->getCoords().y - 10)){
        return true;
    } else {
        return false;
    }
}

//expects validated input
//freeFlag: 1->mkbuild, command 0->build(default)
//return 1:created -1:not enough money
int Game::makeBuilding(std::string buildingType,
                       int y,int x,
                       Colonia* colonia,
                       int freeFlag){
    int result = 0;
    //recieves 1 if buildingType is Torre and 0 if Quinta
    int type;
    (buildingType == "Torre" || buildingType == "torre")? type = 1 :type = 2;

    //transforms the coordinates given to a point
    Point p;
    p.x = x;
    p.y = y;

    BoardPiece* newBuilding = NULL;
    switch(type){
    case 1:
        //Creates a new Torre
        if((newBuilding = colonia->createTorre(p,freeFlag)) != NULL){
            result = 1;
        } else {
            result = -1;
        }
        break;
    case 2:
        //Creates a new Quinta
        if((newBuilding = colonia->createQuinta(p,freeFlag)) != NULL){
            result = 1;
        } else {
            result = -1;
        }
        break;
    default:
        //should never reach this default case
        std::cout << "invalid:unknown building type!";
        break;
    }
    placeBuildingOnBoard(newBuilding);
    return result;
}


//=======================================
//==BOARD FUNCTIONS======================

//expects valid input
void Game::placeBuildingOnBoard(BoardPiece* b){
    board[(b->getCoords().x)-1][(b->getCoords().y)-1] = b;
}

bool Game::coordsInbounds(int y,int x){
    if (y >= 1 && y <= (int)board.size() &&
        x >= 1 && x <= (int)board[1].size())
        return true;
    else
        return false;
}

bool Game::isSpaceFree(int y, int x){
    if (board[x-1][y-1] == NULL)
        return true;
    else
        return false;
}

void Game::deleteBuildingFromBoard(BoardPiece* b){
    board[b->getCoords().y -1][b->getCoords().x -1] = NULL;
}
