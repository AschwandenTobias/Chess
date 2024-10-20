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
    Bishop::moveWhiteBishop(board, 2, 16);
    board.printBoard();
    return 0; 
}