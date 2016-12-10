#include "game.h"

Game::Builder& Game::Builder::setPerfil (const char p){
    Perfil newPerfil(p);
    this->perfilList.push_back(newPerfil);
    return *this;
}

int Game::Builder::perfilExists(const char p){
    for(std::vector<Perfil>::iterator it = perfilList.begin();
        it != perfilList.end(); ++it){
        if (it->getLabel() == p)
            return 1;
    }
    return 0;
}

Perfil* Game::Builder::getPerfilFromList(const char p){
    int index=0;
    for(std::vector<Perfil>::iterator it = perfilList.begin();
        it != perfilList.end(); ++it){
        if (it->getLabel() == p){
            Perfil* found = &perfilList[index];
            return found;
        }
        index++;
    }
}
