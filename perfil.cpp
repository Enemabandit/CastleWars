#include "perfil.h"


int Perfil::isForcaAvailable(int costForca){
    if (forca >= costForca)
        return 1;
    else
        return 0;
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
}
}

//adds new modifier to a perfil
//retur 1:added -1:perfil doesnt exist -2:forca unavailable
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
