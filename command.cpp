#include "command.h"

//max size for string variables
const int MAX_STRING_SIZE = 50;
//Constructor for the class command
Command::Command(std::string fc):
    fullCommand(fc),
    commandToExecute(fc.substr(0,fc.find_first_of(' '))),
    c(atributeCommand(commandToExecute)),
    argVector(getArgVector(fullCommand)){
}

//atributes the inputed command to the respective enum Command value
//(0/invalid if the command is not valid)
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
std::vector<std::string> Command::getArgVector(const std::string fc){
    std::vector<std::string> args;
    //get the arguments from the fullcommand
    std::string argString = fc.substr(fullCommand.find_first_of(' ')+1);
    std::string argument;

    for(std::string::iterator it = argString.begin();
        it <= argString.end(); it++){
        if(*it != ' ' && *it != '\0')
            argument.push_back(*it);
        else{
            args.push_back(argument);
            argument.clear();
        }
    }
    return args;
}

//Validates the command
//returns 0 and prints the error when needed
//TODO: rethink the type validations (use separete functions?)
int Command::validate(){
    int validation = 0;
    switch(c){
    case invalid:
        std::cout << "Command " << commandToExecute
                  <<" not recognized. (try help)" << std::endl;
        break;
    case help:
        printHelpConfiguration();
        break;
    case inicio:
        //ends configuration and initiate execution
        //TODO:validation of the configuration
        break;
    case dim:
        //expects 2 arguments
        if(argVector.size() != 2) {
            std::cout << "invalid: dim expects 2 arguments" << std::endl;
        } else {
            //tests the input arguments and executes the coomand if valid
            if(stringToPositiveInt(argVector[0]) <= 0){
                std::cout << "invalid:argument (linhas) not decimal or is <= 0"
                          << std::endl;
            } else {
                if(stringToPositiveInt(argVector[1]) <= 0){
                    std::cout << "invalid:argument (colunas) "
                              << "not decimal or is <= 0" << std::endl;
                } else {
                    validation = 1;
                }
            }
        }
        break;
    case moedas:
        //expects 1 arguments
        if(argVector.size() != 1) {
            std::cout << "invalid: moedas expects 1 argument" << std::endl;
        } else {
            //tests the input arguments and executes the coomand if valid
            if(stringToPositiveInt(argVector[0]) < 0){
                std::cout << "invalid:argument not decimal or is <= 0"
                          << std::endl;
            } else {
                validation = 1;
            }
        }
        break;
    case oponentes:
        //expects 1 arguments
        if(argVector.size() != 1) {
            std::cout << "invalid: oponentes expects 1 argument" << std::endl;
        } else {
            //tests the input arguments and executes the coomand if valid
            if(stringToPositiveInt(argVector[0]) < 0){
                std::cout << "invalid:argument not decimal or is <= 0"
                          << std::endl;
            } else {
                validation = 1;
            }
        }
        break;
    case castelo:
        //expects 3 arguments
        if(argVector.size() != 3) {
            std::cout << "invalid: castelo expects 3 arguments" << std::endl;
        } else {
        //tests the input arguments and executes the coomand if valid
            if(argVector[0].length() < 1 ||
               argVector[0].length() > MAX_STRING_SIZE){
                std::cout << "invalid:argument (colonia) "
                          << "needs at least 1 character or has more than "
                          << MAX_STRING_SIZE << " characters." << std::endl;
            } else {
                if(stringToPositiveInt(argVector[1]) < 0){
                    std::cout << "invalid:argument (linhas) "
                              << "not decimal or is < 0!" << std::endl;
                } else {
                    if(stringToPositiveInt(argVector[2]) < 0){
                        std::cout << "invalid:argument (colunas) "
                                  << "not decimal or is < 0" << std::endl;
                    } else {
                        validation = 1;
                    }
                }
            }
        }
        break;
    case mkperfil:
        //TODO: test if perfil exists
        //expects 1 arguments
        if(argVector.size() != 1) {
            std::cout << "invalid: mkperfil expects 1 argument"
                      << std::endl;
        } else {
            //tests the input arguments and executes the coomand if valid
            if(argVector[0].length() != 1 || !isalpha(argVector[0][0])){
                std::cout << "invalid:argument is expected to be"
                          << " 1 alphabetic letter" << std::endl;
            } else {
                validation = 1;
            }
        }
        break;
    case addperfil:
        //TODO: not testing if perfil exists
        //expects 2 arguments (1 for help)
        if(argVector.size() != 2){
            if(argVector.size() == 1 && !argVector[0].compare("help")){
                printHelpCaracteristicas();
            } else {
                std::cout << "invalid: addperfil expects 2 argument "
                          << "(try addperfil help)" << std::endl;
            }
        } else {
        //tests the input arguments and executes the coomand if valid
            if(argVector[0].length() != 1 || !isalpha(argVector[0][0])){
                std::cout << "invalid:argument is expected to be "
                          << "(perfil) (caracteristica id)" << std::endl;
            } else {
                if(stringToPositiveInt(argVector[1]) < 1 ||
                   stringToPositiveInt(argVector[1]) > 14){
                    std::cout << "invalid:argument (caracteristica id) "
                              << " not found (try addperfil help)"
                              << std::endl;
                } else {
                    validation = 1;
                }
            }
        }
        break;
    case subperfil:
        //TODO: not testing if perfil exists
        //expects 2 arguments (1 for help)
        if(argVector.size() != 2){
            if(argVector.size() == 1 && !argVector[0].compare("help")){
                printHelpCaracteristicas();
            } else {
                std::cout << "invalid: subperfil expects 2 argument "
                          << "(try subperfil help)" << std::endl;
            }
        } else {
            //tests the input arguments and executes the coomand if valid
            if(argVector[0].length() != 1 || !isalpha(argVector[0][0])){
                std::cout << "invalid:argument is expected to be "
                          << "(perfil) (caracteristica id)" << std::endl;
            } else {
                if(stringToPositiveInt(argVector[1]) < 1 ||
                   stringToPositiveInt(argVector[1]) > 14){
                    std::cout << "invalid:argument (caracteristica id) "
                              << "not found (try subperfil help)";
                } else {
                    validation = 1;
                }
            }
        }
        break;
    case rmperfil:
        //TODO: not testing if perfil exists
        //expects 1 argument
        if(argVector.size() != 1) {
            std::cout << "invalid: rmperfil expects 1 argument"
                      << std::endl;
        } else {
            //tests the input arguments and executes the coomand if valid
            if(argVector[0].length() != 1 || !isalpha(argVector[0][0])){
                std::cout << "invalid:argument is expected to be "
                          << "1 alphabetic letter" << std::endl;
            } else {
                validation = 1;
            }
        }
        break;
    case load:
        //expects 1 argument
        if(argVector.size() != 1) {
            std::cout << "invalid: load expects 1 argument" << std::endl;
        } else {
            validation = 0;
        }
        break;
    }
    return validation;
}

