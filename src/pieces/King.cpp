#include <iostream>
#include "king.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "Pawn.h"

void King::generateAllPossibleKingMoves(Chessboard &board, bool white) {
    //we only have 8 possible King moves, so just check each one of them?
    //This list will be different for the AI, since this doesnt take castling into account

    int kingSquare = board.getSquareOfKing(white);
    //Check is all possible Kingmoves are legal. If they are, add them to a list/array/vector?
    //return the list/vector/array of all the possible moves

}

bool King::isWhiteKingMoveNextToEnemyKing(Chessboard &board, int startSquare, int endSquare) {
    Bitboard enemyKing = board.blackKing;  
    int enemyKingSquare = __builtin_ffsll(enemyKing) - 1; 
    int endRow = endSquare / 8, endCol = endSquare % 8;
    int enemyRow = enemyKingSquare / 8, enemyCol = enemyKingSquare % 8;
    if (abs(endRow - enemyRow) <= 1 && abs(endCol - enemyCol) <= 1) {
        return true;
    }
    
    return false;
}

bool King::isBlackKingMoveNextToEnemyKing(Chessboard &board, int startSquare, int endSquare) {
    Bitboard enemyKing = board.whiteKing;  
    int enemyKingSquare = __builtin_ffsll(enemyKing) - 1; 
    int endRow = endSquare / 8, endCol = endSquare % 8;
    int enemyRow = enemyKingSquare / 8, enemyCol = enemyKingSquare % 8;
    if (abs(endRow - enemyRow) <= 1 && abs(endCol - enemyCol) <= 1) {
        return true;
    }
    return false;
}

void King::castleWhiteKing(Chessboard &board, int startSquare, int endSquare) {
    board.whiteKing &= ~(1ULL << 3);  
    if(endSquare == 0) {
        board.whiteKing |= (1ULL << 1);  
        board.whiteRooks &= ~(1ULL << 0); 
        board.whiteRooks |= (1ULL << 2);  
    } else if(endSquare == 7) {
        board.whiteKing |= (1ULL << 5);  
        board.whiteRooks &= ~(1ULL << 7); 
        board.whiteRooks |= (1ULL << 4);  
    }
    board.whiteKingMoved = true;
}

bool King::isWhiteKingCastlingLegal(Chessboard &board) {
    if(board.whiteKingRookMoved || board.whiteKingMoved) return false;
    if(isSquareInWhiteCheck(board, 3) ||isSquareInWhiteCheck(board, 2) || isSquareInWhiteCheck(board, 1)) return false;
    if(board.checkIfPieceIsOnSquare(2) || board.checkIfPieceIsOnSquare(1)) return false;
    return true;
}

bool King::isWhiteQueenCastlingLegal(Chessboard &board) {
    if(board.whiteQueenRookMoved || board.whiteKingMoved) return false;
    if(isSquareInWhiteCheck(board, 3) ||isSquareInWhiteCheck(board, 4) || isSquareInWhiteCheck(board, 5)) return false;
    if(board.checkIfPieceIsOnSquare(4) || board.checkIfPieceIsOnSquare(5)) return false;
    return true;
}


void King::castleBlackKing(Chessboard &board, int startSquare, int endSquare) {
    std::cout << "Im in King::castleBlackKing\n";
    board.blackKing &= ~(1ULL << 59);  
    if(endSquare == 0) {
        board.blackKing |= (1ULL << 57);  
        board.blackRooks &= ~(1ULL << 56); 
        board.blackRooks |= (1ULL << 58);  
    } else if(endSquare == 7) {
        board.blackKing |= (1ULL << 61);  
        board.blackRooks &= ~(1ULL << 63); 
        board.blackRooks |= (1ULL << 60);  
    }
    board.blackKingMoved = true;
}

bool King::isBlackKingCastlingLegal(Chessboard &board) {
    std::cout << "King::start of isBlackKingCastlingLegal\n";
    if(board.blackKingRookMoved || board.blackKingMoved) return false;
    std::cout << "King::blackKingRook hasn't moved and the black King hasn't moved\n";
    if(isSquareInBlackCheck(board, 59) ||isSquareInBlackCheck(board, 58) || isSquareInBlackCheck(board, 57)) return false;
    std::cout << "King::The Squares the King moves over are not in check\n";
    if(board.checkIfPieceIsOnSquare(58) || board.checkIfPieceIsOnSquare(57)) return false;
    std::cout << "King::No Pieces are in the way of castling\n";
    return true;
}

bool King::isBlackQueenCastlingLegal(Chessboard &board) {
    if(board.blackQueenRookMoved || board.blackKingMoved) return false;
    if(isSquareInBlackCheck(board, 59) ||isSquareInBlackCheck(board, 60) || isSquareInBlackCheck(board, 61)) return false;
    if(board.checkIfPieceIsOnSquare(60) || board.checkIfPieceIsOnSquare(61)) return false;
    return true;
}

