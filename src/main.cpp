#include <iostream>
#include "chessboard.h" 
#include "pawn.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;

    board.whitePawns = 0x0000000000FF0000; 
    board.whiteBishops = 0x0000000042000000;
    board.whiteKnights = 0x0000000084000000;
    board.whiteQueen = 0x0000000008000000,
    board.whiteRooks = 0x0000000010000000;

    board.printBoard();
    
    Pawn::moveWhitePawn(board, 16, 25);
    Pawn::moveWhitePawn(board, 18, 27);
    Pawn::moveWhitePawn(board, 19, 26);
    Pawn::moveWhitePawn(board, 21, 28);
    Pawn::moveWhitePawn(board, 22, 31);
    Pawn::moveWhitePawn(board, 23, 30);
    
    board.printBoard();
    return 0; 
}