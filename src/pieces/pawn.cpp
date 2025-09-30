#include <iostream>
#include "pawn.h"

//TODO: Finish this
bool Pawn::isMoveValid(const Move& move, const Position& position, bool white) {
    //Check for en passant
    //Check for promotion
    std::cout << "Checking is pawn move is valid \n";
    int from = move.from;
    int to = move.to;
    int distance = to - from;
    if(white) {
        if(distance == 8 && !position.isOccupied(to)) return true;
        if(distance == 16 && from <= 15 && from >= 8 && !position.isOccupied(to) && !position.isOccupied(from + 8)) return true;
        if((distance == 7 || distance == 9) && position.isOccupiedByBlackPiece(to)) return true;
    } else {
        if(distance == -8 && !position.isOccupied(to)) return true;
        if(distance == -16 && from <= 56 && from >= 49 && !position.isOccupied(to) && !position.isOccupied(from - 8)) return true;
        if((distance == -7 || distance == -9) && position.isOccupiedByWhitePiece(to)) return true;
    }
    return false;
}