#include <iostream>
#include "chessboard.h" 
#include "pawn.h"
#include "knight.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;

    board.printBoard();
    Pawn::moveWhitePawn(board, 11, 19);
    King::moveWhiteKing(board, 3, 11);
    King::moveWhiteKing(board, 11, 19);

    board.printBoard();
    return 0; 
}