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
        makeTurn();
    }
}

void Game::makeTurn() {
    board.drawBoard();
    std::cout << "Type in your move in square Notation: e2e4, SquareToMoveFrom and SquareToMoveTo\n";
    std::cout << "If you wanna castle use CWQS (Castling White Queen Side), CBKS (Castling Black King Side) etc.\n";
    if(whiteTurn) std::cout << "Its whites turn and the move number is: " << moveNumber << "\n";
    else std::cout << "Its blacks turn and the move number is: " << moveNumber << "\n";
    std::string move;
    std::cin >> move;
    if(move.length() != 4) {
        std::cout << "Move lenght is wrong :(\n\n";
        return;
    }
    Move currentMove = parseMove(move);
    //TODO: Finish prints
    std::cout << "StartSquare of the current move: " << currentMove.from << "\n";
    std::cout << "EndSquare of the current move: " <<currentMove.to << "\n";
    std::cout << "Piece that moves: " <<currentMove.movingPiece << "\n";
    std::cout << "What Piece gets captured: " <<currentMove.capturedPiece << "\n";
    std::cout << "What piece I wanna promote to: " <<currentMove.promotionPiece << "\n";
    std::cout << "Whos turn is is: " << currentMove.whiteTurn << "\n";
    std::cout << "Movetype:" <<currentMove.type << "\n";
    moveNumber++;
    whiteTurn = !whiteTurn;
    std::cout << "\n";    
}
//TODO: Finish this
Move Game::parseMove(std::string move) {
    int startFile = move[0] - 'a';
    int startRank = move[1] - '1';
    int endFile = move[2] - 'a';
    int endRank = move[3] - '1';
    int startSquare = 8 * startRank + startFile;
    int endSquare = 8 * endRank + endFile;
    // This just sets it to some pawnMove for now
    Move currentMove(startSquare, endSquare, 0, 0 , 'p', 0);
    return currentMove;
}

//TODO: Finish this
bool Game::isMoveValid(Move move) {
    return 0;
}