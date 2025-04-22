#include <iostream>
#include "game.h"


Game::Game(int difficultyLevel) {
    isCheckmate = false;
    isDraw = false;
    whiteTurn = true;
    moveNumber = 1;
    //std::cout << difficultyLevel;

}

void Game::startGame() {
    std::cout << "Starting game!\n";
    while(!isCheckmate && !isDraw) {
        //std::cout << "Test";
        board.drawBoard();
        std::cout << "Type in your move in square Notation: e2e4, SquareToMoveFrom and SquareToMoveTo\n";
        std::cout << "If you wanna castle use CWQS (Castling White Queen Side), CBKS (Castling Black King Side) etc.\n";
        if(whiteTurn) std::cout << "Its whites turn and the move number is: " << moveNumber << "\n";
        else std::cout << "Its blacks turn and the move number is: " << moveNumber << "\n";
        std::string move;
        std::cin >> move;
        if(move.length() != 4) {
            std::cout << "Move lenght is wrong :(\n\n";
            continue;
        }
        moveNumber++;
        whiteTurn = !whiteTurn;
        std::cout << "\n";
    }
}

void Game::parseMove(std::string move) {

}

bool Game::isMoveValid(Move move) {

}