#include <iostream>
#include "chessboard.h" 
#include "pawn.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard chessboard;
    chessboard.printBoard();
    Pawn::moveWhitePawn(chessboard, 8, 16);
    //chessboard.checkIfPieceIsOnSquare(0x0000000000000001);
    chessboard.printBoard();
    return 0; 
}