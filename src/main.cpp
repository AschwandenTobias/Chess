#include <iostream>
#include "chessboard.h" 
#include "pawn.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;
    board.printBoard();


    board.whitePawns = 0x0000000000FF0000; 
    board.blackPawns = 0x0000000021000000;
    board.blackBishops = 0x0000000042000000;
    board.blackKnights = 0x0000000084000000;
    board.blackQueen = 0x0000000008000000,
    board.blackRooks = 0x0000000010000000;
    Pawn::moveWhitePawn(board, 16, 25);
    Pawn::moveWhitePawn(board, 17, 24);
    Pawn::moveWhitePawn(board, 18, 27);
    Pawn::moveWhitePawn(board, 19, 26);
    Pawn::moveWhitePawn(board, 20, 29);
    Pawn::moveWhitePawn(board, 21, 28);
    Pawn::moveWhitePawn(board, 22, 31);
    Pawn::moveWhitePawn(board, 23, 30);
    
    board.printBoard();
    return 0; 
}