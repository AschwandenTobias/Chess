#include <iostream>
#include "chessboard.h" 
#include "pawn.h"
#include "knight.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;


    board.printBoard();
    Knight::moveWhiteKnight(board, 1, 7);
    Knight::moveWhiteKnight(board, 1, 11);
    Knight::moveWhiteKnight(board, 1, -5);
    Knight::moveWhiteKnight(board, 1, -9);
    Knight::moveWhiteKnight(board, 1, -14);
    Knight::moveWhiteKnight(board, 1, -16);
    Knight::moveWhiteKnight(board, 1, 18);
    board.printBoard();
    return 0; 
}