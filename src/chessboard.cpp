#include "chessboard.h" 
#include <iostream>

#include "pieces/Pawn.h"
#include "pieces/Rook.h"
#include "pieces/Bishop.h"
#include "pieces/Knight.h"
#include "pieces/King.h"
#include "pieces/Queen.h"
#include <vector>
#include <utility>



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

    int attackingPieceSquare = -1;
    
    whiteQueenRookMoved = false;
    whiteKingRookMoved = false;
    blackQueenRookMoved = false;
    blackKingRookMoved = false;
    whiteKingMoved = false;
    blackKingMoved = false;
}

int Chessboard::returnNumberOfPieces(Piece piece) {
    switch (piece) {
        case(WHITE_PAWN): return __builtin_popcountll(whitePawns);
        case(WHITE_ROOK): return __builtin_popcountll(whiteRooks);
        case(WHITE_KNIGHT): return __builtin_popcountll(whiteKnights);
        case(WHITE_BISHOP): return __builtin_popcountll(whiteBishops);
        case(WHITE_QUEEN): return __builtin_popcountll(whiteQueen);
        case(BLACK_PAWN): return __builtin_popcountll(blackPawns);
        case(BLACK_ROOK): return __builtin_popcountll(blackRooks);
        case(BLACK_BISHOP): return __builtin_popcountll(blackBishops);
        case(BLACK_KNIGHT): return __builtin_popcountll(blackKnights);
        case(BLACK_QUEEN): return __builtin_popcountll(blackQueen);
    }
    return -1;
}

std::vector<std::pair<int, int>> Chessboard::generateAllPossibleMoves(bool white) {
    std::vector<std::pair<int, int>> allMoves;
    if(white) {
        auto pawnMoves = Pawn::getAllPossiblePawnMoves(*this, white);
        allMoves.insert(allMoves.end(), pawnMoves.begin(), pawnMoves.end());
        auto rookMoves = Rook::getAllPossibleRookMoves(*this, white);
        allMoves.insert(allMoves.end(), rookMoves.begin(), rookMoves.end());
        auto knightMoves = Knight::getAllPossibleKnightMoves(*this, white);
        allMoves.insert(allMoves.end(), knightMoves.begin(), knightMoves.end());
        auto bishopMoves = Bishop::getAllPossibleBishopMoves(*this, white);
        allMoves.insert(allMoves.end(), bishopMoves.begin(), bishopMoves.end());
        auto queenMoves = Queen::getAllPossibleQueenMoves(*this, white);
        allMoves.insert(allMoves.end(), queenMoves.begin(), queenMoves.end());
        auto kingMoves = King::getAllPossibleKingMoves(*this, white);
        allMoves.insert(allMoves.end(), kingMoves.begin(), kingMoves.end());
    } else {
        auto pawnMoves = Pawn::getAllPossiblePawnMoves(*this, false);
        allMoves.insert(allMoves.end(), pawnMoves.begin(), pawnMoves.end());
        auto rookMoves = Rook::getAllPossibleRookMoves(*this, false);
        allMoves.insert(allMoves.end(), rookMoves.begin(), rookMoves.end());
        auto knightMoves = Knight::getAllPossibleKnightMoves(*this, false);
        allMoves.insert(allMoves.end(), knightMoves.begin(), knightMoves.end());
        auto bishopMoves = Bishop::getAllPossibleBishopMoves(*this, false);
        allMoves.insert(allMoves.end(), bishopMoves.begin(), bishopMoves.end());
        auto queenMoves = Queen::getAllPossibleQueenMoves(*this, false);
        allMoves.insert(allMoves.end(), queenMoves.begin(), queenMoves.end());
        auto kingMoves = King::getAllPossibleKingMoves(*this, false);
        allMoves.insert(allMoves.end(), kingMoves.begin(), kingMoves.end());
    }
    return allMoves;
}

Chessboard::Piece Chessboard::getPieceAtSquare(int square) {
    Bitboard squareMask = 1ULL << square;

    if (whitePawns & squareMask) return WHITE_PAWN;
    if (whiteRooks & squareMask) return WHITE_ROOK;
    if (whiteKnights & squareMask) return WHITE_KNIGHT;
    if (whiteBishops & squareMask) return WHITE_BISHOP;
    if (whiteQueen & squareMask) return WHITE_QUEEN;
    if (whiteKing & squareMask) return WHITE_KING;
    if (blackPawns & squareMask) return BLACK_PAWN;
    if (blackRooks & squareMask) return BLACK_ROOK;
    if (blackKnights & squareMask) return BLACK_KNIGHT;
    if (blackBishops & squareMask) return BLACK_BISHOP;
    if (blackQueen & squareMask) return BLACK_QUEEN;
    if (blackKing & squareMask) return BLACK_KING;
    return EMPTY;
}

void Chessboard::setAllPiecesToZero() {
    whitePawns = 0;
    whiteRooks = 0;
    whiteBishops = 0;
    whiteKnights = 0;
    whiteQueen = 0;
    whiteKing = 0;
    blackPawns = 0;
    blackRooks = 0;
    blackBishops = 0;
    blackKnights = 0;
    blackQueen = 0;
    blackKing = 0;
}

