#include "chessboard.h" 
#include <iostream>

#include "pieces/Pawn.h"
#include "pieces/Rook.h"
#include "pieces/Bishop.h"
#include "pieces/Knight.h"
#include "pieces/King.h"
#include "pieces/Queen.h"
#include <vector>
#include <utility>



Chessboard::Chessboard() {
    whitePawns = 0x000000000000FF00;
    whiteRooks = 0x0000000000000081;
    whiteKnights = 0x0000000000000042;
    whiteBishops = 0x0000000000000024;
    whiteQueen = 0x0000000000000010;
    whiteKing = 0x0000000000000008;
    blackPawns = 0x00FF000000000000;
    blackRooks = 0x8100000000000000;
    blackKnights = 0x4200000000000000;
    blackBishops = 0x2400000000000000;
    blackQueen = 0x1000000000000000;
    blackKing = 0x0800000000000000;

    whitePieces = 0xFFFF;
    blackPieces = 0xFFFF000000000000;
    occupiedSquares = whitePieces | blackPieces;
    blackAttackingSquares; //TODO: define this
    whiteAttackingSquares; //TODO: define this

    int lastMoveStartSquare = 0;  
    int lastMoveEndSquare = 0;    
    bool lastMoveWasTwoSquarePawnMove = false;

    int attackingPieceSquare = -1;
    
    whiteQueenRookMoved = false;
    whiteKingRookMoved = false;
    blackQueenRookMoved = false;
    blackKingRookMoved = false;
    whiteKingMoved = false;
    blackKingMoved = false;
}
//Function that just makes a move. Doesnt check for move legality
//TODO: finish this and make it efficient
void Chessboard::makeMove(Move move) {
    bool white = move.movedPiece == Piece::WHITE_PAWN || move.movedPiece == Piece::WHITE_ROOK || move.movedPiece == Piece::WHITE_BISHOP || move.movedPiece == Piece::WHITE_KNIGHT || move.movedPiece == Piece::WHITE_QUEEN || move.movedPiece == Piece::WHITE_KING;
    Bitboard startMask  = (1ULL << move.startSquare);
    Bitboard endMask = (1ULL << move.endSquare);
    deletePiece(move.startSquare);
    setPiece(move.endSquare, move.movedPiece);
    if(white) {
        whitePieces &= ~startMask;
        whitePieces |= endMask;
    } else {
        blackPieces &= ~startMask;
        blackPieces |= endMask;
    }
    occupiedSquares = whitePieces | blackPieces;
}

std::vector<std::pair<int, int>> Chessboard::generateAllPossibleMoves(bool white) {
    std::vector<std::pair<int, int>> allMoves;
    if(white) {
        auto pawnMoves = Pawn::getAllPossiblePawnMoves(*this, white);
        allMoves.insert(allMoves.end(), pawnMoves.begin(), pawnMoves.end());
        auto rookMoves = Rook::getAllPossibleRookMoves(*this, white);
        allMoves.insert(allMoves.end(), rookMoves.begin(), rookMoves.end());
        auto knightMoves = Knight::getAllPossibleKnightMoves(*this, white);
        allMoves.insert(allMoves.end(), knightMoves.begin(), knightMoves.end());
        auto bishopMoves = Bishop::getAllPossibleBishopMoves(*this, white);
        allMoves.insert(allMoves.end(), bishopMoves.begin(), bishopMoves.end());
        auto queenMoves = Queen::getAllPossibleQueenMoves(*this, white);
        allMoves.insert(allMoves.end(), queenMoves.begin(), queenMoves.end());
        auto kingMoves = King::getAllPossibleKingMoves(*this, white);
        allMoves.insert(allMoves.end(), kingMoves.begin(), kingMoves.end());
    } else {
        auto pawnMoves = Pawn::getAllPossiblePawnMoves(*this, false);
        allMoves.insert(allMoves.end(), pawnMoves.begin(), pawnMoves.end());
        auto rookMoves = Rook::getAllPossibleRookMoves(*this, false);
        allMoves.insert(allMoves.end(), rookMoves.begin(), rookMoves.end());
        auto knightMoves = Knight::getAllPossibleKnightMoves(*this, false);
        allMoves.insert(allMoves.end(), knightMoves.begin(), knightMoves.end());
        auto bishopMoves = Bishop::getAllPossibleBishopMoves(*this, false);
        allMoves.insert(allMoves.end(), bishopMoves.begin(), bishopMoves.end());
        auto queenMoves = Queen::getAllPossibleQueenMoves(*this, false);
        allMoves.insert(allMoves.end(), queenMoves.begin(), queenMoves.end());
        auto kingMoves = King::getAllPossibleKingMoves(*this, false);
        allMoves.insert(allMoves.end(), kingMoves.begin(), kingMoves.end());
    }
    return allMoves;
}

