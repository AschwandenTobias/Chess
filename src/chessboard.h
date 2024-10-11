#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <cstdint>

typedef uint64_t Bitboard;

class Chessboard {
public:
    Bitboard whitePawns;
    Bitboard whiteRooks;
    Bitboard whiteKnights;
    Bitboard whiteBishops;
    Bitboard whiteQueen;
    Bitboard whiteKing;
    Bitboard blackPawns;
    Bitboard blackRooks;
    Bitboard blackKnights;
    Bitboard blackBishops;
    Bitboard blackQueen;
    Bitboard blackKing;

    int lastMoveStartSquare;  
    int lastMoveEndSquare;    
    bool lastMoveWasTwoSquarePawnMove;

    Chessboard();
    void printBoard();
    bool checkIfPieceIsOnSquare(Bitboard square);
    bool checkIfWhitePieceIsOnSquare(Bitboard square);
    bool checkIfBlackPieceIsOnSquare(Bitboard square);
    bool checkIfBlackPawnIsOnSquare(Bitboard square);
    bool checkIfWhitePawnIsOnSquare(Bitboard square);
    void deletePiece(Bitboard square);
    void updateLastMove(int startsquare, int endsquare);
};

#endif 