#include "perfil.h"


Modifier createNewModifier(int id){
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

//void Perfil::updateForca(int costForca){
//    forca -= costForca;
//}
