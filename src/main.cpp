#include <iostream>
#include "chessboard.h" 
#include "pawn.h"
#include "knight.h"
#include "rook.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;

    board.whiteRooks = 0x0000000008000000;
    board.printBoard();
    Rook::moveWhiteRook(board, 27, 62);

    board.printBoard();
    return 0; 
}