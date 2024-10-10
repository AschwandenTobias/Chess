#include "chessboard.h" 
#include <iostream>

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
}

//TODO: Implement Queening
void Chessboard::moveWhitePawn(int startSquare, int endSquare) {
    Bitboard from = (1ULL << startSquare); //sets the bit to the correct from square
    Bitboard to = (1ULL << endSquare); //sets the bit to the correct to square
    if(isWhitePawnMoveLegal(startSquare, endSquare)) {
        if (whitePawns & from) { //checks if a white pawn if on the from square
            from = ~from; //reverses from in order to remove the bit after
            whitePawns &= from; //AND operation to remove the bit from the from square
            whitePawns |= to; //OR operation to add the bit to the to square
        } else {
            std::cout << "No white pawn found!\n";
        }
    } else {
        std::cout << "This move is unfortunatly not legal :(\n";
    }
}

bool Chessboard::isWhitePawnMoveLegal(int startSquare, int endSquare) {
    Bitboard from = (1ULL << startSquare);
    Bitboard tmp = (1ULL << startSquare + 8);
    Bitboard captureLeft = (1ULL << startSquare + 7);
    Bitboard captureRight = (1ULL << startSquare + 9);
    int distance = endSquare - startSquare;
    std::cout << distance << "\n";
    if (distance == 8) {
        if(!checkIfPieceIsOnSquare(tmp)) {
            std::cout << "The move is 1 square forward\n";
            return true;
        }
        return false;
    } else if (distance == 16) {
        if(!checkIfPieceIsOnSquare(tmp) && !checkIfPieceIsOnSquare(tmp << 8)) {
            std::cout << "The move is 2 squares forward\n";
            return true;
        }
        return false;
    } else if (checkIfPieceIsOnSquare(captureLeft) || checkIfPieceIsOnSquare(captureRight)) {
        std::cout << "The move is a capture\n";
        //Its a capture
    } else {
        std::cout << "The move shouldnt be possible";
    }
    bool enPassant = checkForEnPassant(startSquare, endSquare);
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
        std::cout << "Detected no piece on the square\n";
        return false;
    }
    std::cout << "Some issue in checkIfPieceIsOnSquare\n";
    return false;
}

bool Chessboard::checkForEnPassant(int startSquare, int endSquare) {
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
            else if (whiteRooks & (1ULL << square)) piece = 'R';
            else if (whiteKnights & (1ULL << square)) piece = 'N';
            else if (whiteBishops & (1ULL << square)) piece = 'B';
            else if (whiteQueen & (1ULL << square)) piece = 'Q';
            else if (whiteKing & (1ULL << square)) piece = 'K';
            else if (blackPawns & (1ULL << square)) piece = 'P';
            else if (blackRooks & (1ULL << square)) piece = 'R';
            else if (blackKnights & (1ULL << square)) piece = 'N';
            else if (blackBishops & (1ULL << square)) piece = 'B';
            else if (blackQueen & (1ULL << square)) piece = 'Q';
            else if (blackKing & (1ULL << square)) piece = 'K';
            else {
                
            }
            std::cout << piece << ' ';
        }
        std::cout << "\n";
    }
    std::cout << "  a b c d e f g h\n\n";
} 

