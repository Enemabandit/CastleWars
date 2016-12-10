//Trabalho Prático
//TODO:review const on function arguments
#include <iostream>
#include <string>
#include <vector>
#include "utils.h"
#include "command.h"


class BoardPiece{
};

class Game{
    int numColumns;
    int numRows;
    BoardPiece** board;

};

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

//executes the configuration of a new simulation
Game setupConfig();

//returns a new board not initialized
BoardPiece** setBoard(int mRows, int mColumns);

int main(){
    std::cout << "Welcome!" << std::endl;

    Game game = setupConfig();

}

//executes the configuration of a new simulation
Game setupConfig(){

    Game game;
    int height;
    int width;
    BoardPiece** board;
    int initMoedas;
    int numOpponents;

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
                height = stringToPositiveInt(command.getArgVector()[0]);
                width = stringToPositiveInt(command.getArgVector()[1]);
                board=setBoard(height,width);
                std::cout << "-> Board " << height << "x" << width <<
                          " created with !sucess"<< std::endl;
                break;
            case moedas:
                initMoedas = stringToPositiveInt(command.getArgVector()[0]);
                std::cout << "-> " << initMoedas << " set as starting moedas!"
                          << std::endl;
                break;
            case oponentes:
                numOpponents = stringToPositiveInt(command.getArgVector()[0]);
                std::cout << "-> " << numOpponents << " opponents created!"
                          << std::endl;
                break;
            case castelo:
                placeCasteloOnBoard(command.getArgVector()[0],
                                    stringToPositiveInt(command.getArgVector()[1]),
                                    stringToPositiveInt(command.getArgVector()[2]));
                break;
            case mkperfil:
                createPerfil(command.getArgVector()[0].at(0));
                break;
            case addperfil:
                addCaracteristicaToPerfil(command.getArgVector()[0].at(0),
                                          stringToPositiveInt(command.getArgVector()[1]));
                break;
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

    return game;
}

BoardPiece** setBoard(const int mRows,const int mColumns){
    BoardPiece** board;
    board = new BoardPiece*[mRows-1];

    for (int i = 0; i < mRows; i++){
        board[i] = new BoardPiece[mColumns-1];
        for (int j = 0; j < mColumns; j++)
            board[i][j] = BoardPiece();
    }
    return board;
}
