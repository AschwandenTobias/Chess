#include <iostream>
#include "chessboard.h" 

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard chessboard;
    chessboard.printBoard();
    chessboard.moveWhitePawn(8, 16);
    chessboard.moveWhitePawn(9, 25);
    chessboard.moveWhitePawn(16, 25);
    //chessboard.checkIfPieceIsOnSquare(0x0000000000000001);
    chessboard.printBoard();
    return 0; 
}