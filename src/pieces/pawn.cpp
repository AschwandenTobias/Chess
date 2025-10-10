#include <iostream>
#include "pawn.h"

bool Pawn::isMoveValid(const Move& move, const Position& position, bool white) {
    //Check for promotion
    //std::cout << "pawn.cpp: Checking if pawn move is valid \n";
    int from = move.from;
    int to = move.to;
    int distance = to - from;
    int fromFile = from % 8;
    //Check for en passant. Check if the move flag is set and then, is the move it legal.
    if (move.type == MoveType::EN_PASSANT) {
        int dir = white ? 1 : -1;
        int capturedSquare = to - 8 * dir; 
        if (std::abs(distance) == 7 || std::abs(distance) == 9) {
            if (!position.isOccupied(to)) {
                PieceType enemyPawn = white ? PieceType::BlackPawn : PieceType::WhitePawn;
                if (position.isPieceAt(capturedSquare, enemyPawn) &&
                    (capturedSquare % 8 == position.doublePawnMove)) {
                    return true;
                }
            }
        }
        return false;
    }
    //std::cout << "pawn.cpp: Pawn movement distance: " << distance << "\n";
    if(white) {
        //std::cout << "pawn.cpp: White pawn wants to move\n";
        //std::cout << "pawn.cpp: Checking it goal square is occupied\n";
        if(distance == 8 && !position.isOccupied(to)) return true;
        //std::cout << "pawn.cpp: Checking it double pawn move it possible\n";
        if(distance == 16 && from <= 15 && from >= 8 && !position.isOccupied(to) && !position.isOccupied(from + 8)) return true;
        //std::cout << "pawn.cpp: Checking if capture is possible\n";  
        //std::cout << "pawn.cpp: Check if to is occupied by black piece: " << position.isOccupiedByBlackPiece(to) << "\n";  
        if (distance == 7 && fromFile != 0 && position.isOccupiedByBlackPiece(to))
            return true;
        if (distance == 9 && fromFile != 7 && position.isOccupiedByBlackPiece(to))
            return true;
    } else {
        if(distance == -8 && !position.isOccupied(to)) return true;
        if(distance == -16 && from <= 56 && from >= 49 && !position.isOccupied(to) && !position.isOccupied(from - 8)) return true;
        if (distance == -7 && fromFile != 7 && position.isOccupiedByWhitePiece(to))
            return true;
        if (distance == -9 && fromFile != 0 && position.isOccupiedByWhitePiece(to))
            return true;    
    }
    //std::cout << "pawn.cpp: Move wasn't legal, returning false \n";
    return false;
}