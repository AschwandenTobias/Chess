#include <iostream>
#include "chessboard.h" 
#include "pawn.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;

   

    board.printBoard();
    
    Pawn::moveBlackPawn(board, 55, 47);

    board.printBoard();
    return 0; 
}