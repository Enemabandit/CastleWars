//Trabalho Prático
//TODO:review const on function arguments
#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
#include "command.h"
#include "game.h"


void placeCasteloOnBoard(std::string colonia, int xCoord,int yCoord){std::cout << "TO BE IMPLEMENTED placeCasteloOnBoard(): " << colonia << xCoord << yCoord << std::endl;};
//TODO:function called by the addperfil command
void addCaracteristicaToPerfil(char p,int c){std::cout << "TO BE IMPLEMENTED addCaracteristicaToPerfil(): " << p << c << std::endl;}
//TODO:function called by the subperfil command
void removeCaracteristicaFromPerfil(char p,int c){std::cout << "TO BE IMPLEMENTED removeCaracteristicaFromPerfil(): " << p << c << std::endl;}
//TODO:function called by the rmperfil command
void deletePerfil(char p){std::cout << "TO BE IMPLEMENTED deletePerfil(): " << p << std::endl;};
//TODO:function called by the load command
void loadConfiguration(std::string file){std::cout << "TO BE IMPLEMENTED loadConfiguration(): " << file << std::endl;};

//executes the configuration of a new simulation
Game setupConfig();

//returns a new board not initialized
BoardPiece** setBoard(int mRows, int mColumns);
//checks if the perfil (label) alredy exists in perfilList
int PerfilExists(char label);

int main(){
    std::cout << "Welcome!" << std::endl;

    Game game = setupConfig();



}

//executes the configuration of a new simulation
Game setupConfig(){

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
                break;
            case inicio:
                //ends configuration and initiate execution
                //TODO:validation of the configuration
                break;
            case dim:
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
                placeCasteloOnBoard(command.getArgVector()[0],
                                    stringToPositiveInt(command.getArgVector()[1]),
                                    stringToPositiveInt(command.getArgVector()[2]));
                break;
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
                removeCaracteristicaFromPerfil(command.getArgVector()[0].at(0),
                                               stringToPositiveInt(command.getArgVector()[1]));
                break;
            case rmperfil:
                deletePerfil(command.getArgVector()[0].at(0));
                break;
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

BoardPiece** setBoard(const int height,const int weight){
    BoardPiece** board;
    board = new BoardPiece*[height-1];

    for (int i = 0; i < height; i++){
        board[i] = new BoardPiece[weight-1];
        for (int j = 0; j < height; j++)
            board[i][j] = BoardPiece();
    }
    return board;
}

