#include <iostream>
#include "chessboard.h" 
#include "pawn.h"
#include "knight.h"
#include "rook.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;


    board.printBoard();
    Rook::moveWhiteRook(board, 0, 16);
    board.printBoard();
    return 0; 
}