bool King::isSquareInBlackCheck(Chessboard &board, int square) {
    if(checkWhiteBishopMovesForCheck(board, square)) {
        std::cout << "King::White Bishop that can attack the square detected\n";
        return true;
    } else if (checkWhiteKnightMovesForCheck(board, square)) {
        std::cout << "King::White Knight that can attack the square detected\n";
        return true;
    } else if (checkWhiteRookMovesForCheck(board, square)) {
        std::cout << "King::White Rook that can attack the square detected\n";
        return true;
    } else if(checkWhiteQueenMovesForCheck(board, square)) {
        std::cout << "King::White Queen that can attack the square detected\n";
        return true;
    } else if (checkWhitePawnMovesForCheck(board, square)) {
        std::cout << "King::White Pawn that can attack the square detected\n";
        return true;
    }
    return false;
}

bool King::isBlackKingInCheck(Chessboard &board) {
    int kingSquare = __builtin_ffsll(board.blackKing) - 1;
    std::cout << "KingSquare: " << kingSquare << "\n";
    return isSquareInBlackCheck(board, kingSquare);
}

bool King::checkWhitePawnMovesForCheck(Chessboard &board, int startSquare) {
    Bitboard whitePawns = board.whitePawns;
    int numberOfWhitePawns = __builtin_popcountll(whitePawns);
    for(int i = 0; i < numberOfWhitePawns; i++) {
        int pawnSquare = __builtin_ffsll(whitePawns) - 1;
        if(Pawn::isWhitePawnMoveLegal(board, pawnSquare, startSquare)) {
            return true;
        }
        whitePawns &= whitePawns - 1;
    }
    return false; 
}

bool King::checkWhiteQueenMovesForCheck(Chessboard &board, int startSquare) {
    Bitboard whiteQueen = board.whiteQueen;
    int numberOfWhiteQueens = __builtin_popcountll(whiteQueen);
    for(int i = 0; i < numberOfWhiteQueens; i++) {
        int queenSquare = __builtin_ffsll(whiteQueen) - 1;
        if(Queen::isWhiteQueenMoveLegal(board, queenSquare, startSquare)) {
            return true;
        }
        whiteQueen &= whiteQueen - 1;
    }
    return false; 
}

bool King::checkWhiteBishopMovesForCheck(Chessboard &board, int startSquare) {
    //std::cout << "We check now enemy Bishop moves for checks\n";
    Bitboard whiteBishops = board.whiteBishops;
    int numberOfWhiteBishops = __builtin_popcountll(whiteBishops);
    //std::cout << "Number of White Bishops: " << numberOfWhiteBishops << "\n";
    for(int i = 0; i < numberOfWhiteBishops; i++) {
        int bishopSquare = __builtin_ffsll(whiteBishops) - 1;
        if(Bishop::isBlackBishopMoveLegal(board, bishopSquare, startSquare)) { //changed from checking diagonal moves to checking if blackBishopMoveLegal
            //std::cout << "White Bishop can attack the black King!\n";
            return true;
        }
        whiteBishops &= whiteBishops - 1;
    }
    //std::cout << "No White Bishop checks detected\n";
    return false; 
}

bool King::checkWhiteKnightMovesForCheck(Chessboard &board, int startSquare) {
    Bitboard whiteKnights = board.whiteKnights;
    int numberOfWhiteKnights = __builtin_popcountll(whiteKnights);
    for(int i = 0; i < numberOfWhiteKnights; i++) {
        int knightSquare = __builtin_ffsll(whiteKnights) - 1;
        if(Knight::isWhiteKnightMoveLegal(board, knightSquare, startSquare)) {
            return true;
        }
        whiteKnights &= whiteKnights - 1;
    }
    return false; 
}

bool King::checkWhiteRookMovesForCheck(Chessboard &board, int startSquare) {
    Bitboard whiteRooks = board.whiteRooks;
    int numberOfWhiteRooks = __builtin_popcountll(whiteRooks);
    for(int i = 0; i < numberOfWhiteRooks; i++) {
        int rookSquare = __builtin_ffsll(whiteRooks) - 1;
        if(Rook::isWhiteRookMoveLegal(board, rookSquare, startSquare)) {
            return true;
        }
        whiteRooks &= whiteRooks - 1;
    }
    return false; 
}

bool King::isSquareInWhiteCheck(Chessboard &board, int square) {
    if(checkBlackBishopMovesForCheck(board, square)) {
        return true;
    } else if (checkBlackKnightMovesForCheck(board, square)) {
        return true;
    } else if (checkBlackRookMovesForCheck(board, square)) {
        return true;
    } else if(checkBlackQueenMovesForCheck(board, square)) {
        return true;
    } else if (checkBlackPawnMovesForCheck(board, square)) {
        return true;
    }
    return false;
}

bool King::checkBlackPawnMovesForCheck(Chessboard &board, int startSquare) {
    Bitboard blackPawns = board.blackPawns;
    int numberOfBlackPawns = __builtin_popcountll(blackPawns);
    for(int i = 0; i < numberOfBlackPawns; i++) {
        int pawnSquare = __builtin_ffsll(blackPawns) - 1;
        if(Pawn::isBlackPawnMoveLegal(board, pawnSquare, startSquare)) {
            return true;
        }
        blackPawns &= blackPawns - 1;
    }
    return false; 
}