//print to stdout the help for caracteristicas
void Command::printHelpCaracteristicas(){
    std::cout << "+----------------------------+" << std::endl;
    std::cout << "|    Caracteristicas List    |" << std::endl;
    std::cout << "+--------+-------------------+" << std::endl;
    std::cout << "|   ID   |   Name            |" << std::endl;
    std::cout << "+----------------------------+" << std::endl;
    std::cout << "|   1    |   Bandeira        |" << std::endl;
    std::cout << "|   2    |   Superior        |" << std::endl;
    std::cout << "|   3    |   Pele Dura       |" << std::endl;
    std::cout << "|   4    |   Armadura        |" << std::endl;
    std::cout << "|   5    |   faca            |" << std::endl;
    std::cout << "|   6    |   Espada          |" << std::endl;
    std::cout << "|   7    |   Agressão        |" << std::endl;
    std::cout << "|   8    |   Ecologico       |" << std::endl;
    std::cout << "|   9    |   HeatSeeker      |" << std::endl;
    std::cout << "|   10   |   BuildSeeker     |" << std::endl;
    std::cout << "|   11   |   Walker          |" << std::endl;
    std::cout << "|   12   |   Remedio         |" << std::endl;
    std::cout << "|   13   |   SecondChance    |" << std::endl;
    std::cout << "|   14   |   Aluno           |" << std::endl;
    std::cout << "+--------+-------------------+" << std::endl;
}
//print to stdout the help for the configuration commands
void Command::printHelpConfiguration(){
    std::cout << "+-----------------------------------------------------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                                                 Configuration Commands                                                |" << std::endl;
    std::cout << "+----------------+-----------------------------------+------------------------------------------------------------------+" << std::endl;
    std::cout << "|   Coomand      |   arguments                       |   Description                                                    |" << std::endl;
    std::cout << "+----------------+-----------------------------------+------------------------------------------------------------------+" << std::endl;
    std::cout << "|   dim          |   lin<i> col<i>                   |   Define a dimensão da planicie                                  |" << std::endl;
    std::cout << "|   moedas       |   numero<i>                       |   Define a quantidade de moedas inicias das colonias             |" << std::endl;
    std::cout << "|   oponentes    |   numero<i>                       |   Define quantas colonias controlads pelo computador vao haver   |" << std::endl;
    std::cout << "|                |                                   |      default: 1                                                  |" << std::endl;
    std::cout << "|   castelo      |   colonia<s> lin<i> col<i>        |   Define a posicao do castelo da colonia indicada                |" << std::endl;
    std::cout << "|                |                                   |      default: aleatorio                                          |" << std::endl;
    std::cout << "|   mkperfil     |   perfil<c>                       |   define um novo perfil identificado por uma letra               |" << std::endl;
    std::cout << "|   rmperfil     |   perfil<c>                       |   elimina o perfil indicado                                      |" << std::endl;
    std::cout << "|   addperfil    |   perfil<c> idCaracteristica<i>   |   Adiciona a carecteristica indicada ao perfil indicado          |" << std::endl;
    std::cout << "|   subperfil    |   perfil<c> idCaracteristica<i>   |   Remove a caracteristica indicada ao perfil indicado            |" << std::endl;
    std::cout << "|   load         |   ficheiro<s>                     |   Carrega a configuracao guardada                                |" << std::endl;
    std::cout << "|   inicio       |                                   |   Inicia a simulacao                                             |" << std::endl;
    std::cout << "|   help         |                                   |   mostra esta janela                                             |" << std::endl;
    std::cout << "+----------------+-----------------------------------+------------------------------------------------------------------+" << std::endl;
    std::cout << "|                                             dataTypes: int<i> string(50 max length)<s> char<c>(only aplhabet letters) |" << std::endl;
    std::cout << "+----------------+-----------------------------------+------------------------------------------------------------------+" << std::endl;
}
