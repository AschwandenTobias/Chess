#include <iostream>
#include "chessboard.h" 
#include "pawn.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;

    board.printBoard();

    Pawn::moveBlackPawn(board, 48, 32);
    Pawn::moveBlackPawn(board, 32, 24);
    Pawn::moveWhitePawn(board, 9, 25);
    Pawn::moveBlackPawn(board, 24, 17);


    board.printBoard();
    return 0; 
}