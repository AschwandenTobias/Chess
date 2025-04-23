#ifndef MOVE_H
#define MOVE_H

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
    char movingPiece;
    char capturedPiece;
    char promotionPiece;
    bool whiteTurn;
    MoveType type;

    Move(int from, int to, char movingPiece, bool whiteTurn, char capturedPiece = '\0', char promotionPiece = '\0', MoveType type = NORMAL)
        : from(from), to(to), movingPiece(movingPiece), capturedPiece(capturedPiece), promotionPiece(promotionPiece), whiteTurn(whiteTurn), type(type) {}
};

#endif