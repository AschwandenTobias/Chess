#include "chessboard.h" 
#include <iostream>
#include "pawn.h"

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

    int lastMoveStartSquare = 0;  
    int lastMoveEndSquare = 0;    
    bool lastMoveWasTwoSquarePawnMove = false;
}

void Chessboard::updateLastMove(int startSquare, int endSquare) {
    lastMoveStartSquare = startSquare;
    lastMoveEndSquare = endSquare;
    lastMoveWasTwoSquarePawnMove = false;
}

void Chessboard::deletePiece(Bitboard square) {
    Bitboard del = ~(1ULL << square);
    whitePawns &= del;
    whiteRooks &= del;
    whiteBishops &= del;
    whiteKnights &= del;
    whiteQueen &= del;
    whiteKing &= del;
    blackPawns &= del;
    blackRooks &= del;
    blackBishops &= del;
    blackKing &= del;
    blackQueen &= del;
    blackKing &= del;
}

bool Chessboard::checkIfBlackPawnIsOnSquare(Bitboard square) {
    if(blackPawns & square) return true;
    else {
        return false;
    }
}

bool Chessboard::checkIfWhitePawnIsOnSquare(Bitboard square) {
    if(whitePawns & square) return true;
    else {
        return false;
    }
}

bool Chessboard::checkIfWhitePieceIsOnSquare(Bitboard square) {
    if(whitePawns & square) return true;
    else if(whiteRooks & square) return true;
    else if(whiteKnights & square) return true;
    else if(whiteBishops & square) return true;
    else if(whiteQueen & square) return true;
    else if(whiteKing & square) return true;
    else {
        return false;
    }
}

bool Chessboard::checkIfBlackPieceIsOnSquare(Bitboard square) {
    if(blackPawns & square) return true;
    else if(blackKnights & square) return true;
    else if(blackBishops & square) return true;
    else if(blackRooks & square) return true;
    else if(blackQueen & square) return true;
    else if(blackKing & square) return true;
    else {
        return false;
    }
}

bool Chessboard::checkIfPieceIsOnSquare(Bitboard square) {
    if(whitePawns & square) return true;
    else if(whiteRooks & square) return true;
    else if(whiteKnights & square) return true;
    else if(whiteBishops & square) return true;
    else if(whiteQueen & square) return true;
    else if(whiteKing & square) return true;
    else if(blackPawns & square) return true;
    else if(blackKnights & square) return true;
    else if(blackBishops & square) return true;
    else if(blackRooks & square) return true;
    else if(blackQueen & square) return true;
    else if(blackKing & square) return true;
    else {
        //std::cout << "Detected no piece on the square\n";
        return false;
    }
    //std::cout << "Some issue in checkIfPieceIsOnSquare\n";
    return false;
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
    std::cout << "  a b c d e f g h\n\n";
} 
