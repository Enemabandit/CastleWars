//Trabalho Prático
//TODO:see ways to sanitize input strings on arguments (tamanho entre X e Y)
//TODO:review const on function arguments
#include <iostream>
#include <string>
#include <vector>

enum Command{invalid,help,inicio,dim,moedas,oponentes,castelo,mkperfil,addperfil,subperfil,rmperfil,load};
const int MAX_STRING_SIZE = 50;

//atributes the inputed command to the respective enum Command value (11/invalid if the command is not valid)
Command atributeCommand(std::string c);
//returns a vector containing the arguments of the inputed command
std::vector<std::string> getArgumentsVector(std::string fullCommand);
//converts a positive decimal integer in a string to int (returns -1 if the number is negative or not decimal)
int stringToPositiveInt(std::string s);

//print to stdout the help for caracteristicas
void printHelpCaracteristicas();
//print to stdout the help for the configuration commands
void printHelpConfiguration();

//TODO:function called by the dim command
void setBoard(int maxRows, int maxColumns){std::cout << "TO BE IMPLEMENTED setBoard(): "<< maxRows << maxColumns << std::endl;};
//TODO:function called by the moedas command
void setMoedas(int m){std::cout << "TO BE IMPLEMENTED setMoedas(): " << m << std::endl;};
//TODO:function called by the oponentes command
void setOponentes(int numOp){std::cout << "TO BE IMPLEMENTED setOponentes(): " << numOp << std::endl;};
//TODO:function called by the castelo command
void placeCasteloOnBoard(std::string colonia, int xCoord,int yCoord){std::cout << "TO BE IMPLEMENTED placeCasteloOnBoard(): " << colonia << xCoord << yCoord << std::endl;};
//TODO:function called by the mkperfil command
void createPerfil(char p){std::cout << "TO BE IMPLEMENTED createPerfil(): " << p << std::endl;};
//TODO:function called by the addperfil command
void addCaracteristicaToPerfil(char p,int c){std::cout << "TO BE IMPLEMENTED addCaracteristicaToPerfil(): " << p << c << std::endl;}
//TODO:function called by the subperfil command
void removeCaracteristicaFromPerfil(char p,int c){std::cout << "TO BE IMPLEMENTED removeCaracteristicaFromPerfil(): " << p << c << std::endl;}
//TODO:function called by the rmperfil command
void deletePerfil(char p){std::cout << "TO BE IMPLEMENTED deletePerfil(): " << p << std::endl;};
//TODO:function called by the load command
void loadConfiguration(std::string file){std::cout << "TO BE IMPLEMENTED loadConfiguration(): " << file << std::endl;};

