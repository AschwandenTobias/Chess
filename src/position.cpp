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
    pinnedPiecesWhite = 0x0000000000000000;
    pinnedPiecesBlack = 0x0000000000000000;
    whiteAttacks = 0x0000000000FF0000;
    blackAttacks = 0x0000FF0000000000;

    attackMaps = 0x0000000000000000;
    checkMask = 0x0000000000000000;

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
    doublePawnMove = -1;
}

//TODO: Check this
bool Position::isSquareAttacked(int square, bool white) {
    uint64_t mask = 1ULL << square;
    return white ? (mask & blackAttacks) != 0 : (mask & whiteAttacks) != 0;
}

bool Position::isOccupied(int square) const {
    return pieceLocation[square] != PieceType::None;
}

bool Position::isOccupiedByWhitePiece(int square) const {
    uint64_t mask = 1ULL << square;
    return (whiteOccupied & mask) != 0;
}

bool Position::isOccupiedByBlackPiece(int square) const {
    uint64_t mask = 1ULL << square;
    return (blackOccupied & mask) != 0;
}

//Made more efficient (i think) with the array lookup
PieceType Position::getPieceAt(int square) {
    return pieceLocation[square];
}

//Made more efficient (i think) with the array lookup
bool Position::isPieceAt(int square, PieceType piece) const {
    return pieceLocation[square] == piece;
}

//This deletes a piece from the bitboards, also deletes it from the pieceLocationArray.
//TODO: Possible bug, not sure if this will need to also update the other bitboards or if i really call movePieceTo everywhere i delete a piece
void Position::deletePieceAt(PieceType piece, int square) {
    uint64_t squareToDelete = 1ULL << square;
    switch(piece) {
        case(PieceType::WhitePawn): whitePawns &= ~squareToDelete; break;
        case(PieceType::BlackPawn): blackPawns &= ~squareToDelete; break;
        case(PieceType::WhiteKnight): whiteKnights &= ~squareToDelete; break;
        case(PieceType::BlackKnight): blackKnights &= ~squareToDelete; break;
        case(PieceType::WhiteBishop): whiteBishops &= ~squareToDelete; break;
        case(PieceType::BlackBishop): blackBishops &= ~squareToDelete; break;
        case(PieceType::WhiteRook): whiteRooks &= ~squareToDelete; break;
        case(PieceType::BlackRook): blackRooks &= ~squareToDelete; break;
        case(PieceType::WhiteQueen): whiteQueens &= ~squareToDelete; break;
        case(PieceType::BlackQueen): blackQueens &= ~squareToDelete; break;
        case(PieceType::WhiteKing): whiteKing &= ~squareToDelete; break;
        case(PieceType::BlackKing): blackKing &= ~squareToDelete; break;
        default: break;
    }
    pieceLocation[square] = PieceType::None;
}

//This function moves a piece to a new location. This also updates the other bitboards.
void Position::movePieceTo(PieceType piece, int square) {
    uint64_t squareToMoveTo = 1ULL << square;
    switch(piece) {
        case(PieceType::WhitePawn): whitePawns |= squareToMoveTo; break;
        case(PieceType::BlackPawn): blackPawns |= squareToMoveTo; break;
        case(PieceType::WhiteKnight): whiteKnights |= squareToMoveTo; break;
        case(PieceType::BlackKnight): blackKnights |= squareToMoveTo; break;
        case(PieceType::WhiteBishop): whiteBishops |= squareToMoveTo; break;
        case(PieceType::BlackBishop): blackBishops |= squareToMoveTo; break;
        case(PieceType::WhiteRook): whiteRooks |= squareToMoveTo; break;
        case(PieceType::BlackRook): blackRooks |= squareToMoveTo; break;
        case(PieceType::WhiteQueen): whiteQueens |= squareToMoveTo; break;
        case(PieceType::BlackQueen): blackQueens |= squareToMoveTo; break;
        case(PieceType::WhiteKing): whiteKing |= squareToMoveTo; break;
        case(PieceType::BlackKing): blackKing |= squareToMoveTo; break;
    }
    pieceLocation[square] = piece;
    //TODO: This could be made more efficient with only computing this when needing it.
    whiteOccupied = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens | whiteKing;
    blackOccupied = blackPawns | blackKnights | blackBishops | blackRooks | blackQueens | blackKing;
    occupiedSquares = whiteOccupied | blackOccupied;
    emptySquares = ~occupiedSquares;
}

//Do i even need these functions?
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