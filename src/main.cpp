#include <iostream>
#include "chessboard.h" 
#include "pawn.h"
#include "knight.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;


    board.printBoard();
    Knight::moveWhiteKnight(board, 41, 56);
    Knight::moveWhiteKnight(board, 56, 41);
    Knight::moveWhiteKnight(board, 41, 47);
    Knight::moveWhiteKnight(board, 47, 41);
    Knight::moveWhiteKnight(board, 41, 51);
    Knight::moveWhiteKnight(board, 51, 41);
    Knight::moveWhiteKnight(board, 41, 58);
    Knight::moveWhiteKnight(board, 58, 41);
    Knight::moveWhiteKnight(board, 45, 60);
    Knight::moveWhiteKnight(board, 60, 45);
    Knight::moveWhiteKnight(board, 45, 51);
    Knight::moveWhiteKnight(board, 51, 45);
    Knight::moveWhiteKnight(board, 45, 55);
    Knight::moveWhiteKnight(board, 55, 45);
    Knight::moveWhiteKnight(board, 45, 62);
    Knight::moveWhiteKnight(board, 62, 45);
    board.printBoard();
    return 0; 
}