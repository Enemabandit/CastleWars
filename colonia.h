#ifndef COLONIA_H
#define COLONIA_H

#include <iostream>
#include "boardpiece.h"
#include "perfil.h"

class Colonia{
    std::string name;
    Edificio edificios[];
    Ser seres[];
    Perfil perfis[];
};

#endif
