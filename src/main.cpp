#include <iostream>
#include "chessboard.h" 
#include "pawn.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;

    board.printBoard();
    Pawn::moveWhitePawn(board, 8, 24);
    Pawn::moveWhitePawn(board, 24, 32);
    Pawn::moveWhitePawn(board, 15, 31);
    Pawn::moveBlackPawn(board, 49, 33);
    Pawn::moveBlackPawn(board, 54, 38);
    Pawn::moveBlackPawn(board, 38, 30);

    Pawn::moveWhitePawn(board, 32, 41);
    Pawn::moveBlackPawn(board, 30, 21);
    board.printBoard();
    return 0; 
}