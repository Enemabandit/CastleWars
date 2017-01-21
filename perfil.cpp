#include "perfil.h"

int Perfil::isForcaAvailable(int costForca){
    if (forca >= costForca)
        return 1;
    else
        return 0;
}

//return number of a specfic modifier occurrences in one perfil
int Perfil::getModifierOccurrences(int id){
    int occurrences = 0;
    //iterate through passiveMods
    for (std::vector<Modifier*>::iterator it = passiveMods.begin();
         it != passiveMods.end(); ++it){
        if ((*it)->getID() == id) occurrences++;
    }
    //iterate through activeMods
    for (std::vector<Modifier*>::iterator it = activeMods.begin();
         it != activeMods.end(); ++it){
        if ((*it)->getID() == id) occurrences++;
    }
    return occurrences;
}

//return a pointer to the first occurrence of the modifier id
//and its index
ModifierPosition Perfil::getFirstModifierOccurrence(int id){
    ModifierPosition pos;
    int index = 0;
    if (id <= 5){
        //iterate through passiveMods
        for (std::vector<Modifier*>::iterator it = passiveMods.begin();
             it != passiveMods.end(); ++it){
            if ((*it)->getID() == id){
                pos.mod = *it;
                pos.index = index;
                return pos;
            } else
                index++;
        }
    } else {
        //iterate through activeMods
        for (std::vector<Modifier*>::iterator it = activeMods.begin();
             it != activeMods.end(); ++it){
            if ((*it)->getID() == id){
                pos.mod = *it;
                pos.index = index;
                return pos;
            } else
                index++;
        }
    }
}

Modifier* Perfil::createNewModifier(int id){
switch(id){
case 1:
    return new Bandeira();
    break;
case 2:
    return new Superior();
    break;
case 3:
    return new PeleDura();
    break;
case 4:
    return new Armadura();
    break;
case 5:
    return new Faca();
    break;
case 6:
    return new Espada();
    break;
case 7:
    return new Agressao();
    break;
case 8:
    return new Ecologico();
    break;
case 9:
    return new HeatSeeker();
    break;
case 10:
    return new BuildSeeker();
    break;
case 11:
    return new Walker();
    break;
case 12:
    return new Remedio();
    break;
case 13:
    return new SecondChance();
    break;
case 14:
    return new Aluno();
    break;
default:
    return NULL;
    break;
}
}

//adds new modifier to a perfil
//retur 1:added 0:forca unavailable
int Perfil::addModifier(int id){
    //instancia um novo modifier, rependendo do seu id
    Modifier* mod = createNewModifier(id);
    if (isForcaAvailable(mod->getCostForca())){
        updateForca(mod->getCostForca());
        updateCost(mod->getCostMoedas());
        //testa se é modificador activo ou passivo e addiciona ao vector
        (id <= 5)? addPModifier(mod): addAModifier(mod);
        return 1;
    } else {
        return 0;
    }
}

//return 1:added 0:modifier doesnt exist
int Perfil::rmModifier(int id){
    if (getModifierOccurrences(id) != 0){
        ModifierPosition mod = getFirstModifierOccurrence(id);
        //update the perfil cost and forca
        updateCost((-mod.mod->getCostMoedas()));
        updateForca((-mod.mod->getCostForca()));
        //remove modifier from respective vector
        if (id <= 5) {
            //erase the modifier from vector
            passiveMods.erase(passiveMods.begin()+(mod.index));
        } else {
            //erase modifier from vector
            activeMods.erase(activeMods.begin()+(mod.index));
        }
        //destroy the modifier
        delete mod.mod;
        return 1;
    } else {
        return 0;
    }
}

void Perfil::deleteLists(){
    //iterate through passiveMods
    for (std::vector<Modifier*>::iterator it = passiveMods.begin();
         it != passiveMods.end(); ++it){
        delete (*it);
    }
    //iterate through activeMods
    for (std::vector<Modifier*>::iterator it = activeMods.begin();
         it != activeMods.end(); ++it){
        delete (*it);
    }
    passiveMods.clear();
    activeMods.clear();
}


//==PERFIL PASSIVE MODS======================
int Perfil::getPassiveAtaqueModifier(){
    int ataqueModifier = 0;
    for(std::vector<Modifier*>::iterator it = passiveMods.begin();
        it != passiveMods.end(); ++it){
        ataqueModifier += (*it)->getAtaque();
    }
    return ataqueModifier;
}
int Perfil::getPassiveDefesaModifier(){
    int defesaModifier = 0;
    for(std::vector<Modifier*>::iterator it = passiveMods.begin();
        it != passiveMods.end(); ++it){
        defesaModifier += (*it)->getDefesa();
    }
    return defesaModifier;
}
int Perfil::getPassiveSaudeModifier(){
    int saudeModifier = 0;
    for(std::vector<Modifier*>::iterator it = passiveMods.begin();
        it != passiveMods.end(); ++it){
        saudeModifier += (*it)->getSaude();
    }
    return saudeModifier;
}

//==PERFIL ACTIVE MODS=======================

//==MOVE=================
//NOTE:ma implementacao, deveria ter feito uma class para board
//     de modo a pedir agora o target
Point Modifier::move(){
    Point p;
    return p;
}
Point HeatSeeker::move(){
    Point p;
    return p;
}
Point BuildSeeker::move(){
    Point p;
    return p;
}
Point Walker::move(){
    Point p;
    //Point target;
    //target = getRandomPosition(,)
    return p;
}
