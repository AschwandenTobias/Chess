#include "game.h"
#include "chessboard.h"
#include <iostream>
#include <string>
#include "pieces/Pawn.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"
#include "pieces/King.h"

Game::Game() {

    IsCheckmate = false;
    whiteTurn = true;
    isDraw = false;
    board;
    kingIsInCheck = false;
}


void Game::start() {
    while(!IsCheckmate && !isDraw) {
        board.printBoard();
        std::string move;
        if(whiteTurn) {
            std::cout << "Its whites turn: Enter your move in the following format: \"e2e4\" \n";
            std::cout << "Castling White KingSide == CWKS, Castling B QueenSide == CBQS etc.\n";
        } else {
            std::cout << "Its blacks turn: Enter your move:\n";
        }
        std::cin >> move;
        if(move.length() != 4) {
            continue;
        }
        int startSquare = translateMove(move.substr(0, 2));
        int endSquare = translateMove(move.substr(2, 3));
        std::cout << "StartSquare: " << startSquare << ", EndSquare: " << endSquare << "\n";

        if (isMoveValid(startSquare, endSquare)) {
            makeMove(startSquare, endSquare);
            whiteTurn = !whiteTurn;
            if(whiteTurn) {
                King::isWhiteKingInCheck(board);
            } else {
                King::isBlackKingInCheck(board);
            }
            checkGameOver();
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }
}

int Game::translateMove(std::string move) {
    //std::cout << "move[0]: " << move[0] << ", move[1]: " << move[1] << "\n";
    //int file = move[0];
    //std::cout << "file as number: " << file << "\n";
    if (move == "CW") {  
        return 3;
    } else if (move == "KS") {  
        return 0;
    } else if (move == "QS") {  
        return 7;
    } else if (move == "CB") {  
        return 59;
    }
    int square = (move[1] - '1') * 8 + 7 - (move[0] - 'a');
    return square;
}

bool Game::isMoveValid(int startSquare, int endSquare) {
    if(endSquare < 0 || endSquare > 63) return false;
    Chessboard::Piece piece = board.getPieceAtSquare(startSquare);
    switch (piece)
    {
    case Chessboard::WHITE_PAWN:
        return Pawn::isWhitePawnMoveLegal(board, startSquare, endSquare);
        break;
    case Chessboard::WHITE_KNIGHT:
        return Knight::isWhiteKnightMoveLegal(board, startSquare, endSquare);
        break;
    case Chessboard::WHITE_BISHOP:
        return Bishop::isWhiteBishopMoveLegal(board, startSquare, endSquare);
        break;
    case Chessboard::WHITE_ROOK:
        return Rook::isWhiteRookMoveLegal(board, startSquare, endSquare);
        break;
    case Chessboard::WHITE_QUEEN:
        return Queen::isWhiteQueenMoveLegal(board, startSquare, endSquare);
        break;
    case Chessboard::WHITE_KING:
        if(startSquare == 3 && endSquare == 0) {
            return King::isWhiteKingCastlingLegal(board);
        } else if(startSquare == 3 && endSquare == 7) {
            return King::isWhiteQueenCastlingLegal(board);
        }
        return King::isWhiteKingMoveLegal(board, startSquare, endSquare);
        break;
    case Chessboard::BLACK_PAWN:
        return Pawn::isBlackPawnMoveLegal(board, startSquare, endSquare);
        break;
    case Chessboard::BLACK_KNIGHT:
        return Knight::isBlackKnightMoveLegal(board, startSquare, endSquare);
        break;
    case Chessboard::BLACK_BISHOP:
        return Bishop::isBlackBishopMoveLegal(board, startSquare, endSquare);
        break;
    case Chessboard::BLACK_ROOK:
        return Rook::isBlackRookMoveLegal(board, startSquare, endSquare);
        break;
    case Chessboard::BLACK_QUEEN:
        return Queen::isBlackQueenMoveLegal(board, startSquare, endSquare);
        break;
    case Chessboard::BLACK_KING:
        if(startSquare == 59 && endSquare == 0) {
            return King::isBlackKingCastlingLegal(board);
        } else if (startSquare == 59 && endSquare == 7) {
            return King::isBlackQueenCastlingLegal(board);
        }
        return King::isBlackKingMoveLegal(board, startSquare, endSquare);
        break;
    default:
        return false;
        break;
    }
    return true;
}

void Game::promoteWhitePawn(int endSquare) {
    std::string promotionPiece;
    Bitboard promotionSquare = (1ULL << endSquare);
    while (true) {
        std::cout << "Your pawn promotes! Enter the first letter of the piece! (B, K, Q, R)\n";
        std::cin >> promotionPiece;
        promotionPiece[0] = std::toupper(promotionPiece[0]);
        if(promotionPiece.length() != 1) {
            std::cout << "Pls only enter one character :) \n";
            continue;
        }
        if(promotionPiece == "B") {
            std::cout << "Promotion to Bishop\n";
            board.deletePiece(endSquare);
            board.whiteBishops |= promotionSquare;
            break;
        } else if (promotionPiece != "R") {
            std::cout << "Promotion to Rook\n";
            board.deletePiece(endSquare);
            board.whiteRooks |= promotionSquare;
            break;
        } else if (promotionPiece != "K") {
            std::cout << "Promotion to Knight\n";
            board.deletePiece(endSquare);
            board.whiteKnights |= promotionSquare;
            break;
        } else if(promotionPiece != "Q") {
            std::cout << "Promotion to Queen\n";
            board.deletePiece(endSquare);
            board.whiteQueen |= promotionSquare;
            break;
        } else {
            std::cout << "No correct piece detected!\n";
            continue;
        }
    }
}

void Game::promoteBlackPawn(int endSquare) {
    std::string promotionPiece;
    Bitboard promotionSquare = (1ULL << endSquare);
    while (true) {
        std::cout << "Your pawn promotes! Enter the first letter of the piece! (B, K, Q, R)\n";
        std::cin >> promotionPiece;
        promotionPiece[0] = std::toupper(promotionPiece[0]);
        if(promotionPiece.length() != 1) {
            std::cout << "Pls only enter one character :) \n";
            continue;
        }
        if(promotionPiece == "B") {
            board.deletePiece(endSquare);
            board.blackBishops |= promotionSquare;
            break;
        } else if (promotionPiece != "R") {
            board.deletePiece(endSquare);
            board.blackRooks |= promotionSquare;
            break;
        } else if (promotionPiece != "K") {
            board.deletePiece(endSquare);
            board.blackKnights |= promotionSquare;
            break;
        } else if(promotionPiece != "Q") {
            board.deletePiece(endSquare);
            board.blackQueen |= promotionSquare;
            break;
        } else {
            std::cout << "No correct piece detected!\n";
            continue;
        }
    }
}

bool Game::checkIfWhitePawnPromotes(int endSquare) {
    if(endSquare < 56 || endSquare > 63) {
        return false;
    }
    return true;
}

bool Game::checkIfBlackPawnPromotes(int endSquare) {
    if(endSquare < 0 || endSquare > 7) {
        return false;
    }
    return true;
}

void Game::makeMove(int startSquare, int endSquare) {
    Chessboard::Piece piece = board.getPieceAtSquare(startSquare);
    if (piece == Chessboard::EMPTY) {
        std::cout << "No piece at the starting square!\n";
        return; 
    }
    switch (piece) {
        case Chessboard::WHITE_PAWN:
            Pawn::moveWhitePawn(board, startSquare, endSquare);
            if(checkIfWhitePawnPromotes(endSquare)) {
                promoteWhitePawn(endSquare);
            }
            break;
        case Chessboard::WHITE_KNIGHT:
            Knight::moveWhiteKnight(board, startSquare, endSquare);
            break;
        case Chessboard::WHITE_BISHOP:
            Bishop::moveWhiteBishop(board, startSquare, endSquare);
            break;
        case Chessboard::WHITE_ROOK:
            Rook::moveWhiteRook(board, startSquare, endSquare);
            break;
        case Chessboard::WHITE_QUEEN:
            Queen::moveWhiteQueen(board, startSquare, endSquare);
            break;
        case Chessboard::WHITE_KING:
            if(startSquare == 3 && endSquare == 0) {
                King::castleWhiteKing(board, startSquare, endSquare);
            } else if(startSquare == 3 && endSquare == 7) {
                King::castleWhiteKing(board, startSquare, endSquare);
            }
            King::moveWhiteKing(board, startSquare, endSquare);
            break;
        case Chessboard::BLACK_PAWN:
            Pawn::moveBlackPawn(board, startSquare, endSquare);
            if(checkIfBlackPawnPromotes(endSquare)) {
                promoteBlackPawn(endSquare);
            }
            break;
        case Chessboard::BLACK_KNIGHT:
            Knight::moveBlackKnight(board, startSquare, endSquare);
            break;
        case Chessboard::BLACK_BISHOP:
            Bishop::moveBlackBishop(board, startSquare, endSquare);
            break;
        case Chessboard::BLACK_ROOK:
            Rook::moveBlackRook(board, startSquare, endSquare);
            break;
        case Chessboard::BLACK_QUEEN:
            Queen::moveBlackQueen(board, startSquare, endSquare);
            break;
        case Chessboard::BLACK_KING:
            if(startSquare == 59 && endSquare == 0) {
                King::castleBlackKing(board, startSquare, endSquare);
            } else if (startSquare == 59 && endSquare == 7) {
                King::castleBlackKing(board, startSquare, endSquare);
            }
            King::moveBlackKing(board, startSquare, endSquare);
            break;
        default:
            std::cout << "Unknown piece type!" << std::endl;
            return;
    }
}

void Game::checkGameOver() {

}