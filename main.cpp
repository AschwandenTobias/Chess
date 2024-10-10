#include <iostream>
#include "chessboard.h" 

int main() {
    std::cout << "Excited to code a chess game!\n";
    Chessboard chessboard;
    chessboard.printBoard();
    chessboard.moveWhitePawn(8, 16);
    chessboard.printBoard();
    return 0; 
}