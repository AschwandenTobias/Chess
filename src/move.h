#ifndef MOVE_H
#define MOVE_H
#include "piece.h"

struct Move {
    int startSquare;      
    int endSquare;        
    Piece movedPiece;   
    Piece capturedPiece; 
    Piece promotionPiece;
    bool isCastling;    
    bool isPromoting;    
    bool isEnPassant;    


    Move(int from, int to, 
         Piece moved, 
         Piece captured = Piece::EMPTY, 
         Piece promotion = Piece::EMPTY,
         bool castling = false, 
         bool promoting = false, 
         bool enPassant = false);
};

#endif