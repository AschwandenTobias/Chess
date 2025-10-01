#include "piece.h"

std::ostream& operator<<(std::ostream& os, PieceType piece) {
    switch (piece) {
        case PieceType::None:        return os << "None";
        case PieceType::WhitePawn:   return os << "WhitePawn";
        case PieceType::WhiteKnight: return os << "WhiteKnight";
        case PieceType::WhiteBishop: return os << "WhiteBishop";
        case PieceType::WhiteRook:   return os << "WhiteRook";
        case PieceType::WhiteQueen:  return os << "WhiteQueen";
        case PieceType::WhiteKing:   return os << "WhiteKing";
        case PieceType::BlackPawn:   return os << "BlackPawn";
        case PieceType::BlackKnight: return os << "BlackKnight";
        case PieceType::BlackBishop: return os << "BlackBishop";
        case PieceType::BlackRook:   return os << "BlackRook";
        case PieceType::BlackQueen:  return os << "BlackQueen";
        case PieceType::BlackKing:   return os << "BlackKing";
    }
    return os << "Unknown";
}
