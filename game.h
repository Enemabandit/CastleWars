#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "perfil.h"

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
    const std::vector<Perfil> perfilList;
public:
    Game(int h, int w, int m,int o): height(h),
                                     width(w),
                                     initMoedas(m),
                                     numOpponents(o){
    }

};

//BUILDER for the class Game
class Game::Builder{
private:
    int height = 0;
    int width = 0;
    int initMoedas = 0;
    int numOpponents = 0;
    std::vector<Perfil> perfilList;
public:
    //SET functions for
    Builder& setHeight (const int h){this->height = h; return *this;}
    Builder& setWidth (const int w){this->width = w; return *this;}
    Builder& setMoedas (const int m){this->initMoedas = m; return *this;}
    Builder& setOpponents (const int o){this->numOpponents = o; return *this;}

    //GET functions to print results
    int getHeight() const {return height;}
    int getWidth() const {return width;}
    int getMoedas() const {return initMoedas;}
    int getNumOpponents() const {return numOpponents;}

    //Validation functions
    int perfilExists(const char p);

    //calls the Game class constructor with the final values
    Game build(){
        return Game(this->height,
                    this->width,
                    this->initMoedas,
                    this->numOpponents);
    }

};

#endif
