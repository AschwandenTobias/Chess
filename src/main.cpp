#include <iostream>
#include "chessboard.h" 
#include "pawn.h"
#include "knight.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;

    board.whiteKnights = 0x0000000400000000;

    board.printBoard();
    Knight::moveWhiteKnight(board, 34, 40);

    board.printBoard();
    return 0; 
}