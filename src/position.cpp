#include "position.h"

Position::Position() {
   //The basic pieces
   uint64_t whitePawns = 0x0000000000000000;
   uint64_t whiteKnights = 0x0000000000000000;
   uint64_t whiteBishops = 0x0000000000000000;
   uint64_t whiteRooks = 0x0000000000000000;
   uint64_t whiteQueens = 0x0000000000000000;
   uint64_t whiteKing = 0x0000000000000000;
   uint64_t blackPawns = 0x0000000000000000;
   uint64_t blackKnights = 0x0000000000000000;
   uint64_t blackBishops = 0x0000000000000000;
   uint64_t blackRooks = 0x0000000000000000;
   uint64_t blackQueens = 0x0000000000000000;
   uint64_t blackKing = 0x0000000000000000;

   //More advanced Bitboards
   uint64_t occupiedSquares = 0x0000000000000000;
   uint64_t emptySquares = 0x0000000000000000;
   uint64_t whiteOccupied = 0x0000000000000000;
   uint64_t blackOccupied = 0x0000000000000000;
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