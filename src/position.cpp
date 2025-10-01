#include <iostream>
#include "position.h"

Position::Position() {
    //The pieces themselves
    whitePawns = 0x000000000000FF00ULL;
    whiteKnights = 0x0000000000000042ULL;
    whiteBishops = 0x0000000000000024ULL;
    whiteRooks = 0x0000000000000081ULL;
    whiteQueens = 0x0000000000000008ULL;
    whiteKing = 0x0000000000000010ULL;
    blackPawns = 0x00FF000000000000ULL;
    blackKnights = 0x4200000000000000ULL;
    blackBishops = 0x2400000000000000ULL;
    blackRooks = 0x8100000000000000ULL;
    blackQueens = 0x0800000000000000ULL;
    blackKing = 0x1000000000000000ULL;

    //Additional Bitboards. TODO: Finish setting them up
    whiteOccupied = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens  | whiteKing;
    blackOccupied = blackPawns | blackKnights | blackBishops | blackRooks | blackQueens  | blackKing;
    occupiedSquares = whiteOccupied | blackOccupied;
    emptySquares = 0x0000000000000000;
    pinnedPieces = 0x0000000000000000;
    attackMaps = 0x0000000000000000;
    checkMask = 0x0000000000000000;
    rayAttacks = 0x0000000000000000;
    betweenSquares = 0x0000000000000000;

    //Maybe for more engine efficiency, just some thoughts
    passedPawns = 0x0000000000000000;
    isolatedPawns = 0x0000000000000000;

    for (int sq = 0; sq < 64; sq++) {
        uint64_t mask = 1ULL << sq;

        if (whitePawns & mask) pieceLocation[sq] = PieceType::WhitePawn;
        else if (whiteKnights & mask) pieceLocation[sq] = PieceType::WhiteKnight;
        else if (whiteBishops & mask) pieceLocation[sq] = PieceType::WhiteBishop;
        else if (whiteRooks & mask) pieceLocation[sq] = PieceType::WhiteRook;
        else if (whiteQueens & mask) pieceLocation[sq] = PieceType::WhiteQueen;
        else if (whiteKing & mask) pieceLocation[sq] = PieceType::WhiteKing;
        else if (blackPawns & mask) pieceLocation[sq] = PieceType::BlackPawn;
        else if (blackKnights & mask) pieceLocation[sq] = PieceType::BlackKnight;
        else if (blackBishops & mask) pieceLocation[sq] = PieceType::BlackBishop;
        else if (blackRooks & mask) pieceLocation[sq] = PieceType::BlackRook;
        else if (blackQueens & mask) pieceLocation[sq] = PieceType::BlackQueen;
        else if (blackKing & mask) pieceLocation[sq] = PieceType::BlackKing;
        else pieceLocation[sq] = PieceType::None;
    }

    whiteTurn = true;
}

bool Position::isOccupied(int square) const {
    uint64_t mask = 1ULL << square;
    return (occupiedSquares & mask) != 0;
}

bool Position::isOccupiedByWhitePiece(int square) const {
    uint64_t mask = 1ULL << square;
    return (whiteOccupied & mask) != 0;
}

bool Position::isOccupiedByBlackPiece(int square) const {
    uint64_t mask = 1ULL << square;
    return (blackOccupied & mask) != 0;
}

PieceType Position::getPieceAt(int square) {
    uint64_t mask = 1ULL << square;
    //std::cout << "Moving mask: " << mask << ", square: " << square << ", PieceType: " << static_cast<int>(piece) << "\n";
    if((mask & whitePawns) != 0) return PieceType::WhitePawn;
    if((mask & whiteKnights) != 0) return PieceType::WhiteKnight;
    if((mask & whiteBishops) != 0) return PieceType::WhiteBishop;
    if((mask & whiteRooks) != 0) return PieceType::WhiteRook;
    if((mask & whiteQueens) != 0) return PieceType::WhiteQueen;
    if((mask & whiteKing) != 0) return PieceType::WhiteKing;
    if((mask & blackPawns) != 0) return PieceType::BlackPawn;
    if((mask & blackKnights) != 0) return PieceType::BlackKnight;
    if((mask & blackBishops) != 0) return PieceType::BlackBishop;
    if((mask & blackRooks) != 0) return PieceType::BlackRook;
    if((mask & blackQueens) != 0) return PieceType::BlackQueen;
    if((mask & blackKing) != 0) return PieceType::BlackKing;
    return PieceType::None;
}

