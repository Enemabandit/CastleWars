#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <vector>

#include "utils.h"

//enum to be used on command validations
enum commandList{invalid,help,inicio,dim,moedas,oponentes,castelo,mkperfil,addperfil,subperfil,rmperfil,load};

//CLASS Command
//NOTE: para relatorio! devia ter feito uma class mãe para commandos e duas filhas para
//      a configuracao e outra para a simulacao, de forma a simplificar o codigo

class Command{
    const std::string fullCommand;
    const std::string commandToExecute;
    const commandList c;
    const std::vector<std::string> argVector;

    //functions to print help menus for the input commands
    void printHelpCaracteristicas();
    void printHelpConfiguration();

public:
    //CONSTRUCTOR
    Command(const std::string fc);

    //GET functions
    const std::string getCommandToExecute() const {return commandToExecute;}
    std::vector<std::string> getArgVector() const {return argVector;}
    std::vector<std::string> getArgVector(const std::string fc);
    commandList getC() const {return c;};
    commandList atributeCommand(std::string c) const;

    //Validation functions
    int validate();
};




#endif
