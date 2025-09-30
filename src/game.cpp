#include <iostream>
#include "game.h"

Game::Game(int difficultyLevel) {
    isCheckmate = false;
    isDraw = false;
    whiteTurn = true;
    moveNumber = 1;
    //board;
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
    if(isMoveValid(currentMove)) {
        makeMove(currentMove);
        moveNumber++;
        whiteTurn = !whiteTurn;
    } else {
        std::cout << "This move it not legal, try again" << "\n";
        return;
    }
    //TODO: Finish prints
    std::cout << "StartSquare of the current move: " << currentMove.from << "\n";
    std::cout << "EndSquare of the current move: " <<currentMove.to << "\n";
    //std::cout << "Piece that moves: " << currentMove.movingPiece << "\n";
    //std::cout << "What Piece gets captured: " <<currentMove.capturedPiece << "\n";
    //std::cout << "What piece I wanna promote to: " <<currentMove.promotionPiece << "\n";
    std::cout << "Whos turn is is: " << currentMove.whiteTurn << "\n";
    std::cout << "Movetype:" <<currentMove.type << "\n";
    
    std::cout << "\n";    
}
//TODO: Finish this. Set all the flags of the move
Move Game::parseMove(std::string move) {
    int startFile = move[0] - 'a';
    int startRank = move[1] - '1';
    int endFile = move[2] - 'a';
    int endRank = move[3] - '1';
    int startSquare = 8 * startRank + startFile;
    int endSquare = 8 * endRank + endFile;
    //This just sets it to random Move for now
    Move currentMove(startSquare, endSquare,
                    PieceType::None,  
                    whiteTurn,         
                    PieceType::None,   
                    PieceType::None,  
                    MoveType::NORMAL);
}

//This already checks if the move is outside of the board boundaries or if there is a piece i wanna move on the startSquare
bool Game::isMoveValid(Move move) {
    int from = move.from;
    int to = move.to;
    if(to < 0 || to > 63) return false;
    //TODO: Implement here that the move is correct
    //if (!Position::isPieceAt(from, move.movingPiece)) return false;
    //switch(move.movingPiece) {
      //  case(PieceType::WhitePawn):
//
  //  }
}

//TODOL: Implement this, dont forget to update all important bitboards
void Game::makeMove(Move move) {

}