Piece Chessboard::getPieceAtSquare(int square) {
    Bitboard squareMask = 1ULL << square;

    if (whitePawns & squareMask) return Piece::WHITE_PAWN;
    if (whiteRooks & squareMask) return Piece::WHITE_ROOK;
    if (whiteKnights & squareMask) return Piece::WHITE_KNIGHT;
    if (whiteBishops & squareMask) return Piece::WHITE_BISHOP;
    if (whiteQueen & squareMask) return Piece::WHITE_QUEEN;
    if (whiteKing & squareMask) return Piece::WHITE_KING;
    if (blackPawns & squareMask) return Piece::BLACK_PAWN;
    if (blackRooks & squareMask) return Piece::BLACK_ROOK;
    if (blackKnights & squareMask) return Piece::BLACK_KNIGHT;
    if (blackBishops & squareMask) return Piece::BLACK_BISHOP;
    if (blackQueen & squareMask) return Piece::BLACK_QUEEN;
    if (blackKing & squareMask) return Piece::BLACK_KING;
    return Piece::EMPTY;
}

void Chessboard::setAllPiecesToZero() {
    whitePawns = 0;
    whiteRooks = 0;
    whiteBishops = 0;
    whiteKnights = 0;
    whiteQueen = 0;
    whiteKing = 0;
    blackPawns = 0;
    blackRooks = 0;
    blackBishops = 0;
    blackKnights = 0;
    blackQueen = 0;
    blackKing = 0;
}

int Chessboard::getSquareOfKing(bool white) {
    if(white) {
        return(__builtin_ffsll(whiteKing) - 1);
    } else {
        return(__builtin_ffsll(blackKing) - 1);
    }
}

void Chessboard::updateLastMove(int startSquare, int endSquare) {
    lastMoveStartSquare = startSquare;
    lastMoveEndSquare = endSquare;
    lastMoveWasTwoSquarePawnMove = false;
}

void Chessboard::setPiece(int square, Piece piece) {
    Bitboard mask = (1ULL << square);
    switch (piece) {
        case Piece::WHITE_PAWN:
            whitePawns |= mask;
            break;
        case Piece::WHITE_ROOK:
            whiteRooks |= mask;
            break;
        case Piece::WHITE_KNIGHT:
            whiteKnights |= mask;
            break;
        case Piece::WHITE_BISHOP:
            whiteBishops |= mask;
            break;
        case Piece::WHITE_QUEEN:
            whiteQueen |= mask;
            break;
        case Piece::WHITE_KING:
            whiteKing |= mask;
            break;
        case Piece::BLACK_PAWN:
            blackPawns |= mask;
            break;
        case Piece::BLACK_ROOK:
            blackRooks |= mask;
            break;
        case Piece::BLACK_KNIGHT:
            blackKnights |= mask;
            break;
        case Piece::BLACK_BISHOP:
            blackBishops |= mask;
            break;
        case Piece::BLACK_QUEEN:
            blackQueen |= mask;
            break;
        case Piece::BLACK_KING:
            blackKing |= mask;
            break;
        default:
            break;
    }
}