int main(){
    std::cout << "Welcome!" << std::endl;

    //Configuration MENU
    std::cout << "***CONFIGURATION***" << std::endl;
    std::cout << "help for commands description" << std::endl;
    std::string fullCommand;
    do{
        std::cout << "game-config: ";
        //get the full command statement from user
        std::getline(std::cin,fullCommand);
        //get the command intended
        std::string command = fullCommand.substr(0,fullCommand.find_first_of(' '));
        Command c = atributeCommand(command);
        //get the arguments for the command
        std::string argString = fullCommand.substr(fullCommand.find_first_of(' ')+1);
        std::vector<std::string> argVector = getArgumentsVector(fullCommand);

        switch(c){
        case invalid:
            std::cout << "Command " << command <<" not recognized. (try help)" << std::endl;
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
                break;
            }
            //tests the input arguments and executes the coomand if valid
            if(stringToPositiveInt(argVector[0]) <= 0){
                std::cout << "invalid:argument (linhas) not decimal or is <= 0" << std::endl;
                break;
            } else {
                if(stringToPositiveInt(argVector[1]) <= 0){
                    std::cout << "invalid:argument (colunas) not decimal or is <= 0" << std::endl;
                    break;
                } else {
                    setBoard(stringToPositiveInt(argVector[0]),stringToPositiveInt(argVector[1]));
                }
            }
            break;
        case moedas:
            //expects 1 arguments
            if(argVector.size() != 1) {
                std::cout << "invalid: moedas expects 1 argument" << std::endl;
                break;
            }
            //tests the input arguments and executes the coomand if valid
            if(stringToPositiveInt(argVector[0]) < 0){
                std::cout << "invalid:argument not decimal or is <= 0" << std::endl;
                break;
            } else {
                    setMoedas(stringToPositiveInt(argVector[0]));
            }
            break;
        case oponentes:
            //expects 1 arguments
            if(argVector.size() != 1) {
                std::cout << "invalid: oponentes expects 1 argument" << std::endl;
                break;
            }
            //tests the input arguments and executes the coomand if valid
            if(stringToPositiveInt(argVector[0]) < 0){
                std::cout << "invalid:argument not decimal or is <= 0" << std::endl;
                break;
            } else {
                setOponentes(stringToPositiveInt(argVector[0]));
            }
            break;
        case castelo:
            //expects 3 arguments
            if(argVector.size() != 3) {
                std::cout << "invalid: castelo expects 3 arguments" << std::endl;
                break;
            }
            //tests the input arguments and executes the coomand if valid
            if(argVector[0].length() < 1 || argVector[0].length() > MAX_STRING_SIZE){
              std::cout << "invalid:argument (colonia) needs at least 1 character or has more than "
                        << MAX_STRING_SIZE << " characters." << std::endl;
            } else {
                if(stringToPositiveInt(argVector[1]) < 0){
                    std::cout << "invalid:argument (linhas) not decimal or is < 0" << std::endl;
                    break;
                } else {
                    if(stringToPositiveInt(argVector[2]) < 0){
                        std::cout << "invalid:argument (colunas) not decimal or is < 0" << std::endl;
                        break;
                    } else {
                        placeCasteloOnBoard(argVector[0],stringToPositiveInt(argVector[1]),
                                            stringToPositiveInt(argVector[2]));
                    }
                }
            }
            break;
        case mkperfil:
            //expects 1 arguments
            if(argVector.size() != 1) {
                std::cout << "invalid: mkperfil expects 1 argument" << std::endl;
                break;
            }
            //tests the input arguments and executes the coomand if valid
            if(argVector[0].length() != 1 || !isalpha(argVector[0][0])){
                std::cout << "invalid:argument is expected to be 1 alphabetic letter" << std::endl;
                break;
            } else {
                createPerfil(argVector[0].at(0));
            }
            break;
        case addperfil:
            //expects 2 arguments (1 for help)
            if(argVector.size() != 2){
                if(argVector.size() == 1 && !argVector[0].compare("help")){
                    printHelpCaracteristicas();
                    break;
                } else {
                    std::cout << "invalid: addperfil expects 2 argument (try addperfil help)" << std::endl;
                    break;
                }
            }
            //tests the input arguments and executes the coomand if valid
            if(argVector[0].length() != 1 || !isalpha(argVector[0][0])){
                std::cout << "invalid:argument is expected to be (perfil) (caracteristica id)" << std::endl;
                break;
            } else {
                if (stringToPositiveInt(argVector[1]) < 1 || stringToPositiveInt(argVector[1]) > 14){
                    std::cout << "invalid:argument (caracteristica id)  not found (try addperfil help)" << std::endl;
                } else {
                    addCaracteristicaToPerfil(argVector[0].at(0),stringToPositiveInt(argVector[1]));
                }
            }
            break;
        case subperfil:
            //expects 2 arguments (1 for help)
            if(argVector.size() != 2){
                if(argVector.size() == 1 && !argVector[0].compare("help")){
                    printHelpCaracteristicas();
                    break;
                } else {
                    std::cout << "invalid: subperfil expects 2 argument (try subperfil help)" << std::endl;
                    break;
                }
            }
            //tests the input arguments and executes the coomand if valid
            if(argVector[0].length() != 1 || !isalpha(argVector[0][0])){
                std::cout << "invalid:argument is expected to be (perfil) (caracteristica id)" << std::endl;
                break;
            } else {
                if (stringToPositiveInt(argVector[1]) < 1 || stringToPositiveInt(argVector[1]) > 14){
                    std::cout << "invalid:argument (caracteristica id)  not found (try subperfil help)";
                } else {
                    removeCaracteristicaFromPerfil(argVector[0].at(0),stringToPositiveInt(argVector[1]));
                }
            }
            break;
        case rmperfil:
            //expects 1 argument
            if(argVector.size() != 1) {
                std::cout << "invalid: rmperfil expects 1 argument" << std::endl;
                break;
            }
            //tests the input arguments and executes the coomand if valid
            if(argVector[0].length() != 1 || !isalpha(argVector[0][0])){
                std::cout << "invalid:argument is expected to be 1 alphabetic letter" << std::endl;
                break;
            } else {
                deletePerfil(argVector[0].at(0));
            }
            break;
        case load:
            //expects 1 argument
            if(argVector.size() != 1) {     std::cout << "invalid: load expects 1 argument" << std::endl;
                break;
            }
            //appending .txt when not specified TODO: ATTENTION append is changing argVector[]!! review
            (!argVector[0].substr(argVector[0].length() - 4,4).compare(".txt"))?
                loadConfiguration(argVector[0]) : loadConfiguration(argVector[0].append(".txt"));
            break;
        }
    } while (fullCommand != "inicio");
}
//atributes the inputed command to the respective enum Command value (11/invalid if the command is not valid)
Command atributeCommand(std::string c){
    if (c == "dim") return Command::dim;
    else if (c == "moedas") return Command::moedas;
    else if (c == "oponentes") return Command::oponentes;
    else if (c == "castelo") return Command::castelo;
    else if (c == "mkperfil") return Command::mkperfil;
    else if (c == "addperfil") return Command::addperfil;
    else if (c == "subperfil") return Command::subperfil;
    else if (c == "rmperfil") return Command::rmperfil;
    else if (c == "load") return Command::load;
    else if (c == "inicio") return Command::inicio;
    else if (c == "help") return Command::help;
    else return Command::invalid;
}
//returns a vector containing the arguments of the inputed command
std::vector<std::string> getArgumentsVector(std::string fullCommand){
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
//converts a string with a positive decimal integer to int (returns -1 if the string as anything but digits)
int stringToPositiveInt(std::string s){
    std::string stringValidated;
    for (std::string::iterator it = s.begin(); it < s.end(); it++){
        if(isdigit(*it)){
            stringValidated.push_back(*it);
        } else{
            return -1;
        }
    }
    int validatedNumber = std::stoi(stringValidated);
    return validatedNumber;
}
//print to stdout the help for caracteristicas
void printHelpCaracteristicas(){
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
void printHelpConfiguration(){
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
