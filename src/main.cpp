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
    Rook::moveBlackRook(board, 63, 62);
    Rook::moveBlackRook(board, 63, 64);
    Pawn::moveBlackPawn(board, 55, 39);
    Rook::moveBlackRook(board, 63, 47);
    Rook::moveBlackRook(board, 47, 46);
    Rook::moveBlackRook(board, 46, 14);
    Rook::moveBlackRook(board, 14, 13);
    Rook::moveBlackRook(board, 13, 12);
    Rook::moveBlackRook(board, 12, 15);
    Rook::moveBlackRook(board, 15, 39);
    Rook::moveBlackRook(board, 15, 7);
    Rook::moveBlackRook(board, 7, 6);
    Rook::moveBlackRook(board, 6, 5);    
    board.printBoard();
    return 0; 
}