void Chessboard::deletePiece(Bitboard square) {
    Bitboard del = ~square;
    whitePawns &= del;
    whiteRooks &= del;
    whiteBishops &= del;
    whiteKnights &= del;
    whiteQueen &= del;
    whiteKing &= del;
    blackPawns &= del;
    blackRooks &= del;
    blackBishops &= del;
    blackKnights &= del;
    blackQueen &= del;
    blackKing &= del;
}

void Chessboard::deleteWhitePiece(Bitboard square) {
    Bitboard del = ~square;
    whitePawns &= del;
    whiteRooks &= del;
    whiteBishops &= del;
    whiteKnights &= del;
    whiteQueen &= del;
    whiteKing &= del;
}

void Chessboard::deleteBlackPiece(Bitboard square) {
    Bitboard del = ~square;
    blackPawns &= del;
    blackRooks &= del;
    blackBishops &= del;
    blackKnights &= del;
    blackQueen &= del;
    blackKing &= del;
}

void Chessboard::deletePiece(int squareToDelete) {
    Bitboard del = ~(1ULL << squareToDelete);
    whitePawns &= del;
    whiteRooks &= del;
    whiteBishops &= del;
    whiteKnights &= del;
    whiteQueen &= del;
    whiteKing &= del;
    blackPawns &= del;
    blackRooks &= del;
    blackBishops &= del;
    blackKnights &= del;
    blackQueen &= del;
    blackKing &= del;
}

bool Chessboard::checkIfWhiteKingIsOnSquare(Bitboard square) {
    return (whiteKing & square);
}

bool Chessboard::checkIfBlackKingIsOnSquare(Bitboard square) {
    return (blackKing & square);
}

bool Chessboard::checkIfWhiteKnightIsOnSquare(Bitboard square) {
    return (whiteKnights & square);
}

bool Chessboard::checkIfBlackKnightIsOnSquare(Bitboard square) {
    return (blackKnights & square);
}

bool Chessboard::checkIfWhiteQueenIsOnSquare(Bitboard square) {
    return (whiteQueen & square);
}

bool Chessboard::checkIfBlackQueenIsOnSquare(Bitboard square) {
    return (blackQueen & square);
}

bool Chessboard::checkIfWhiteBishopIsOnSquare(Bitboard square) {
    return (whiteBishops & square);
}

bool Chessboard::checkIfBlackBishopIsOnSquare(Bitboard square) {
    return (blackBishops & square);
}

bool Chessboard::checkIfWhiteRookIsOnSquare(Bitboard square) {
    return (whiteRooks & square);
}

bool Chessboard::checkIfBlackRookIsOnSquare(Bitboard square) {
    return (blackRooks & square);
}

bool Chessboard::checkIfBlackPawnIsOnSquare(Bitboard square) {
    if(blackPawns & square) return true;
    else {
        return false;
    }
}

bool Chessboard::checkIfWhitePawnIsOnSquare(Bitboard square) {
    if(whitePawns & square) return true;
    else {
        return false;
    }
}

bool Chessboard::checkIfWhitePieceIsOnSquare(Bitboard square) {
    if(whitePawns & square) return true;
    else if(whiteRooks & square) return true;
    else if(whiteKnights & square) return true;
    else if(whiteBishops & square) return true;
    else if(whiteQueen & square) return true;
    else if(whiteKing & square) return true;
    else {
        return false;
    }
}

bool Chessboard::checkIfWhitePieceIsOnSquare(int squareToDelete) {
    Bitboard square = (1ULL << squareToDelete);
    if(whitePawns & square) return true;
    else if(whiteRooks & square) return true;
    else if(whiteKnights & square) return true;
    else if(whiteBishops & square) return true;
    else if(whiteQueen & square) return true;
    else if(whiteKing & square) return true;
    else {
        return false;
    }
}

