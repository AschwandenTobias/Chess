#include "chessboard.h" 
#include <iostream>


Chessboard::Chessboard() {
    whitePawns = 0x000000000000FF00;
    whiteRooks = 0x0000000000000081;
    whiteKnights = 0x0000000000000042;
    whiteBishops = 0x0000000000000024;
    whiteQueen = 0x0000000000000010;
    whiteKing = 0x0000000000000008;
    blackPawns = 0x00FF000000000000;
    blackRooks = 0x8100000000000000;
    blackKnights = 0x4200000000000000;
    blackBishops = 0x2400000000000000;
    blackQueen = 0x1000000000000000;
    blackKing = 0x0800000000000000;
}

void Chessboard::printBoard() {
    std::cout << "  a b c d e f g h\n";
    for(int row = 7; row >= 0; row--) {
        std::cout << row + 1 << " "; 
        for(int col = 7; col >= 0; col--) {
            int square = row * 8 + col;
            char piece = '.';
            if (whitePawns & (1ULL << square)) piece = 'P';
            else if (whiteRooks & (1ULL << square)) piece = 'R';
            else if (whiteKnights & (1ULL << square)) piece = 'N';
            else if (whiteBishops & (1ULL << square)) piece = 'B';
            else if (whiteQueen & (1ULL << square)) piece = 'Q';
            else if (whiteKing & (1ULL << square)) piece = 'K';
            else if (blackPawns & (1ULL << square)) piece = 'P';
            else if (blackRooks & (1ULL << square)) piece = 'R';
            else if (blackKnights & (1ULL << square)) piece = 'N';
            else if (blackBishops & (1ULL << square)) piece = 'B';
            else if (blackQueen & (1ULL << square)) piece = 'Q';
            else if (blackKing & (1ULL << square)) piece = 'K';
            else {
                
            }
            std::cout << piece << ' ';
        }
        std::cout << "\n";
    }
    std::cout << "  a b c d e f g h\n";
}