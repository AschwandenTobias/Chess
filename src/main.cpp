#include <iostream>
#include "chessboard.h" 
#include "pawn.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;

   board.blackPawns = 0x000000FF00000000; 
    board.whitePawns = 0x0000000021000000;
    board.whiteBishops = 0x0000000042000000;
    board.whiteKnights = 0x0000000084000000;
    board.whiteQueen = 0x0000000008000000,
    board.whiteRooks = 0x0000000010000000;

    board.printBoard();
    
    

    Pawn::moveBlackPawn(board, 32, 25);
    Pawn::moveBlackPawn(board, 33, 24);
    Pawn::moveBlackPawn(board, 34, 27);
    Pawn::moveBlackPawn(board, 35, 26);
    Pawn::moveBlackPawn(board, 36, 29);
    Pawn::moveBlackPawn(board, 37, 28);
    Pawn::moveBlackPawn(board, 38, 31);
    Pawn::moveBlackPawn(board, 39, 30);
    board.printBoard();
    return 0; 
}