bool Position::isPieceAt(int square, PieceType piece) const {
    //std::cout << "Inside Position isPieceAt\n";
    uint64_t mask = 1ULL << square;
    //std::cout << "Moving mask: " << mask << ", square: " << square << ", PieceType: " << static_cast<int>(piece) << "\n";
    switch(piece) {
        case PieceType::WhitePawn:
            //std::cout << "White Pawn detected at square\n";
            return (whitePawns & mask) != 0;
        case PieceType::WhiteKnight:
            return (whiteKnights & mask) != 0;
        case PieceType::WhiteBishop:
            return (whiteBishops & mask) != 0;
        case PieceType::WhiteRook:
            return (whiteRooks & mask) != 0;
        case PieceType::WhiteQueen:
            return (whiteQueens & mask) != 0;
        case PieceType::WhiteKing:
            return (whiteKing & mask) != 0;
        case PieceType::BlackPawn:
            return (blackPawns & mask) != 0;
        case PieceType::BlackKnight:
            return (blackKnights & mask) != 0;
        case PieceType::BlackBishop:
            return (blackBishops & mask) != 0;
        case PieceType::BlackRook:
            return (blackRooks & mask) != 0;
        case PieceType::BlackQueen:
            return (blackQueens & mask) != 0;
        case PieceType::BlackKing:
            return (blackKing & mask) != 0;
    }
    return false;
}

void Position::deletePieceAt(int square) {
    uint64_t squareToDelete = 1ULL << square;
    switch(getPieceAt(square)) {
        case(PieceType::WhitePawn): whitePawns &= ~squareToDelete;
        case(PieceType::BlackPawn): blackPawns &= ~squareToDelete;
        case(PieceType::WhiteKnight): whiteKnights &= ~squareToDelete;
        case(PieceType::BlackKnight): blackKnights &= ~squareToDelete;
        case(PieceType::WhiteBishop): whiteBishops &= ~squareToDelete;
        case(PieceType::BlackBishop): blackBishops &= ~squareToDelete;
        case(PieceType::WhiteRook): whiteRooks &= ~squareToDelete;
        case(PieceType::BlackRook): blackRooks &= ~squareToDelete;
        case(PieceType::WhiteQueen): whiteQueens &= ~squareToDelete;
        case(PieceType::BlackQueen): blackQueens &= ~squareToDelete;
        case(PieceType::WhiteKing): whiteKing &= ~squareToDelete;
        case(PieceType::BlackKing): blackKing &= ~squareToDelete;
    }
}

void Position::deleteWhitePawnAt(int square) {
    uint64_t squareToDelete = 1ULL << square;
    whitePawns &= ~squareToDelete;
}

void Position::deleteWhiteBishopAt(int square) {
    uint64_t squareToDelete = 1ULL << square;
    whiteBishops &= ~squareToDelete;
}

void Position::deleteWhiteKnightAt(int square) {
    uint64_t squareToDelete = 1ULL << square;
    whiteKnights &= ~squareToDelete;
}

void Position::deleteWhiteRookAt(int square) {
    uint64_t squareToDelete = 1ULL << square;
    whiteRooks &= ~squareToDelete;
}

void Position::deleteWhiteQueenAt(int square) {
    uint64_t squareToDelete = 1ULL << square;
    whiteQueens &= ~squareToDelete;
}

void Position::deleteWhiteKingAt(int square) {
    uint64_t squareToDelete = 1ULL << square;
    whiteKing &= ~squareToDelete;
}

void Position::deleteBlackPawnAt(int square) {
    uint64_t squareToDelete = 1ULL << square;
    blackPawns &= ~squareToDelete;
}

void Position::deleteBlackBishopAt(int square) {
    uint64_t squareToDelete = 1ULL << square;
    blackBishops &= ~squareToDelete;
}

void Position::deleteBlackKnightAt(int square) {
    uint64_t squareToDelete = 1ULL << square;
    blackKnights &= ~squareToDelete;
}

void Position::deleteBlackRookAt(int square) {
    uint64_t squareToDelete = 1ULL << square;
    blackRooks &= ~squareToDelete;
}

void Position::deleteBlackQueenAt(int square) {
    uint64_t squareToDelete = 1ULL << square;
    blackQueens &= ~squareToDelete;
}

void Position::deleteBlackKingAt(int square) {
    uint64_t squareToDelete = 1ULL << square;
    blackKing &= ~squareToDelete;
}