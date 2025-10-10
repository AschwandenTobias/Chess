#include <iostream>
#include "game.h"

Game::Game(int difficultyLevel) {
    isCheckmate = false;
    isDraw = false;
    whiteTurn = true;
    moveNumber = 1;
    //board;
    //std::cout << difficultyLevel;
}

void Game::startGame() {
    std::cout << "Starting game!\n";
    while(!isCheckmate && !isDraw) {
        makeTurn();
    }
}

void Game::makeTurn() {
    board.drawBoard();
    std::cout << "Type in your move in square Notation: e2e4, SquareToMoveFrom and SquareToMoveTo\n";
    std::cout << "If you wanna castle use CWQS (Castling White Queen Side), CBKS (Castling Black King Side) etc.\n";
    if(whiteTurn) std::cout << "Its whites turn and the move number is: " << moveNumber << "\n";
    else std::cout << "Its blacks turn and the move number is: " << moveNumber << "\n";
    std::string move;
    std::cin >> move;
    if(move.length() != 4) {
        std::cout << "Move lenght is wrong :(\n\n";
        return;
    }
    Move currentMove = parseMove(move);
    std::cout << "\nThis is printed immediately after parsing the move \n";
    std::cout << "StartSquare of the current move: " << currentMove.from << "\n";
    std::cout << "EndSquare of the current move: " <<currentMove.to << "\n";
    std::cout << "Piece that moves: " << currentMove.movingPiece << "\n";
    std::cout << "What Piece gets captured: " << currentMove.capturedPiece << "\n";
    std::cout << "What piece I wanna promote to: " << currentMove.promotionPiece << "\n";
    std::cout << "Whos turn is is: " << currentMove.whiteTurn << "\n";
    std::cout << "Movetype:" <<currentMove.type << "\n";
    std::cout << "\n";    
    if(isMoveValid(currentMove)) {
        std::cout << "game.cpp: Move was legal. Making now the move\n";
        makeMove(currentMove);
        moveNumber++;
        whiteTurn = !whiteTurn;
    } else {
        std::cout << "This move it not legal, try again" << "\n";
        return;
    }
    std::cout << "\nThis is printed at the end of the turn\n";
    std::cout << "DoublePawnMove: " << board.position.doublePawnMove << "\n\n\n";

}

//This functions sets up the move to be played, including all the flags expect promotion piece.
//TODO: Should this also already ask the user for which piece he wants to promote to?
//This does also not check, if the piece to be captured is the piece from the opponent.
Move Game::parseMove(std::string move) {
    //Sets up first the start and endSquares
    int startFile = move[0] - 'a';
    int startRank = move[1] - '1';
    int endFile = move[2] - 'a';
    int endRank = move[3] - '1';
    int startSquare = 8 * startRank + startFile;
    int endSquare = 8 * endRank + endFile;
    //Now setting up the correct piece Types
    PieceType movingPiece = board.position.getPieceAt(startSquare);
    PieceType capturedPiece = board.position.getPieceAt(endSquare);

    //Setup moveType
    bool isPromotion = false;
    MoveType moveType = MoveType::NORMAL;
    if(whiteTurn && movingPiece == PieceType::WhitePawn && endSquare >= 56) isPromotion = true;
    if(!whiteTurn && movingPiece == PieceType::BlackPawn && endSquare <= 7) isPromotion = true;
    if(capturedPiece != PieceType::None) moveType = MoveType::CAPTURE;
    if(isPromotion) moveType = MoveType::PROMOTION;
    if(isPromotion && capturedPiece != PieceType::None) moveType = MoveType::PROMOTION_CAPTURE;

    //Setup en Passant: Here just set the flag if its a possible en passant.
    if(whiteTurn && movingPiece == PieceType::WhitePawn && (endSquare - startSquare == 7 || endSquare - startSquare == 9) && !board.position.isOccupied(endSquare)) {
        moveType = MoveType::EN_PASSANT;
        capturedPiece = board.position.getPieceAt(endSquare - 8);
    } else if(!whiteTurn && movingPiece == PieceType::BlackPawn && (endSquare - startSquare == -7 || endSquare - startSquare == -9) && !board.position.isOccupied(endSquare)) {
        moveType = MoveType::EN_PASSANT;
        capturedPiece = board.position.getPieceAt(endSquare + 8);
    }
    Move currentMove(startSquare, endSquare,
                    movingPiece,  
                    whiteTurn,
                    capturedPiece,   
                    PieceType::None,  
                    moveType);
    return currentMove;
}

//This already checks if the move is outside of the board boundaries or if there is a piece i wanna move on the startSquare
//TODO: Complete here everything new piece movement has been added. This does not check the endSquare.
bool Game::isMoveValid(const Move& move) {
    //std::cout << "game.cpp::isMoveValid: Checking now if move is valid \n";
    int from = move.from;
    int to = move.to;
    //std::cout << "game.cpp::isMoveValid: Checking if move is inside board boundaries\n";
    if((to < 0 || to > 63) || (from < 0 || from > 63)) return false;
    if(whiteTurn && move.capturedPiece != PieceType::None && !board.position.isOccupiedByBlackPiece(to) && move.type != MoveType::EN_PASSANT) return false;
    if(!whiteTurn && move.capturedPiece != PieceType::None && !board.position.isOccupiedByWhitePiece(to) && move.type != MoveType::EN_PASSANT) return false;
    //TODO: Im pretty sure i dont need this next check? I already read the piece in the parser.
    if (!board.position.isPieceAt(from, move.movingPiece)) return false;
    switch(move.movingPiece) {
        case(PieceType::WhitePawn):
            //std::cout << "game.cpp::isMoveValid: Wanting to move white pawn. Checking next Pawn::isMoveValid \n";
            if(Pawn::isMoveValid(move, board.position, whiteTurn)) return true; break;
        case(PieceType::BlackPawn):
            if(Pawn::isMoveValid(move, board.position, whiteTurn)) return true; break;
            //TODO: Add here more pieces once implemented
    }
    return false; 
}

//Always add more cases when new pieces are added. For now only has pawns
//TODO: Add another function that sets up the promotion piece. 
//TODO: Filter this based on moveType?
void Game::makeMove(const Move& move) {
    int from = move.from;
    int to = move.to;
    board.position.doublePawnMove = (move.movingPiece == PieceType::WhitePawn || move.movingPiece == PieceType::BlackPawn) && (std::abs(to - from) == 16) ? from % 8 : -1;
    //Delete pieces first
    if(move.type == MoveType::CAPTURE | move.type == MoveType::PROMOTION_CAPTURE) board.position.deletePieceAt(move.capturedPiece, to);
    if(whiteTurn && move.type == MoveType::EN_PASSANT) board.position.deletePieceAt(move.capturedPiece, to - 8);
    //std::cout << "game.cpp::makeMove: Deleting piece after enPassant: " << move.capturedPiece << ", on Square: " << to -8 << "\n";
    if(!whiteTurn && move.type == MoveType::EN_PASSANT) board.position.deletePieceAt(move.capturedPiece, to + 8);
    //Add moving piece at right square
    board.position.pieceLocation[from] = PieceType::None;
    board.position.deletePieceAt(move.movingPiece, from);
    board.position.movePieceTo(move.movingPiece, to);
    //We already update the other bitboards in the moveTo function, so no need to do it here.
    
}

PieceType Game::promotePiece() {
    std::cout << "You can promote your pawn! Select a piece to promote into with:\n";
    std::cout << "Write Q for queen and K for knight\n";
    return PieceType::None;
}