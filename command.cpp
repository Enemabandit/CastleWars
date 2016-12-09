#include "command.h"
Command::Command(std::string fc):
    fullCommand(fc),
    //get the command intended
    commandToExecute(fc.substr(0,fc.find_first_of(' '))),
    c(atributeCommand(commandToExecute)),
    //get the arguments for the command
    argVector(getArgumentsVector(fullCommand)){}

//atributes the inputed command to the respective enum Command value (0/invalid if the command is not valid)
commandList Command::atributeCommand(std::string c) const{
    if (c == "dim") return commandList::dim;
    else if (c == "moedas") return commandList::moedas;
    else if (c == "oponentes") return commandList::oponentes;
    else if (c == "castelo") return commandList::castelo;
    else if (c == "mkperfil") return commandList::mkperfil;
    else if (c == "addperfil") return commandList::addperfil;
    else if (c == "subperfil") return commandList::subperfil;
    else if (c == "rmperfil") return commandList::rmperfil;
    else if (c == "load") return commandList::load;
    else if (c == "inicio") return commandList::inicio;
    else if (c == "help") return commandList::help;
    else return commandList::invalid;}
//returns a vector containing the arguments of the inputed command
std::vector<std::string> Command::getArgumentsVector(std::string fullCommand) const{
    std::vector<std::string> args;
    //get the arguments from the fullcommand
    std::string argString = fullCommand.substr(fullCommand.find_first_of(' ')+1);
    std::string argument;

    for (std::string::iterator it = argString.begin(); it <= argString.end(); it++){
        if(*it != ' ' && *it != '\0')
            argument.push_back(*it);
        else{
            args.push_back(argument);
            argument.clear();
        }
    }
    return args;
}
