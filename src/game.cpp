#include "game.h"
#include "chessboard.h"
#include <iostream>
#include <string>


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
        if(move.length() != 4) {
            continue;
        }
        int startSquare = translateMove(move.substr(0, 2));
        int endSquare = translateMove(move.substr(2, 3));
        std::cout << "StartSquare: " << startSquare << ", EndSquare: " << endSquare << "\n";

        if (isMoveValid(startSquare, endSquare)) {
            makeMove(startSquare, endSquare);
            whiteTurn = !whiteTurn;
            checkGameOver();
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }
}

int Game::translateMove(std::string move) {
    std::cout << "move[0]: " << move[0] << ", move[1]: " << move[1] << "\n";
    int square = (move[1] - '1') * 8 + (move[0] - 'a' - 1);
    return square;
}

bool Game::isMoveValid(int startSquare, int endSquare) {
    if(endSquare < 0 || endSquare > 63) return false;
    return true;
}

void Game::makeMove(int startSquare, int endSquare) {

}

void Game::checkGameOver() {

}