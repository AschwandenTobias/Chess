#include <iostream>
#include "chessboard.h" 
#include "pieces/pawn.h"
#include "pieces/knight.h"
#include "pieces/rook.h"
#include "pieces/bishop.h"
#include "pieces/queen.h"
#include "pieces/king.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard board;

    board.printBoard();
    Pawn::moveWhitePawn(board, 11, 19);
    King::moveWhiteKing(board, 3, 11);
    King::moveWhiteKing(board, 11, 19);
    King::moveWhiteKing(board, 11, 18);
    King::moveWhiteKing(board, 18, 17);
    board.printBoard();
    return 0; 
}