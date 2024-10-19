#include <iostream>
#include "chessboard.h" 
#include "pawn.h"
#include "knight.h"
#include "rook.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;

    //board.whiteRooks = 0x0000000001000000;
    board.printBoard();
    Rook::moveWhiteRook(board, 0, 1);
    board.printBoard();
    return 0; 
}