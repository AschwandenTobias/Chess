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
    Pawn::moveWhitePawn(board, 9, 17);
    Bishop::moveWhiteBishop(board, 2, 16);
    Bishop::moveWhiteBishop(board, 16, 9);
    Bishop::moveWhiteBishop(board, 9, 54);
    Bishop::moveWhiteBishop(board, 54, 63);
    Bishop::moveWhiteBishop(board, 63, 0);
    Bishop::moveWhiteBishop(board, 63, 54);
    Bishop::moveWhiteBishop(board, 54, 61);
    Pawn::moveWhitePawn(board, 14, 22);
    Bishop::moveWhiteBishop(board, 5, 14);
    Bishop::moveWhiteBishop(board, 14, 49);
    Bishop::moveWhiteBishop(board, 49, 56);
    Bishop::moveWhiteBishop(board, 56, 49);
    Bishop::moveWhiteBishop(board, 49, 58);
    Bishop::moveWhiteBishop(board, 58, 51);
    Bishop::moveWhiteBishop(board, 51, 60);
    Bishop::moveWhiteBishop(board, 60, 53);
    Bishop::moveWhiteBishop(board, 53, 62);
    Bishop::moveWhiteBishop(board, 62, 69);
    Bishop::moveWhiteBishop(board, 62, 61);
    Bishop::moveWhiteBishop(board, 62, 54);
    board.printBoard();
    return 0; 
}