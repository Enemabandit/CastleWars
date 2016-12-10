#ifndef PERFIL_H
#define PERFIL_H

#include <iostream>
#include <vector>

class Modifier{
    int id;
    int costMoedas;
    int costForca;

};

class Bandeira: public Modifier{};
class Superior: public Modifier{};
class PeleDura: public Modifier{};
class Armadura: public Modifier{};
class Faca: public Modifier{};
class Espada: public Modifier{};
class Agressao: public Modifier{};
class Ecologico: public Modifier{};
class HeatSeeker: public Modifier{};
class BuildSeeker: public Modifier{};
class Walker: public Modifier{};
class Remedio: public Modifier{};
class SecondChance: public Modifier{};
class Aluno: public Modifier{};

class Perfil{
    const char label;
    int forca;
    int cost;
    std::vector<Modifier> passive;
    std::vector<Modifier> active;
};
#endif
