#include <iostream>
#include "chessboard.h" 
#include "pawn.h"
#include "knight.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;

    board.printBoard();

    Queen::moveBlackQueen(board, 60, 68);
    Pawn::moveBlackPawn(board, 51, 43);
    Queen::moveBlackQueen(board, 60, 61);
    Queen::moveBlackQueen(board, 60, 24);
    Queen::moveBlackQueen(board, 24, 48);
    Queen::moveBlackQueen(board, 24, 8);
    Queen::moveBlackQueen(board, 8, 0);
    Queen::moveBlackQueen(board, 0, 9);


    
    board.printBoard();
    return 0; 
}