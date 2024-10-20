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

    Queen::moveWhiteQueen(board, 4, 18);
    Pawn::moveWhitePawn(board, 11, 19);
    Queen::moveWhiteQueen(board, 4, 18);
    Queen::moveWhiteQueen(board, 18, 26);
    Queen::moveWhiteQueen(board, 26, 27);
    Queen::moveWhiteQueen(board, 27, 24);
    Queen::moveWhiteQueen(board, 24, 48);
    Queen::moveWhiteQueen(board, 48, 8);
    Pawn::moveWhitePawn(board, 8, 16);
    Queen::moveWhiteQueen(board, 48, 8);

    
    board.printBoard();
    return 0; 
}