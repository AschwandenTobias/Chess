#include "game.h"
#include "chessboard.h"
#include <iostream>


Game::Game() {

    IsCheckmate = false;
    whiteTurn = true;
    isDraw = false;
    board;
}


void Game::start() {
    while(!IsCheckmate && !isDraw) {
        board.printBoard();
        std::string move;
        if(whiteTurn) {
            std::cout << "Its whites turn: Enter your move in the following format: \"e2e4\" \n";
        } else {
            std::cout << "Its blacks turn: Enter your move: \n";
        }
        std::cin >> move;
    }
}

void Game::translateMove() {

}

bool Game::isMoveValid(int startSquare, int endSquare) {
    return true;
}

void Game::makeMove(int startSquare, int endSquare) {

}

void Game::checkGameOver() {

}