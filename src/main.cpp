#include <iostream>
#include "chessboard.h" 
#include "pawn.h"

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard chessboard;
    //chessboard.printBoard();
    //Pawn::moveWhitePawn(chessboard, 8, 16);
    /* Test for enemy pawn capture
    Pawn::moveBlackPawn(chessboard, 48, 32);
    Pawn::moveWhitePawn(chessboard, 9, 25);
    Pawn::moveWhitePawn(chessboard, 25, 32);
    */
    Pawn::moveBlackPawn(chessboard, 48, 32);
    Pawn::moveBlackPawn(chessboard, 50, 34);
    Pawn::moveWhitePawn(chessboard, 9, 25);
    Pawn::moveWhitePawn(chessboard, 25, 33);

    //chessboard.deletePiece(0); // deletes Piece at arg


    //Pawn::moveWhitePawn(chessboard, 33, 48); //enPassant right pawn
    //Pawn::moveWhitePawn(chessboard, 33, 50); //enPassant left pawn


    //chessboard.checkIfPieceIsOnSquare(0x0000000000000001);
    chessboard.printBoard();
    return 0; 
}