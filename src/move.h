#ifndef MOVE_H
#define MOVE_H

#include "chessboard.h"  // Include chessboard.h to access the Piece enum

struct Move {
    int startSquare;       // Starting square (0-63)
    int endSquare;         // Ending square (0-63)
    Chessboard::Piece piece;           // Piece being moved (e.g., WHITE_PAWN, BLACK_KNIGHT)
    bool isCastling;       // Whether the move is a castling move
    bool isPromoting;      // Whether the move involves a promotion
    bool isEnPassant;      // Whether the move is an en passant

    // Constructor for initializing the Move struct
    Move(int from, int to, Chessboard::Piece piece = Chessboard::EMPTY, bool isCastling = false, bool isPromoting = false, bool isEnPassant = false)
        : startSquare(from), endSquare(to), piece(piece), isCastling(isCastling), isPromoting(isPromoting), isEnPassant(isEnPassant) {}
};

#endif
