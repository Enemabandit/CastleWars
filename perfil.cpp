#include "perfil.h"


int Perfil::isForcaAvailable(int costForca){
    if (forca >= costForca)
        return 1;
    else
        return 0;
}

Modifier Perfil::instantiateNewModifier(int id){
    switch(id){
    case 1:
        return Bandeira();
        break;
    case 2:
        return Superior();
        break;
    case 3:
        return PeleDura();
        break;
    case 4:
        return Armadura();
        break;
    case 5:
        return Faca();
        break;
    case 6:
        return Espada();
        break;
    case 7:
        return Agressao();
        break;
    case 8:
        return Ecologico();
        break;
    case 9:
        return HeatSeeker();
        break;
    case 10:
        return BuildSeeker();
        break;
    case 11:
        return Walker();
        break;
    case 12:
        return Remedio();
        break;
    case 13:
        return SecondChance();
        break;
    case 14:
        return Aluno();
        break;

    }
}

//adds new modifier to a perfil
//retur 1:added -1:perfil doesnt exist -2:forca unavailable
int Perfil::addModifier(int id){
    //instancia um novo modifier, rependendo do seu id
    Modifier mod = instantiateNewModifier(id);
    if (isForcaAvailable(mod.getCostForca())){
        //testa se é modificador activo ou passivo e addiciona ao vector
        (id <= 5)? addPModifier(mod): addAModifier(mod);
        return 1;
    } else {
        return 0;
    }
}
