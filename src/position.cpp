#include "position.h"

Position::Position() {
   //The basic pieces
   uint64_t whitePawns = 0x000000000000FF00ULL;
   uint64_t whiteKnights = 0x0000000000000042ULL;
   uint64_t whiteBishops = 0x0000000000000024ULL;
   uint64_t whiteRooks = 0x0000000000000081ULL;
   uint64_t whiteQueens = 0x0000000000000008ULL;
   uint64_t whiteKing = 0x0000000000000010ULL;
   uint64_t blackPawns = 0x00FF000000000000ULL;
   uint64_t blackKnights = 0x4200000000000000ULL;
   uint64_t blackBishops = 0x2400000000000000ULL;
   uint64_t blackRooks = 0x8100000000000000ULL;
   uint64_t blackQueens = 0x0800000000000000ULL;
   uint64_t blackKing = 0x1000000000000000ULL;

   //More advanced Bitboards. TODO: Finish setting them up
   uint64_t whiteOccupied = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens  | whiteKing;
   uint64_t blackOccupied = blackPawns | blackKnights | blackBishops | blackRooks | blackQueens  | blackKing;
   uint64_t occupiedSquares = whiteOccupied | blackOccupied;
   uint64_t emptySquares = 0x0000000000000000;
   uint64_t pinnedPieces = 0x0000000000000000;
   uint64_t attackMaps = 0x0000000000000000;
   uint64_t checkMask = 0x0000000000000000;
   uint64_t rayAttacks = 0x0000000000000000;
   uint64_t betweenSquares = 0x0000000000000000;

   //Maybe for more engine efficiency
   uint64_t passedPawns = 0x0000000000000000;
   uint64_t isolatedPawns = 0x0000000000000000;

    bool whiteTurn = true;
}