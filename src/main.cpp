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
    Knight::moveWhiteKnight(board, 6, 21);
    Knight::moveBlackKnight(board, 62, 77);
    Knight::moveBlackKnight(board, 62, 68);
    Knight::moveBlackKnight(board, 62, 52);
    Knight::moveBlackKnight(board, 62, 56);
    Knight::moveBlackKnight(board, 62, 72);
    Knight::moveBlackKnight(board, 62, 79);
    Knight::moveBlackKnight(board, 62, 45);
    Knight::moveBlackKnight(board, 57, 42);
    board.printBoard();
    return 0; 
}