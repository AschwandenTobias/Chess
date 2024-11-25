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
    int whiteScore = 0, blackScore = 0;

    whiteScore += board.returnNumberOfPieces(board.WHITE_PAWN) * pawnValue;
    whiteScore += board.returnNumberOfPieces(board.WHITE_ROOK) * rookValue;
    whiteScore += board.returnNumberOfPieces(board.WHITE_BISHOP) * bishopValue;
    whiteScore += board.returnNumberOfPieces(board.WHITE_KNIGHT) * knightValue;
    whiteScore += board.returnNumberOfPieces(board.WHITE_QUEEN) * queenValue;

    blackScore += board.returnNumberOfPieces(board.BLACK_PAWN) * pawnValue;
    blackScore += board.returnNumberOfPieces(board.BLACK_ROOK) * rookValue;
    blackScore += board.returnNumberOfPieces(board.BLACK_BISHOP) * bishopValue;
    blackScore += board.returnNumberOfPieces(board.BLACK_KNIGHT) * knightValue;
    blackScore += board.returnNumberOfPieces(board.BLACK_QUEEN) * queenValue;
    //std::cout << "WhiteScore: " << whiteScore << ", blackScore : " << blackScore << "\n";
    return white ? (whiteScore - blackScore) : (blackScore - whiteScore);
}


std::pair<int, int> Engine::selectMove(Chessboard &board, std::vector<std::pair<int, int>> possibleMoves, bool white) {
    std::pair<int, int> bestMove;
    int bestEval = std::numeric_limits<int>::min();  

    for (const auto& move : possibleMoves) {
        Chessboard newBoard = board;  
        //newBoard.applyMove(move);  // Apply the move to the board
        Chessboard::Piece movingPiece = newBoard.getPieceAtSquare(move.first);
        newBoard.deletePiece(move.first);
        newBoard.deletePiece(move.second);
        newBoard.setPiece(move.second, movingPiece);
        int eval = minimax(newBoard, 2, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), false, white);
        
        
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
        return evaluationFunction(board, white);
    }

    if (isMaximizingPlayer) {  
        int maxEval = std::numeric_limits<int>::min();
        for (const auto& move : legalMoves) {
            Chessboard newBoard = board; 
            //newBoard.applyMove(move);  // Apply the move (implement properly)
            //std::cout << "Board before the move\n";
            //newBoard.printBoard();
            Chessboard::Piece movingPiece = newBoard.getPieceAtSquare(move.first);
            newBoard.deletePiece(move.first);
            newBoard.deletePiece(move.second);
            newBoard.setPiece(move.second, movingPiece);
            //std::cout << "Board after the move\n";
            //newBoard.printBoard();
            int eval = minimax(newBoard, depth - 1, alpha, beta, false, !white);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) {
                break;  
            }
        }
        return maxEval;
    } else {  
        int minEval = std::numeric_limits<int>::max();
        for (const auto& move : legalMoves) {
            Chessboard newBoard = board;  
            //newBoard.applyMove(move);  // Apply the move (implement properly)
            //std::cout << "Board before the move\n";
            //newBoard.printBoard();
            Chessboard::Piece movingPiece = newBoard.getPieceAtSquare(move.first);
            newBoard.deletePiece(move.first);
            newBoard.deletePiece(move.second);
            newBoard.setPiece(move.second, movingPiece);
            //std::cout << "Board after the move\n";
            //newBoard.printBoard();
            int eval = minimax(newBoard, depth - 1, alpha, beta, true, !white); 
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) {
                break;  
            }
        }
        return minEval;
    }
}
