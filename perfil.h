#ifndef PERFIL_H
#define PERFIL_H

#include <iostream>
#include <vector>

class Modifier{
protected:
    const int id;
    const int costMoedas;
    const int costForca;

    //CONSTRUCTOR
    Modifier(const int i,const int cm, const int cf): id(i),
                                                      costMoedas(cm),
                                                      costForca(cf){
    }

};

class Bandeira: public Modifier{
    Bandeira(): Modifier(1,1,0){
    }
};
class Superior: public Modifier{
    Superior(): Modifier(2,1,1){
    }
};
class PeleDura: public Modifier{
    PeleDura(): Modifier(3,2,2){
    }
};
class Armadura: public Modifier{
    Armadura(): Modifier(4,2,3){
    }
};
class Faca: public Modifier{
    Faca(): Modifier(5,1,1){
    }
};
class Espada: public Modifier{
    Espada(): Modifier(6,2,2){
    }
};
class Agressao: public Modifier{
    Agressao(): Modifier(7,1,1){
    }
};
class Ecologico: public Modifier{
    Ecologico(): Modifier(8,1,1){
    }
};
class HeatSeeker: public Modifier{
    HeatSeeker(): Modifier(9,1,1){
    }
};
class BuildSeeker: public Modifier{
    BuildSeeker(): Modifier(10,1,1){
    }
};
class Walker: public Modifier{
    Walker(): Modifier(11,1,1){
    }
};
class Remedio: public Modifier{
    Remedio(): Modifier(12,2,1){
    }
};
class SecondChance: public Modifier{
    SecondChance(): Modifier(13,3,1){
    }
};
class Aluno: public Modifier{
    Aluno(): Modifier(14,1,1){
    }
};

class Perfil{
    const char label;
    int forca;
    int cost;
    std::vector<Modifier> passive;
    std::vector<Modifier> active;
public:
    Perfil(const char l): label(l),
                          forca(10),
                          cost(0){
    }
};
#endif
