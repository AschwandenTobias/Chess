#ifndef MOVE_H
#define MOVE_H

struct Move {
    int startSquare;
    int endSquare;
    bool isCastling;
    bool isPromoting;
    bool isEnPassant;

    Move(int from, int to, bool isCastling = false, bool isPromoting = false, bool isEnPassant = false)
    : startSquare(from), endSquare(to), isCastling(isCastling), isPromoting(isPromoting), isEnPassant(isEnPassant) {}

};

#endif