bool Chessboard::checkIfBlackPieceIsOnSquare(Bitboard square) {
    if(blackPawns & square) return true;
    else if(blackKnights & square) return true;
    else if(blackBishops & square) return true;
    else if(blackRooks & square) return true;
    else if(blackQueen & square) return true;
    else if(blackKing & square) return true;
    else {
        return false;
    }
}

bool Chessboard::checkIfBlackPieceIsOnSquare(int squareToDelete) {
    Bitboard square = (1ULL << squareToDelete);
    if(blackPawns & square) return true;
    else if(blackKnights & square) return true;
    else if(blackBishops & square) return true;
    else if(blackRooks & square) return true;
    else if(blackQueen & square) return true;
    else if(blackKing & square) return true;
    else {
        return false;
    }
}

bool Chessboard::checkIfPieceIsOnSquare(int Square) {
    Bitboard square = 1Ull << Square;
    if(whitePawns & square) return true;
    else if(whiteRooks & square) return true;
    else if(whiteKnights & square) return true;
    else if(whiteBishops & square) return true;
    else if(whiteQueen & square) return true;
    else if(whiteKing & square) return true;
    else if(blackPawns & square) return true;
    else if(blackKnights & square) return true;
    else if(blackBishops & square) return true;
    else if(blackRooks & square) return true;
    else if(blackQueen & square) return true;
    else if(blackKing & square) return true;
    else {
        //std::cout << "Detected no piece on the square\n";
        return false;
    }
    //std::cout << "Some issue in checkIfPieceIsOnSquare\n";
    return false;
}

bool Chessboard::checkIfPieceIsOnSquare(Bitboard square) {
    if(whitePawns & square) return true;
    else if(whiteRooks & square) return true;
    else if(whiteKnights & square) return true;
    else if(whiteBishops & square) return true;
    else if(whiteQueen & square) return true;
    else if(whiteKing & square) return true;
    else if(blackPawns & square) return true;
    else if(blackKnights & square) return true;
    else if(blackBishops & square) return true;
    else if(blackRooks & square) return true;
    else if(blackQueen & square) return true;
    else if(blackKing & square) return true;
    else {
        //std::cout << "Detected no piece on the square\n";
        return false;
    }
    //std::cout << "Some issue in checkIfPieceIsOnSquare\n";
    return false;
}

void Chessboard::printBoard() {
    std::cout << "  a b c d e f g h\n";
    for(int row = 7; row >= 0; row--) {
        std::cout << row + 1 << " "; 
        for(int col = 7; col >= 0; col--) {
            int square = row * 8 + col;
            char piece = '.';
            if (whitePawns & (1ULL << square)) piece = 'P';
            else if (whiteKnights & (1ULL << square)) piece = 'N';
            else if (whiteRooks & (1ULL << square)) piece = 'R';
            else if (whiteBishops & (1ULL << square)) piece = 'B';
            else if (whiteQueen & (1ULL << square)) piece = 'Q';
            else if (whiteKing & (1ULL << square)) piece = 'K';
            else if (blackPawns & (1ULL << square)) piece = 'p';
            else if (blackRooks & (1ULL << square)) piece = 'r';
            else if (blackKnights & (1ULL << square)) piece = 'n';
            else if (blackBishops & (1ULL << square)) piece = 'b';
            else if (blackQueen & (1ULL << square)) piece = 'q';
            else if (blackKing & (1ULL << square)) piece = 'k';
            else {
                
            }
            std::cout << piece << ' ';
        }
        std::cout << "\n";
    }
    std::cout << "  a b c d e f g h\n\n";
} 

void Chessboard::printBitboard(Bitboard board) {
    for (int rank = 7; rank >= 0; --rank) { // Iterate ranks from 8 to 1
        for (int file = 7; file >= 0; --file) { // Iterate files from H to A
            int square = rank * 8 + file; // Calculate square index (0-63)
            if (board & (1ULL << square)) // Check if the bit at this square is set
                std::cout << "1 ";
            else
                std::cout << ". ";
        }
        std::cout << "\n"; // Newline for each rank
    }
    std::cout << std::endl;
}
