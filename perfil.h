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

public:
    Modifier createNewModifier(int id);


    //GET functions
    int getCostMoedas() const {return costMoedas;}
    int getCostForca() const {return costForca;}

};

class Bandeira: public Modifier{
public:
    Bandeira(): Modifier(1,1,0){
    }
};
class Superior: public Modifier{
public:
    Superior(): Modifier(2,1,1){
    }
};
class PeleDura: public Modifier{
public:
    PeleDura(): Modifier(3,2,2){
    }
};
class Armadura: public Modifier{
public:
    Armadura(): Modifier(4,2,3){
    }
};
class Faca: public Modifier{
public:
    Faca(): Modifier(5,1,1){
    }
};
class Espada: public Modifier{
public:
    Espada(): Modifier(6,2,2){
    }
};
class Agressao: public Modifier{
public:
    Agressao(): Modifier(7,1,1){
    }
};
class Ecologico: public Modifier{
public:
    Ecologico(): Modifier(8,1,1){
    }
};
class HeatSeeker: public Modifier{
public:
    HeatSeeker(): Modifier(9,1,1){
    }
};
class BuildSeeker: public Modifier{
public:
    BuildSeeker(): Modifier(10,1,1){
    }
};
class Walker: public Modifier{
public:
    Walker(): Modifier(11,1,1){
    }
};
class Remedio: public Modifier{
public:
    Remedio(): Modifier(12,2,1){
    }
};
class SecondChance: public Modifier{
public:
    SecondChance(): Modifier(13,3,1){
    }
};
class Aluno: public Modifier{
public:
    Aluno(): Modifier(14,1,1){
    }
};

class Perfil{
    const char label;
    int forca;
    int cost;
    std::vector<Modifier> passiveMods;
    std::vector<Modifier> activeMods;

    //SET functions
    void updateForca(int costForca){forca -= costForca;}
    void updateCost(int costMoedas){cost += costMoedas;}
    void addPModifier(Modifier m){passiveMods.push_back(m);}
    void addAModifier(Modifier m){activeMods.push_back(m);}

    int isForcaAvailable(int costForca);

    //intantiate new modifier to be placed in the a perfil
    Modifier instantiateNewModifier(int id);

public:
    Perfil(const char l): label(l),
                          forca(10),
                          cost(0){
    }
    //GET functions
    char getLabel() const {return label;}
    int getForca() const {return forca;}

    //adds new modifier to a perfil
    //retur 1:added -1:perfil doesnt exist -2:forca unavailable
    int addModifier(int id);



};
#endif
