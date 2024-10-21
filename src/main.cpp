#include <iostream>
#include "chessboard.h" 
#include "pawn.h"
#include "knight.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;

    board.printBoard();
    board.whiteKnights = 0x0000220000000000;
    board.blackKnights = 0x0000000000220000;
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
    Knight::moveBlackKnight(board, 21, 11);
    Knight::moveBlackKnight(board, 11, 21);
    Knight::moveBlackKnight(board, 21, 4);
    Knight::moveBlackKnight(board, 4, 21);
    Knight::moveBlackKnight(board, 21, 6);
    Knight::moveBlackKnight(board, 6, 21);
    Knight::moveBlackKnight(board, 21, 15);
    Knight::moveBlackKnight(board, 15, 21);
    Knight::moveBlackKnight(board, 17, 7);
    Knight::moveBlackKnight(board, 7, 17);
    Knight::moveBlackKnight(board, 17, 0);
    Knight::moveBlackKnight(board, 0, 17);
    Knight::moveBlackKnight(board, 17, 2);
    Knight::moveBlackKnight(board, 2, 17);
    Knight::moveBlackKnight(board, 17, 11);
    Knight::moveBlackKnight(board, 11, 17);

    board.printBoard();
    return 0; 
}