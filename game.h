#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <map>
#include "perfil.h"
#include "utils.h"

//TODO:see where to use bool functions
//TODO:see wish fuctions from builder can be reused in game

class BoardPiece{
};

class Game{
public:
    //Builer for the class game
    class Builder;

private:
    const int height;
    const int width;
    const int initMoedas;
    const int numOpponents;
    const std::vector<Perfil*> perfilList;
public:

    Game(int h, int w, int m,int o,std::vector<Perfil*> pl):
        height(h),
        width(w),
        initMoedas(m),
        numOpponents(o),
        perfilList(pl){
    }

};

//BUILDER for the class Game
class Game::Builder{
private:
    int                 height;
    int                 width;
    int                 initMoedas;
    int                 numOpponents = 1;
    std::vector<Perfil*> perfilList;
    std::map<char,Point> casteloList;

    //VALIDATION functions
    int perfilExists(const char p);
    bool coloniaExists(const char c);
    bool isPointValid(Point p);
//tests if the castelo for that colonia was already placed
    bool isCasteloPlaced(const char c);

public:
    //SET functions for
    void setHeight (const int h){height = h;}
    void setWidth (const int w){width = w;}
    void setMoedas (const int m){initMoedas = m;}
    void setOpponents (const int o);
    int  setPerfil (const char p);

    //GET functions to print results
    int getHeight() const {return height;}
    int getWidth() const {return width;}
    int getMoedas() const {return initMoedas;}
    int getNumOpponents() const {return numOpponents;}

    //
    int setCastelo(const char label, const int x, const int y);

    //==PERFIL MANIPULATION==================
    int getPerfilIndex(const char label);
    Perfil* getPerfilFromList() {return perfilList.back();}
    Perfil* getPerfilFromList(const char p);
    //return 1:added -1:perfil doesnt exist -2:forca unavailable
    int addModifierToPerfil(char label, int id);
    //return 1:removed -1:perfil doesnt exist -2:Modifier doesnt exist
    int rmModifierFromPerfil(char label,int id);
    //return 1:removed 0:perfil not found
    int rmPerfil(char label);

    //calls the Game class constructor with the final values
    Game* build(){
        return new Game(height,
                        width,
                        initMoedas,
                        numOpponents,
                        perfilList);
    }

};

#endif
