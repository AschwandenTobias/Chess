#ifndef MOVE_H
#define MOVE_H

#include "piece.h"

enum MoveType {
    NORMAL,
    CAPTURE,
    PROMOTION,
    PROMOTION_CAPTURE,
    CASTLE_KINGSIDE,
    CASTLE_QUEENSIDE,
    EN_PASSANT
};

struct Move {
    int from;
    int to;
    PieceType movingPiece;
    PieceType capturedPiece;
    PieceType promotionPiece;
    bool whiteTurn;
    MoveType type;

    Move(int from, int to, PieceType movingPiece, bool whiteTurn,
         PieceType capturedPiece = PieceType::None,
         PieceType promotionPiece = PieceType::None,
         MoveType type = MoveType::NORMAL)
        : from(from),
          to(to),
          movingPiece(movingPiece),
          capturedPiece(capturedPiece),
          promotionPiece(promotionPiece),
          whiteTurn(whiteTurn),
          type(type) {}};
std::ostream& operator<<(std::ostream& os, MoveType type);

#endif