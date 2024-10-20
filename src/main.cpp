#include <iostream>
#include "chessboard.h" 
#include "pawn.h"
#include "knight.h"
#include "rook.h"
#include "bishop.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;

    board.printBoard();
    Bishop::moveBlackBishop(board, 2, 16);
    Pawn::moveBlackPawn(board, 9, 17);
    
    board.printBoard();
    return 0; 
}