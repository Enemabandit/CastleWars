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
    else if (c == "foco") return commandList::foco;
    else if (c == "zoomout") return commandList::zoomout;
    else if (c == "setmoedas") return commandList::setmoedas;
    else if (c == "build") return commandList::build;
    else if (c == "list") return commandList::list;
    else if (c == "listp") return commandList::listp;
    else if (c == "listallp") return commandList::listallp;
    else if (c == "mkbuild") return commandList::mkbuild;
    else if (c == "repair") return commandList::repair;
    else if (c == "upgrade") return commandList::upgrade;
    else if (c == "sell") return commandList::sell;
    else if (c == "ser") return commandList::ser;
    else if (c == "next") return commandList::next;
    else if (c == "nextn") return commandList::nextn;
    else if (c == "ataca") return commandList::ataca;
    else if (c == "recolhe") return commandList::recolhe;
    else if (c == "fim") return commandList::fim;
    else if (c == "save") return commandList::save;
    else if (c == "restore") return commandList::restore;
    else if (c == "erase") return commandList::erase;
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
//TODO: validation of cases where no, or 1 argument is given is not working properly!
//TODO: rethink the type validations (use separete functions!!!)
//NOTE: isto pode ser simplificado, nao estou contente com a implementacao
int Command::validate(){
    int validation = 0;
    switch(c){
    case invalid:
        std::cout << "Command " << commandToExecute
                  <<" not recognized. (try help)" << std::endl;
        break;
    //=============================================
    //==CONFIGURATION FASE=========================
    case help:
        printHelpConfiguration();
        break;
    case inicio:
        //ends configuration and initiate execution
        //TODO:validation of the configuration
        validation = 1;
        break;
    case dim:
        //expects 2 arguments
        if(argVector.size() != 2) {
            std::cout << "invalid: dim expects 2 arguments" << std::endl;
        } else {
            //tests the input arguments
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
            //tests the input arguments
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
            //tests the input arguments
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
            //tests the input arguments
            if(argVector[0].length() != 1){
                std::cout << "invalid:argument (colonia) is expected to be 1 character"
                          << std::endl;
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
        //expects 1 arguments
        if(argVector.size() != 1) {
            std::cout << "invalid: mkperfil expects 1 argument"
                      << std::endl;
        } else {
            //tests the input arguments
            if(argVector[0].length() != 1 || !isalpha(argVector[0][0])){
                std::cout << "invalid:argument is expected to be"
                          << " 1 alphabetic letter" << std::endl;
            } else {
                validation = 1;
            }
        }
        break;
    case addperfil:
        //expects 2 arguments (1 for help)
        if(argVector.size() != 2){
            if(argVector.size() == 1 && !argVector[0].compare("help")){
                printHelpCaracteristicas();
            } else {
                std::cout << "invalid: addperfil expects 2 argument "
                          << "(try addperfil help)" << std::endl;
            }
        } else {
            if(argVector[0].length() != 1 || !isalpha(argVector[0][0])){
                std::cout << "invalid:argument is expected to be "
                          << "(perfil) (caracteristica id)" << std::endl;
            } else {
                //tests the input arguments
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
        //expects 2 arguments (1 for help)
        if(argVector.size() != 2){
            if(argVector.size() == 1 && !argVector[0].compare("help")){
                printHelpCaracteristicas();
            } else {
                std::cout << "invalid: subperfil expects 2 argument "
                          << "(try subperfil help)" << std::endl;
            }
        } else {
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
        //expects 1 argument
        if(argVector.size() != 1) {
            std::cout << "invalid: rmperfil expects 1 argument"
                      << std::endl;
        } else {
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
            validation = 1;
        }
        break;

    //=============================================
    //==SIMULATION FASE============================
    case foco:
        //expects 2 arguments
        if(argVector.size() != 2) {
            std::cout << "invalid: foco expects 2 arguments" << std::endl;
        } else {
            if(stringToPositiveInt(argVector[0]) <= 0){
                std::cout << "invalid:argument (linha) not decimal or is <= 0"
                          << std::endl;
            } else {
                if(stringToPositiveInt(argVector[1]) <= 0){
                    std::cout << "invalid:argument (coluna) "
                              << "not decimal or is <= 0" << std::endl;
                } else {
                    validation = 1;
                }
            }
        }
        break;
    case zoomout:
        //expects 1 arguments
        if(argVector.size() != 1) {
            std::cout << "invalid: zoomout expects 1 argument" << std::endl;
        } else {
            //tests the input arguments
            if(stringToPositiveInt(argVector[0]) < 0){
                std::cout << "invalid:argument not decimal or is <= 0"
                          << std::endl;
            } else {
                validation = 1;
            }
        }
        break;
    case setmoedas:
        //expects 2 arguments
        if(argVector.size() != 2){
            std::cout << "invalid: setmoedas expects 2 argument " << std::endl;
        } else {
            if(!isalpha(argVector[0][0])){
                std::cout << "invalid:argument is expected to be (colonia) (moedas)"
                          << std::endl;
            } else {
                if(stringToPositiveInt(argVector[1]) < 0){
                    std::cout << "invalid:argument (moedas) < 0 "<< std::endl;
                } else {
                    validation = 1;
                }
            }
        }
        break;
    case build:
        //expects 3 arguments
        if(argVector.size() != 3) {
            std::cout << "invalid: build expects 3 arguments" << std::endl;
        } else {
            //tests the input arguments
            if(argVector[0] != "torre" && argVector[0] != "quinta" &&
                argVector[0] != "Torre" && argVector[0] != "Quinta"){
                std::cout << "invalid:argument (edif) is expected to be Torre or Quinta!"
                          << std::endl;
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
    case list:
        //expects 1 argument
        if(argVector.size() != 1) {
            std::cout << "invalid: list expects 1 argument"
                      << std::endl;
        } else {
            if(argVector[0].length() != 1 || !isalpha(argVector[0][0])){
                std::cout << "invalid:argument is expected to be "
                          << "1 alphabetic letter" << std::endl;
            } else {
                validation = 1;
            }
        }
        break;
    case listp:
        //expects 1 argument
        if(argVector.size() != 1) {
            std::cout << "invalid: listp expects 1 argument"
                      << std::endl;
        } else {
            if(argVector[0].length() != 1 || !isalpha(argVector[0][0])){
                std::cout << "invalid:argument is expected to be "
                          << "1 alphabetic letter" << std::endl;
            } else {
                validation = 1;
            }
        }
        break;
    case listallp:
        //doesnt expect arguments
        validation = 1;
        break;
    case mkbuild:
        //expects 4 arguments
        if(argVector.size() != 4) {
            std::cout << "invalid: mkbuild expects 4 arguments" << std::endl;
        } else {
            //tests the input arguments
            if(argVector[0] != "torre" && argVector[0] != "quinta" &&
                argVector[0] != "Torre" && argVector[0] != "Quinta"){
                std::cout << "invalid:argument (edif) is expected to be Torre or Quinta!"
                          << std::endl;
            } else {
                if(stringToPositiveInt(argVector[1]) < 0){
                    std::cout << "invalid:argument (linhas) "
                              << "not decimal or is < 0!" << std::endl;
                } else {
                    if(stringToPositiveInt(argVector[2]) < 0){
                        std::cout << "invalid:argument (colunas) "
                                  << "not decimal or is < 0" << std::endl;
                    } else {
                        if(argVector[3].length() != 1 || !isalpha(argVector[3][0])){
                            std::cout << "invalid:argument (colonia) is expected to be "
                                      << "1 alphabetic letter" << std::endl;
                        } else {
                            validation = 1;
                        }
                    }
                }
            }
        }
        break;
    case repair:
        //expects 1 arguments
        if(argVector.size() != 1) {
            std::cout << "invalid: repair expects 1 argument" << std::endl;
        } else {
            //tests the input arguments
            if(stringToPositiveInt(argVector[0]) < 0){
                std::cout << "invalid:argument not decimal or is <= 0"
                          << std::endl;
            } else {
                validation = 1;
            }
        }
        break;
    case upgrade:
        //expects 1 arguments
        if(argVector.size() != 1) {
            std::cout << "invalid: upgrade expects 1 argument" << std::endl;
        } else {
            //tests the input arguments
            if(stringToPositiveInt(argVector[0]) < 0){
                std::cout << "invalid:argument not decimal or is <= 0"
                          << std::endl;
            } else {
                validation = 1;
            }
        }
        break;
    case sell:
        //expects 1 arguments
        if(argVector.size() != 1) {
            std::cout << "invalid: sell expects 1 argument" << std::endl;
        } else {
            //tests the input arguments
            if(stringToPositiveInt(argVector[0]) < 0){
                std::cout << "invalid:argument not decimal or is <= 0"
                          << std::endl;
            } else {
                validation = 1;
            }
        }
        break;
    case ser:
        //expects 2 arguments
        if(argVector.size() != 2) {
            std::cout << "invalid: ser expects 2 arguments" << std::endl;
        } else {
            //tests the input arguments
            if(stringToPositiveInt(argVector[0]) < 0){
                std::cout << "invalid:argument not decimal or is <= 0"
                          << std::endl;
            } else {
                if(argVector[1].length() != 1 || !isalpha(argVector[1][0])){
                    std::cout << "invalid:argument (perfil) is expected to be "
                              << "1 alphabetic letter" << std::endl;
                } else {
                    validation = 1;
                }
            }
        }
        break;
    case next:
        //doesnt expect arguments
        validation = 1;
        break;
    case nextn:
        //expects 1 arguments
        if(argVector.size() != 1) {
            std::cout << "invalid: nextn expects 1 argument" << std::endl;
        } else {
            //tests the input arguments
            if(stringToPositiveInt(argVector[0]) < 0){
                std::cout << "invalid:argument not decimal or is <= 0"
                          << std::endl;
            } else {
                validation = 1;
            }
        }
        break;
    case ataca:
        //doesnt expect arguments
        validation =1;
        break;
    case recolhe:
        //doesnt expect arguments
        validation =1;
        break;
    case fim:
        //doesnt expect arguments
        validation =1;
        break;
    case save:
        //expects 1 argument
        if(argVector.size() != 1) {
            std::cout << "invalid: save expects 1 argument" << std::endl;
        } else {
            if(argVector[0].length() < 1 || argVector[0].length() > MAX_STRING_SIZE){
                std::cout << "invalid: argument (name) is not of aceptable size! " << std::endl;
            } else {
                validation = 1;
            }
        }
        break;
    case restore:
        //expects 1 argument
        if(argVector.size() != 1) {
            std::cout << "invalid: restore expects 1 argument" << std::endl;
        } else {
            if(argVector[0].length() < 1 || argVector[0].length() > MAX_STRING_SIZE){
                std::cout << "invalid: argument (name) is not of aceptable size! " << std::endl;
            } else {
                validation = 1;
            }
        }
        break;
    case erase:
        //expects 1 argument
        if(argVector.size() != 1) {
            std::cout << "invalid: erase expects 1 argument" << std::endl;
        } else {
            if(argVector[0].length() < 1 || argVector[0].length() > MAX_STRING_SIZE){
                std::cout << "invalid: argument (name) is not of aceptable size! " << std::endl;
            } else {
                validation = 1;
            }
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
