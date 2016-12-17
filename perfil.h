#ifndef PERFIL_H
#define PERFIL_H

#include <iostream>
#include <vector>
#include "utils.h"

class Modifier{
protected:
    const int id;
    const std::string label;
    const int costMoedas;
    const int costForca;

    //CONSTRUCTOR
    Modifier(const int i,std::string l,const int cm, const int cf):
        id(i),
        label(l),
        costMoedas(cm),
        costForca(cf){
    }

public:

    //GET functions
    int getCostMoedas() const {return costMoedas;}
    int getCostForca() const {return costForca;}
    int getID(){return id;}

    //TODO:implement the move functions for each of the modifiers
    //virtual void move();
};

class Bandeira: public Modifier{
public:
    Bandeira(): Modifier(1,"Bandeira",1,0){
    }
};
class Superior: public Modifier{
public:
    Superior(): Modifier(2,"Superior",1,1){
    }
};
class PeleDura: public Modifier{
public:
    PeleDura(): Modifier(3,"Pele Dura",2,2){
    }
};
class Armadura: public Modifier{
public:
    Armadura(): Modifier(4,"Armadura",2,3){
    }
};
class Faca: public Modifier{
public:
    Faca(): Modifier(5,"Faca",1,1){
    }
};
class Espada: public Modifier{
public:
    Espada(): Modifier(6,"Espada",2,2){
    }
};
class Agressao: public Modifier{
public:
    Agressao(): Modifier(7,"Agressao",1,1){
    }
};
class Ecologico: public Modifier{
public:
    Ecologico(): Modifier(8,"Ecologico",1,1){
    }
};
class HeatSeeker: public Modifier{
public:
    HeatSeeker(): Modifier(9,"HeatSeeker",1,1){
    }
};
class BuildSeeker: public Modifier{
public:
    BuildSeeker(): Modifier(10,"BuildSeeker",1,1){
    }
};
class Walker: public Modifier{
public:
    Walker(): Modifier(11,"Walker",1,1){
    }

    //TODO:implement the move functions for each of the modifiers
    //void move();
};
class Remedio: public Modifier{
public:
    Remedio(): Modifier(12,"Remedio",2,1){
    }
};
class SecondChance: public Modifier{
public:
    SecondChance(): Modifier(13,"Second Chance",3,1){
    }
};
class Aluno: public Modifier{
public:
    Aluno(): Modifier(14,"Aluno",1,1){
    }
};

//structure that indicates the index of a modifier in a vector
typedef struct {
    int index;
    Modifier * mod;
} ModifierPosition;

class Perfil{
private:
    const char label;
    int forca;
    int cost;
    //TODO:think about using lists
    std::vector<Modifier*> passiveMods;
    std::vector<Modifier*> activeMods;


    //SET functions
    void updateForca(int costForca){forca -= costForca;}
    void updateCost(int costMoedas){cost += costMoedas;}
    void addPModifier(Modifier *m){passiveMods.push_back(m);}
    void addAModifier(Modifier *m){activeMods.push_back(m);}

    //GET functions
    std::vector<Modifier*>* getPassiveMods(){return &passiveMods;}

    int isForcaAvailable(int costForca);

    //return number of a specfic modifier occurrences in one perfil
    int getModifierOccurrences(int id);
    //return a pointer to the first occurrence of the modifier id
    //and its index
    ModifierPosition getFirstModifierOccurrence(int id);

    Modifier* createNewModifier(int id);

public:
    Perfil(const char l): label(l),
                          forca(10),
                          cost(0){
    }
    //GET functions
    char getLabel() const {return label;}
    int getForca() const {return forca;}

    //return 1:added 0:forca unavailable
    int addModifier(int id);
    //return 1:added 0:modifier doesnt exist
    int rmModifier(int id);


};

#endif
