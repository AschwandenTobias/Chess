#ifndef POSITION_H
#define POSITION_H
#include <cstdint>

#include "piece.h"

class Position {
public:
    Position();
    //The basic pieces
    uint64_t whitePawns;
    uint64_t whiteKnights;
    uint64_t whiteBishops;
    uint64_t whiteRooks;
    uint64_t whiteQueens;
    uint64_t whiteKing;
    uint64_t blackPawns;
    uint64_t blackKnights;
    uint64_t blackBishops;
    uint64_t blackRooks;
    uint64_t blackQueens;
    uint64_t blackKing;

    //More advanced Bitboards
    uint64_t occupiedSquares;
    uint64_t emptySquares;
    uint64_t whiteOccupied;
    uint64_t blackOccupied;
    uint64_t pinnedPiecesWhite;
    uint64_t pinnedPiecesBlack;
    uint64_t whiteAttacks;
    uint64_t blackAttacks;

    uint64_t attackMaps;
    uint64_t checkMask;

    //Maybe for more engine efficiency
    uint64_t passedPawns;
    uint64_t isolatedPawns;

    //Array to quickly lookup piece positions
    PieceType pieceLocation[64];

    bool whiteTurn;
    //TODO: How can i make this the most efficient?
    int doublePawnMove;

    bool isOccupied(int square) const;
    bool isPieceAt(int square, PieceType piece) const;
    PieceType getPieceAt(int square);
    bool isOccupiedByWhitePiece(int square) const;
    bool isOccupiedByBlackPiece(int square) const;

    void movePieceTo(PieceType piece, int square);
    void deletePieceAt(PieceType piece, int square);

    bool isSquareAttacked(int square, bool white);


    void deleteWhitePawnAt(int square);
    void deleteWhiteBishopAt(int square);
    void deleteWhiteKnightAt(int square);
    void deleteWhiteRookAt(int square);
    void deleteWhiteQueenAt(int square);
    void deleteWhiteKingAt(int square);
    void deleteBlackPawnAt(int square);
    void deleteBlackBishopAt(int square);
    void deleteBlackKnightAt(int square);
    void deleteBlackRookAt(int square);
    void deleteBlackQueenAt(int square);
    void deleteBlackKingAt(int square);
};

#endif