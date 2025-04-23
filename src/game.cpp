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
        Move currentMove = parseMove(move);

        moveNumber++;
        whiteTurn = !whiteTurn;
        std::cout << "\n";
    }
}
//TODO: Finish this
Move Game::parseMove(std::string move) {
    int startFile = move[0] - 'a';
    int startRank = move[1] - '1';
    int endFile = move[2] - 'a';
    int endRank = move[3] - '1';
    int startSquare = 8 * startRank + startFile;
    int endSquare = 1;
    Move currentMove(startSquare, endSquare,0 ,  'p', 0);
    return currentMove;
}


bool Game::isMoveValid(Move move) {
    return 0;
}