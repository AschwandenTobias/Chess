#include <iostream>
#include "game.h"

Game::Game(int difficultyLevel) {
    isCheckmate = false;
    //std::cout << difficultyLevel;

}

void Game::startGame() {
    std::cout << "Starting game!\n";
    while(!isCheckmate) {
        //std::cout << "Test";
        board.drawBoard();
        std::cout << "Type in your move in square Notation (e2e4)\n";
        std::string move;
        std::cin >> move;
        std::cout << "The move you wanna make is " << move << "\n";
    }
}