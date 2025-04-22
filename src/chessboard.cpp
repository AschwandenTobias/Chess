#include <iostream>
#include "chessboard.h"


Chessboard::Chessboard() {
   
}

void Chessboard::drawBoard() const {
    const Position& pos = position;
    std::cout << "  a b c d e f g h\n"; 
    for (int row = 7; row >= 0; row--) {
        std::cout << std::to_string(row + 1) << " "; 
        for (int col = 0; col < 8; col++) {
            int currentSquare = 8 * row + col;
            char piece = '.';
            uint64_t mask = 1ULL << currentSquare;
            //std::cout << "Current square: " << currentSquare << "\n";
            //std::cout << pos.whitePawns;
            //std::cout <<mask;
            bool tmp = pos.whitePawns & mask;
            //std::cout << "Current Square: " << currentSquare << ", bool for whitePawns: " << tmp << "\n";
            //std::cout << "Mask: " << mask << ", pos whitePawns: " << pos.whitePawns << "\n";
            if (pos.whitePawns & mask) piece = 'P';
            else if (pos.whiteKnights & mask) piece = 'N';
            else if (pos.whiteRooks & mask) piece = 'R';
            else if (pos.whiteBishops & mask) piece = 'B';
            else if (pos.whiteQueens & mask) piece = 'Q';
            else if (pos.whiteKing & mask) piece = 'K';
            else if (pos.blackPawns & mask) piece = 'p';
            else if (pos.blackKnights & mask) piece = 'n';
            else if (pos.blackBishops & mask) piece = 'b';
            else if (pos.blackRooks & mask) piece = 'r';
            else if (pos.blackQueens & mask) piece = 'q';
            else if (pos.blackKing & mask) piece = 'k';

            std::cout << piece << " "; 
        }
        std::cout << "\n"; 
    }
  
    std::cout << "  a b c d e f g h\n"; 
}