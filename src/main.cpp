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

    Knight::moveWhiteKnight(board, 1, 18); 
    Knight::moveWhiteKnight(board, 18, 8);
    Knight::moveWhiteKnight(board, 18, 19);
    Knight::moveWhiteKnight(board, 18, 33);
    Knight::moveWhiteKnight(board, 33, 39);
    
    board.printBoard();
    return 0; 
}