bool King::checkBlackQueenMovesForCheck(Chessboard &board, int startSquare) {
    Bitboard blackQueen = board.blackQueen;
    int numberOfBlackQueens = __builtin_popcountll(blackQueen);
    for(int i = 0; i < numberOfBlackQueens; i++) {
        int queenSquare = __builtin_ffsll(blackQueen) - 1;
        if(Queen::isBlackQueenMoveLegal(board, queenSquare, startSquare)) {
            return true;
        }
        blackQueen &= blackQueen - 1;
    }
    return false; 
}

bool King::checkBlackBishopMovesForCheck(Chessboard &board, int startSquare) {
    //std::cout << "We check now enemy Bishop moves for checks\n";
    Bitboard blackBishops = board.blackBishops;
    int numberOfBlackBishops = __builtin_popcountll(blackBishops);
    //std::cout << "Number of Black Bishops: " << numberOfBlackBishops << "\n";
    for(int i = 0; i < numberOfBlackBishops; i++) {
        int bishopSquare = __builtin_ffsll(blackBishops) - 1;
        if(Bishop::isWhiteBishopMoveLegal(board, bishopSquare, startSquare)) {
            std::cout << "Black Bishop can attack the white King!\n";
            return true;
        }
        blackBishops &= blackBishops - 1;
    }
    //std::cout << "No black Bishop checks detected\n";
    return false; 
}

bool King::checkBlackKnightMovesForCheck(Chessboard &board, int startSquare) {
    Bitboard blackKnights = board.blackKnights;
    int numberOfBlackKnights = __builtin_popcountll(blackKnights);
    for(int i = 0; i < numberOfBlackKnights; i++) {
        int knightSquare = __builtin_ffsll(blackKnights) - 1;
        if(Knight::isBlackKnightMoveLegal(board, knightSquare, startSquare)) {
            return true;
        }
        blackKnights &= blackKnights - 1;
    }
    return false; 
}

bool King::checkBlackRookMovesForCheck(Chessboard &board, int startSquare) {
    Bitboard blackRooks = board.blackRooks;
    int numberOfBlackRooks = __builtin_popcountll(blackRooks);
    for(int i = 0; i < numberOfBlackRooks; i++) {
        int rookSquare = __builtin_ffsll(blackRooks) - 1;
        if(Rook::isBlackRookMoveLegal(board, rookSquare, startSquare)) {
            return true;
        }
        blackRooks &= blackRooks - 1;
    }
    return false; 
}

bool King::isWhiteKingInCheck(Chessboard &board) {
    int kingSquare = __builtin_ffsll(board.whiteKing) - 1;
    std::cout << "KingSquare: " << kingSquare << "\n";
    return isSquareInWhiteCheck(board, kingSquare);
}

void King::moveWhiteKing(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(isWhiteKingMoveLegal(board, startSquare, endSquare)) {
        board.updateLastMove(startSquare, endSquare);
        board.whiteKingMoved = true;
        if(board.checkIfBlackPieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
        from = ~from;
        board.whiteKing &= from;
        board.whiteKing |= to;
    }
}

bool King::isWhiteKingMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(endSquare < 0 || endSquare > 63) return false;
    if(!board.checkIfWhiteKingIsOnSquare(from)) return false;
    if(board.checkIfWhitePieceIsOnSquare(to)) return false;
    if(isSquareInWhiteCheck(board, endSquare)) return false;
    if(isWhiteKingMoveNextToEnemyKing(board, startSquare, endSquare)) return false;
    int distance = std::abs(endSquare - startSquare);
    int startRow = startSquare / 8;
    int endRow = endSquare / 8;
    if (std::abs(endRow - startRow) > 1) return false;
    if(distance == 1 || distance == 7 || distance == 8 || distance == 9) {
        return true;
    }
    return false;
}

void King::moveBlackKing(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(isBlackKingMoveLegal(board, startSquare, endSquare)) {
        board.updateLastMove(startSquare, endSquare);
        board.blackKingMoved = true;
        if(board.checkIfWhitePieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
        from = ~from;
        board.blackKing &= from;
        board.blackKing |= to;
    }
}

bool King::isBlackKingMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(endSquare < 0 || endSquare > 63) return false;
    if(!board.checkIfBlackKingIsOnSquare(from)) return false;
    if(board.checkIfBlackPieceIsOnSquare(to)) return false;
    if(isSquareInBlackCheck(board, endSquare)) return false;
    if(isBlackKingMoveNextToEnemyKing(board, startSquare, endSquare)) return false;
    int distance = std::abs(endSquare - startSquare);
    int startRow = startSquare / 8;
    int endRow = endSquare / 8;
    if (std::abs(endRow - startRow) > 1) return false;
    if(distance == 1 || distance == 7 || distance == 8 || distance == 9) {
        return true;
    }
    return false;
}