#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <vector>

//enum to be used on command validations
enum commandList{invalid,help,inicio,dim,moedas,oponentes,castelo,mkperfil,addperfil,subperfil,rmperfil,load};

//CLASS Command
class Command{
    const std::string fullCommand;
    const std::string commandToExecute;
    const commandList c;
    const std::vector<std::string> argVector;
public:
    //CONSTRUCTOR
    Command(std::string fc);

    //GET functions
    //function to get the commandList value for the inputed command
    std::string getCommandToExecute() const {return commandToExecute;}
    std::vector<std::string> getArgVector() const {return argVector;}
    commandList getC() const {return c;};

    //atributes the inputed command to the respective enum Command value (0/invalid if the command is not valid)
    commandList atributeCommand(std::string c) const;
    //returns a vector containing the arguments of the inputed command
    std::vector<std::string> getArgumentsVector (std::string fullCommand) const;

};

#endif
