#include <iostream>
#include "chessboard.h" 
#include "pawn.h"
#include "knight.h"
#include "rook.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;

    board.whiteRooks = 0x0000000001000000;
    board.printBoard();
    Rook::moveWhiteRook(board, 24, 48);
    Rook::moveWhiteRook(board, 48, 56);
    Rook::moveWhiteRook(board, 56, 16);
    board.printBoard();
    return 0; 
}