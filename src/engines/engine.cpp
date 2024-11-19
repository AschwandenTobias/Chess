#include "engine.h"
#include <iostream>
#include "../chessboard.h"
#include <limits>


const int pawnValue = 100;
const int rookValue = 500;
const int knightValue = 300;
const int bishopValue = 300;
const int queenValue = 900;

int Engine::evaluationFunction(Chessboard &board, bool white) {
    int score = 0;
    if(white) {
        score += board.returnNumberOfPieces(board.WHITE_PAWN);
        score += board.returnNumberOfPieces(board.WHITE_ROOK);
        score += board.returnNumberOfPieces(board.WHITE_BISHOP);
        score += board.returnNumberOfPieces(board.WHITE_KNIGHT);
        score += board.returnNumberOfPieces(board.WHITE_QUEEN);
    } else {
        score += board.returnNumberOfPieces(board.BLACK_PAWN);
        score += board.returnNumberOfPieces(board.BLACK_ROOK);
        score += board.returnNumberOfPieces(board.BLACK_BISHOP);
        score += board.returnNumberOfPieces(board.BLACK_KNIGHT);
        score += board.returnNumberOfPieces(board.BLACK_QUEEN);
    }
    return score;
}

std::pair<int, int> Engine::selectMove(Chessboard &board, std::vector<std::pair<int, int>> possibleMoves, bool white) {
    std::pair<int, int> bestMove;
    int bestEval = std::numeric_limits<int>::min();  // For white (maximizing player)

    // Explore all possible moves
    for (const auto& move : possibleMoves) {
        Chessboard newBoard = board;  // Use the passed Chessboard
        //newBoard.applyMove(move);  // Apply the move to the board
        Chessboard::Piece movingPiece = newBoard.getPieceAtSquare(move.first);
        newBoard.deletePiece(move.first);
        newBoard.deletePiece(move.second);
        newBoard.setPiece(move.second, movingPiece);

        // Evaluate the position using Minimax
        int eval = minimax(newBoard, 3, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), false, white);
        
        // Choose the move with the best evaluation
        if (eval > bestEval) {
            bestEval = eval;
            bestMove = move;
        }
    }

    return bestMove;
}

int Engine::minimax(Chessboard &board, int depth, int alpha, int beta, bool isMaximizingPlayer, bool white) {
    if (depth == 0) {
        return evaluationFunction(board, white);
    }

    std::vector<std::pair<int, int>> legalMoves = board.generateAllPossibleMoves(white);
    if (legalMoves.empty()) {
        return evaluationFunction(board, white);  // If no legal moves, return evaluation
    }

    if (isMaximizingPlayer) {  // Maximizing for white
        int maxEval = std::numeric_limits<int>::min();
        for (const auto& move : legalMoves) {
            Chessboard newBoard = board;  // Make a copy of the board
            //newBoard.applyMove(move);  // Apply the move
            Chessboard::Piece movingPiece = newBoard.getPieceAtSquare(move.first);
            newBoard.deletePiece(move.first);
            newBoard.deletePiece(move.second);
            newBoard.setPiece(move.second, movingPiece);
            int eval = minimax(newBoard, depth - 1, alpha, beta, false, white);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) {
                break;  // Beta cut-off
            }
        }
        return maxEval;
    } else {  // Minimizing for black
        int minEval = std::numeric_limits<int>::max();
        for (const auto& move : legalMoves) {
            Chessboard newBoard = board;  // Make a copy of the board
            //newBoard.applyMove(move);  // Apply the move
            Chessboard::Piece movingPiece = newBoard.getPieceAtSquare(move.first);
            newBoard.deletePiece(move.first);
            newBoard.deletePiece(move.second);
            newBoard.setPiece(move.second, movingPiece);
            int eval = minimax(newBoard, depth - 1, alpha, beta, true, white);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) {
                break;  // Alpha cut-off
            }
        }
        return minEval;
    }
}

