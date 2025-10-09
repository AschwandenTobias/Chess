#include <iostream>
#include "pawn.h"

//TODO: Finish this
bool Pawn::isMoveValid(const Move& move, const Position& position, bool white) {
    //Check for en passant
    //Check for promotion
    std::cout << "pawn.cpp: Checking if pawn move is valid \n";
    int from = move.from;
    int to = move.to;
    int distance = to - from;
    //std::cout << "pawn.cpp: Pawn movement distance: " << distance << "\n";
    if(white) {
        //std::cout << "pawn.cpp: White pawn wants to move\n";
        //std::cout << "pawn.cpp: Checking it goal square is occupied\n";
        if(distance == 8 && !position.isOccupied(to)) return true;
        //std::cout << "pawn.cpp: Checking it double pawn move it possible\n";
        if(distance == 16 && from <= 15 && from >= 8 && !position.isOccupied(to) && !position.isOccupied(from + 8)) return true;
        //std::cout << "pawn.cpp: Checking if capture is possible\n";  
        //std::cout << "pawn.cpp: Check if to is occupied by black piece: " << position.isOccupiedByBlackPiece(to) << "\n";  
        if((distance == 7 || distance == 9) && position.isOccupiedByBlackPiece(to)) return true;
    } else {
        if(distance == -8 && !position.isOccupied(to)) return true;
        if(distance == -16 && from <= 56 && from >= 49 && !position.isOccupied(to) && !position.isOccupied(from - 8)) return true;
        if((distance == -7 || distance == -9) && position.isOccupiedByWhitePiece(to)) return true;
    }
    //std::cout << "pawn.cpp: Move wasn't legal, returning false \n";
    return false;
}