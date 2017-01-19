//Trabalho Prático
//TODO:review const on function arguments
#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
#include "command.h"
#include "game.h"


void placeCasteloOnBoard(std::string colonia, int xCoord,int yCoord){std::cout << "TO BE IMPLEMENTED placeCasteloOnBoard(): " << colonia << xCoord << yCoord << std::endl;};
//TODO:function called by the load command
void loadConfiguration(std::string file){std::cout << "TO BE IMPLEMENTED loadConfiguration(): " << file << std::endl;};

//executes the configuration of a new simulation
Game* setupConfig();

//returns a new board not initialized
BoardPiece** setBoard(int mRows, int mColumns);

int main(){
    std::cout << "Welcome!" << std::endl;

    Game* game = setupConfig();

    std::cout << "ENDED!!" << std::endl;
}

//executes the configuration of a new simulation
Game* setupConfig(){

    Game::Builder builder;

    //Configuration MENU
    std::cout << "***CONFIGURATION***" << std::endl;
    std::cout << "help for commands description" << std::endl;
    std::string fullCommand;
    do{
        std::cout << "game-config: ";
        //get the full command statement from user
        std::getline(std::cin,fullCommand);
        Command command = Command(fullCommand);
        if(command.validate()) {
            switch(command.getC()){
            case invalid:
                break;
            case help:
                //NOTE: command.validate() is showing this menu
                break;
            case inicio:
                //ends configuration fase and initiate execution
                //TODO:inform the default values used
                //TODO:validation of the configuration
                //TODO:ends config fase only when 5 prefils are present!

                builder.createBoard();
                builder.createColonias();
                builder.placeCastelosOnBoard();

                break;
            case dim:
                //TODO:reset the castle positions
                builder.setHeight(stringToPositiveInt(
                                      command.getArgVector()[0]));
                builder.setWidth(stringToPositiveInt(
                                     command.getArgVector()[1]));
                std::cout << "-> Dimensions " << builder.getHeight() << "x"
                          << builder.getWidth() << " set with sucess!"
                          << std::endl;
                break;
            case moedas:
                builder.setMoedas(stringToPositiveInt(
                                      command.getArgVector()[0]));
                std::cout << "-> " << builder.getMoedas()
                          << " set as starting moedas!" << std::endl;
                break;
            case oponentes:
                builder.setOpponents(stringToPositiveInt(
                                         command.getArgVector()[0]));
                std::cout << "-> " << builder.getNumOpponents()
                          << " opponents created!" << std::endl;
                break;
            case castelo:
            {
                char label = command.getArgVector()[0].at(0);
                int x = stringToPositiveInt(command.getArgVector()[1]);
                int y = stringToPositiveInt(command.getArgVector()[2]);
                int err = builder.setCastelo(label,x,y);

                switch (err){
                case 1:
                    std::cout << "->Castelo set to colonia " << label
                              << " at (" << x << ","<< y  <<")!" << std::endl;
                    break;
                case -1:
                    std::cout << "Colonia " << label << " doesnt exist!"
                              << std::endl;
                    break;
                case -2:
                    std::cout << "Position (" << x << "," << y
                              << ") is invalid!" << std::endl;
                    break;
                default:
                    std::cout << "Erro adding castelo!" << std::endl;
                    break;
                }
                break;
            }
            case mkperfil:
                if(builder.setPerfil(command.getArgVector()[0].at(0))){
                    std::cout << "-> Perfil "
                              << builder.getPerfilFromList()->getLabel()
                              << " created!" << std::endl;
                } else {
                    std::cout << "Perfil " << command.getArgVector()[0]
                              << " already exists!" << std::endl;
                }
                break;
            case addperfil:
            {
                //intermidiary variables for ease of read
                char label = command.getArgVector()[0].at(0);
                int id = stringToPositiveInt(command.getArgVector()[1]);
                int err = builder.addModifierToPerfil(label,id);

                switch (err){
                case 1:
                    //TODO: consider print Modifier label
                    std::cout << "->Caracteristica: "
                              << id << " added to "<< "Perfil "
                              << label << "!" << std::endl;
                    break;
                case -1:
                    std::cout << "Perfil " << label << " doesnt exist!"
                              << std::endl;
                    break;
                case -2:
                    std::cout << "Perfil " << label
                              << " doesnt have enough forca" << std::endl;
                    break;
                default:
                    std::cout << "Erro adding caracteristica!" << std::endl;
                    break;
                }
                break;
            }
            case subperfil:
            {
                //intermidiary variables for ease of read
                char label = command.getArgVector()[0].at(0);
                int id = stringToPositiveInt(command.getArgVector()[1]);
                int err = builder.rmModifierFromPerfil(label,id);

                switch (err){
                case 1:
                    //TODO: consider print Modifier label
                    std::cout << "->Caracteristica: "
                              << id << " removed from "<< "Perfil "
                              << label << "!" << std::endl;
                    break;
                case -1:
                    std::cout << "Perfil " << label << " doesnt exist!"
                              << std::endl;
                    break;
                case -2:
                    std::cout << "There is no Caracteristica " << id
                              << " in " << label << std::endl;
                    break;
                default:
                    std::cout << "Erro adding caracteristica!" << std::endl;
                    break;
                }
                break;
            }
            case rmperfil:
            {
                char label = command.getArgVector()[0].at(0);
                int err = builder.rmPerfil(label);
                err?
                    std::cout << "->Perfil " << label << " eliminated!"
                              << std::endl :
                    std::cout << "Perfil " << label << " not found!"
                              << std::endl;
                break;
            }
            case load:
                //TODO: rethink if is needed
                (!command.getArgVector()[0].substr(command.getArgVector()[0].length() - 4,4).compare(".txt"))?
                    loadConfiguration(command.getArgVector()[0]) :
                    loadConfiguration(command.getArgVector()[0].append(".txt"));
                break;
            }
        }
    } while (fullCommand != "inicio");

    return builder.build();
}
