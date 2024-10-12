#include <iostream>
#include "chessboard.h" 
#include "pawn.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;
    
    board.whitePawns = 0x0000000000FF0000; //Move pawns to third row
    board.blackPawns = 0x00000000FF000000; //blackPawns on fourth row
    board.printBoard();

    Pawn::moveWhitePawn(board, 16, 25);
    
    board.printBoard();
    return 0; 
}