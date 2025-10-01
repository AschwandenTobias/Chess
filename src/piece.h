#ifndef PIECE_H
#define PIECE_H
#include <iostream>

enum class PieceType {
    None,
    WhitePawn, WhiteKnight, WhiteBishop, WhiteRook, WhiteQueen, WhiteKing,
    BlackPawn, BlackKnight, BlackBishop, BlackRook, BlackQueen, BlackKing
};

std::ostream& operator<<(std::ostream& os, PieceType piece);

#endif