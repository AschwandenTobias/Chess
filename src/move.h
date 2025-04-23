#ifndef MOVE_H
#define MOVE_H

struct Move {
    int from;
    int to;
    bool isPromotion;
    char promotionPiece;
    bool isCastling;

    Move(int from, int to, bool isPromotion = false, char promotionPiece = '\0', bool isCastling = false)
        : from(from), to(to), promotionPiece(promotionPiece), isPromotion(isPromotion), isCastling(isCastling) {}
};

#endif