int Chessboard::getSquareOfKing(bool white) {
    if(white) {
        return(__builtin_ffsll(whiteKing) - 1);
    } else {
        return(__builtin_ffsll(blackKing) - 1);
    }
}

void Chessboard::updateLastMove(int startSquare, int endSquare) {
    lastMoveStartSquare = startSquare;
    lastMoveEndSquare = endSquare;
    lastMoveWasTwoSquarePawnMove = false;
}

void Chessboard::setPiece(int square, Piece piece) {
    Bitboard mask = (1ULL << square);
    switch (piece) {
        case WHITE_PAWN:
            whitePawns |= mask;
            break;
        case WHITE_ROOK:
            whiteRooks |= mask;
            break;
        case WHITE_KNIGHT:
            whiteKnights |= mask;
            break;
        case WHITE_BISHOP:
            whiteBishops |= mask;
            break;
        case WHITE_QUEEN:
            whiteQueen |= mask;
            break;
        case WHITE_KING:
            whiteKing |= mask;
            break;
        case BLACK_PAWN:
            blackPawns |= mask;
            break;
        case BLACK_ROOK:
            blackRooks |= mask;
            break;
        case BLACK_KNIGHT:
            blackKnights |= mask;
            break;
        case BLACK_BISHOP:
            blackBishops |= mask;
            break;
        case BLACK_QUEEN:
            blackQueen |= mask;
            break;
        case BLACK_KING:
            blackKing |= mask;
            break;
        default:
            break;
    }
}

void Chessboard::deletePiece(Bitboard square) {
    Bitboard del = ~square;
    whitePawns &= del;
    whiteRooks &= del;
    whiteBishops &= del;
    whiteKnights &= del;
    whiteQueen &= del;
    whiteKing &= del;
    blackPawns &= del;
    blackRooks &= del;
    blackBishops &= del;
    blackKnights &= del;
    blackQueen &= del;
    blackKing &= del;
}

void Chessboard::deletePiece(int squareToDelete) {
    Bitboard del = ~(1ULL << squareToDelete);
    whitePawns &= del;
    whiteRooks &= del;
    whiteBishops &= del;
    whiteKnights &= del;
    whiteQueen &= del;
    whiteKing &= del;
    blackPawns &= del;
    blackRooks &= del;
    blackBishops &= del;
    blackKnights &= del;
    blackQueen &= del;
    blackKing &= del;
}

bool Chessboard::checkIfWhiteKingIsOnSquare(Bitboard square) {
    return (whiteKing & square);
}

bool Chessboard::checkIfBlackKingIsOnSquare(Bitboard square) {
    return (blackKing & square);
}

bool Chessboard::checkIfWhiteKnightIsOnSquare(Bitboard square) {
    return (whiteKnights & square);
}

bool Chessboard::checkIfBlackKnightIsOnSquare(Bitboard square) {
    return (blackKnights & square);
}

bool Chessboard::checkIfWhiteQueenIsOnSquare(Bitboard square) {
    return (whiteQueen & square);
}

bool Chessboard::checkIfBlackQueenIsOnSquare(Bitboard square) {
    return (blackQueen & square);
}

bool Chessboard::checkIfWhiteBishopIsOnSquare(Bitboard square) {
    return (whiteBishops & square);
}

bool Chessboard::checkIfBlackBishopIsOnSquare(Bitboard square) {
    return (blackBishops & square);
}

bool Chessboard::checkIfWhiteRookIsOnSquare(Bitboard square) {
    return (whiteRooks & square);
}

bool Chessboard::checkIfBlackRookIsOnSquare(Bitboard square) {
    return (blackRooks & square);
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

bool Chessboard::checkIfWhitePieceIsOnSquare(int squareToDelete) {
    Bitboard square = (1ULL << squareToDelete);
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

bool Chessboard::checkIfBlackPieceIsOnSquare(int squareToDelete) {
    Bitboard square = (1ULL << squareToDelete);
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

bool Chessboard::checkIfPieceIsOnSquare(int Square) {
    Bitboard square = 1Ull << Square;
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
            else if (whiteKnights & (1ULL << square)) piece = 'N';
            else if (whiteRooks & (1ULL << square)) piece = 'R';
            else if (whiteBishops & (1ULL << square)) piece = 'B';
            else if (whiteQueen & (1ULL << square)) piece = 'Q';
            else if (whiteKing & (1ULL << square)) piece = 'K';
            else if (blackPawns & (1ULL << square)) piece = 'p';
            else if (blackRooks & (1ULL << square)) piece = 'r';
            else if (blackKnights & (1ULL << square)) piece = 'n';
            else if (blackBishops & (1ULL << square)) piece = 'b';
            else if (blackQueen & (1ULL << square)) piece = 'q';
            else if (blackKing & (1ULL << square)) piece = 'k';
            else {
                
            }
            std::cout << piece << ' ';
        }
        std::cout << "\n";
    }
    std::cout << "  a b c d e f g h\n\n";
} 

