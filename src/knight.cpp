#include "knight.h"
#include <iostream>

void Knight::moveWhiteKnight(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = (1ULL << startSquare);
    Bitboard to = (1ULL << endSquare);
    if(isWhiteKnightMoveLegal(board, startSquare, endSquare)) {
        if(board.checkIfBlackPieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
        from = ~from;
        board.whiteKnights &= from;
        board.whiteKnights |= to;
    }
}

bool Knight::isWhiteKnightMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    if(endSquare < 0 || endSquare > 63) {
        return false;
    }
    
    // Knight's possible moves: (row_offset, col_offset)
    static const int knightMoves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    
    for (const auto& move : knightMoves) {
        int newRow = startSquare / 8 + move[0];
        int newCol = startSquare % 8 + move[1];
        int newSquare = newRow * 8 + newCol;
        
        if (newSquare == endSquare) {
            // Check if the destination square is not occupied by a white piece
            Bitboard to = (1ULL << endSquare);
            return !board.checkIfWhitePieceIsOnSquare(to);
        }
    }
    return false; // If none of the moves match the endSquare
}

void Knight::moveBlackKnight(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = (1ULL << startSquare);
    Bitboard to = (1ULL << endSquare);
    
    if(isBlackKnightMoveLegal(board, startSquare, endSquare)) {
        // If there is a white piece on the destination square, delete it
        if(board.checkIfWhitePieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
        // Remove the knight from the starting square
        from = ~from; // Flip the bit
        board.blackKnights &= from; // Remove the knight from the board
        board.blackKnights |= to; // Add the knight to the new position
    }
}
bool Knight::isBlackKnightMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    if(endSquare < 0 || endSquare > 63) {
        return false; // Invalid square
    }

    // Knight's possible moves: (row_offset, col_offset)
    static const int knightMoves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    // Get the current position of the knight
    int startRow = startSquare / 8;
    int startCol = startSquare % 8;

    // Check all possible knight moves
    for (const auto& move : knightMoves) {
        int newRow = startRow + move[0];
        int newCol = startCol + move[1];
        
        // Calculate the new square index
        int newSquare = newRow * 8 + newCol;

        // Check if the new square matches the endSquare
        if (newSquare == endSquare) {
            Bitboard to = (1ULL << endSquare);
            // Check if there is no black piece on the destination square
            return !board.checkIfBlackPieceIsOnSquare(to);
        }

        // Check if newRow and newCol are within the board limits (0-7)
        if (newRow < 0 || newRow > 7 || newCol < 0 || newCol > 7) {
            continue; // Skip out-of-bounds moves
        }
    }
    return false; // If none of the moves match the endSquare
}