#include "rook.h"
#include <iostream>

//this doesnt check if the move is legal, it just returns all attacking squares
std::vector<int> Rook::getAttackingSquares(Chessboard &board, int startSquare, int endSquare) {
    std::vector<int> attackingSquares;
    int distance = std::abs(endSquare - startSquare);
    int direction = 0;

    if(distance % 8 == 0) {
        direction = (endSquare > startSquare) ? 8 : -8;
    } else {
        direction = (endSquare > startSquare) ? 1 : -1;
    }
    while (startSquare != endSquare) {
        attackingSquares.emplace_back(startSquare);
        startSquare += direction;
    }
    return attackingSquares;
}

void Rook::moveWhiteRook(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(isWhiteRookMoveLegal(board, startSquare, endSquare)) {
        board.updateLastMove(startSquare, endSquare);
        if(board.checkIfBlackPieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
        from = ~from;
        board.whiteRooks &= from;
        board.whiteRooks |= to;
    }
}

bool Rook::isWhiteRookMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(endSquare < 0 || endSquare > 63) return false;
    if(!(board.checkIfWhiteRookIsOnSquare(from))) {
        //std::cout << "there was no rook on the startSquare\n";
        return false;
    } else { 
        if((std::abs(endSquare - startSquare) % 8) == 0) {
            if(checkVerticalMoves(board, startSquare, endSquare)) {
                if(board.checkIfWhitePieceIsOnSquare(to)) {
                    //std::cout << "White Piece on endSquare detected. Cant move :(\n";
                    return false;
                } else if(board.checkIfBlackPieceIsOnSquare(to)) {
                    //std::cout << "Black Piece to capture on endSquare detected. Capture it!\n";
                    return true;
                }
            } else {
                return false;
            }
        } else {
            if(checkHorizontalMoves(board, startSquare, endSquare)) {
                if(board.checkIfWhitePieceIsOnSquare(to)) {
                    //std::cout << "White Piece on endSquare detected. Cant move :(\n";
                    return false;
                } else if(board.checkIfBlackPieceIsOnSquare(to)) {
                    //std::cout << "Black Piece to capture on endSquare detected. Capture it!\n";
                    return true;
                }
            } else {
                return false;
            }
        }
    }
    return true;
}

void Rook::moveBlackRook(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(isBlackRookMoveLegal(board, startSquare, endSquare)) {
        board.updateLastMove(startSquare, endSquare);
        if(board.checkIfWhitePieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
    from = ~from;
    board.blackRooks &= from;
    board.blackRooks |= to;
    }
}

bool Rook::isBlackRookMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(endSquare < 0 || endSquare > 63) return false;
    if(!(board.checkIfBlackRookIsOnSquare(from))) {
        //std::cout << "there was no rook on the startSquare\n";
        return false;
    } else { 
        if((std::abs(endSquare - startSquare) % 8) == 0) {
            if(checkVerticalMoves(board, startSquare, endSquare)) {
                if(board.checkIfBlackPieceIsOnSquare(to)) {
                    //std::cout << "Black Piece on endSquare detected. Cant move :(\n";
                    return false;
                } else if(board.checkIfWhitePieceIsOnSquare(to)) {
                    //std::cout << "White Piece to capture on endSquare detected. Capture it!\n";
                    return true;
                }
            } else {
                return false;
            }
        } else {
            if(checkHorizontalMoves(board, startSquare, endSquare)) {
                if(board.checkIfBlackPieceIsOnSquare(to)) {
                    //std::cout << "Black Piece on endSquare detected. Cant move :(\n";
                    return false;
                } else if(board.checkIfWhitePieceIsOnSquare(to)) {
                    //std::cout << "White Piece to capture on endSquare detected. Capture it!\n";
                    return true;
                }
            } else {
                return false;
            }
        }
    }
    return true;
}

bool Rook::checkHorizontalMoves(Chessboard &board, int startSquare, int endSquare) {
    //std::cout << "Horizontal move detected\n";
    int distance = std::abs(endSquare - startSquare);
    int startRow = startSquare / 8;
    int endRow = endSquare / 8;
    if (startRow != endRow) return false;
    //std::cout << "startRow: " << startRow << "\n";
    if(endSquare > startSquare) {
        //std::cout << "Move to the left\n";
        Bitboard tmp = 1ULL << (startSquare + 1);
        for(int i = 0; i < distance - 1; i++) {
            if(board.checkIfPieceIsOnSquare(tmp)) {
                return false;
            }
            tmp = tmp << 1;
        }
    }
    if(endSquare < startSquare) {
        //std::cout << "Move to the right\n";
        Bitboard tmp = 1ULL << (startSquare - 1);
        for(int i = 0; i < distance - 1; i++) {
            if(board.checkIfPieceIsOnSquare(tmp)) {
                return false;
            }
            tmp = tmp >> 1;
        }
    }
    return true;
}

bool Rook::checkVerticalMoves(Chessboard &board, int startSquare, int endSquare) {
    //std::cout << "Vertical move detected\n";
    int distance = std::abs(endSquare - startSquare);
    if(distance % 8 != 0) return false;
    if(endSquare > startSquare) {
        //std::cout << "Rook moves up the board.\n";
        Bitboard tmp = 1ULL << (startSquare + 8);
        for(int i = 0; i < distance/8 - 1; i++) {
            if(board.checkIfPieceIsOnSquare(tmp)) {
                //std::cout << "Piece detected\n";
                return false;
            }
            tmp = tmp << 8;
        }
    }
    if(endSquare < startSquare) {
        //std::cout << "Rook moves down the board.\n";
        Bitboard tmp = 1ULL << (startSquare - 8);
        for(int i = 0; i < distance/8 - 1; i++) {
            if(board.checkIfPieceIsOnSquare(tmp)) {
                //std::cout << "Piece detected\n";
                return false;
            }
            tmp = tmp >> 8;
        }
    }
    return true;
}