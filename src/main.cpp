#include <iostream>
#include "chessboard.h" 
#include "pawn.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;



    board.printBoard();
    
    

    Pawn::moveWhitePawn(board, 8, 24);
    Pawn::moveWhitePawn(board, 24, 32);
    Pawn::moveBlackPawn(board, 49, 33);
    Pawn::moveWhitePawn(board, 32, 41);
    board.printBoard();
    return 0; 
}