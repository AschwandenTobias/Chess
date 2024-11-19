#include "move.h"

// Constructor implementation
Move::Move(int from, int to, 
           Piece moved, 
           Piece captured, 
           Piece promotion, 
           bool castling, 
           bool promoting, 
           bool enPassant)
    : startSquare(from), endSquare(to), movedPiece(moved), capturedPiece(captured), 
      promotionPiece(promotion), isCastling(castling), isPromoting(promoting), 
      isEnPassant(enPassant) {}


