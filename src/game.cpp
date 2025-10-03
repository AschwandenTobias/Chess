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
    if(isMoveValid(currentMove)) {
        makeMove(currentMove);
        moveNumber++;
        whiteTurn = !whiteTurn;
    } else {
        std::cout << "This move it not legal, try again" << "\n";
        return;
    }
    std::cout << "StartSquare of the current move: " << currentMove.from << "\n";
    std::cout << "EndSquare of the current move: " <<currentMove.to << "\n";
    std::cout << "Piece that moves: " << currentMove.movingPiece << "\n";
    std::cout << "What Piece gets captured: " << currentMove.capturedPiece << "\n";
    std::cout << "What piece I wanna promote to: " << currentMove.promotionPiece << "\n";
    std::cout << "Whos turn is is: " << currentMove.whiteTurn << "\n";
    std::cout << "Movetype:" <<currentMove.type << "\n";
    //There seems to be no array printing in c++
    //std::cout << "PiecePositionArray: " << board.position.pieceLocation << "\n";
    
    std::cout << "\n";    
}

//This functions sets up the move to be played, including all the flags expect promotion piece.
//TODO: Should this also already ask the user for which piece he wants to promote to?
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

    //Checking for promotion
    bool isPromotion = false;
    MoveType moveType = MoveType::NORMAL;
    if(whiteTurn && movingPiece == PieceType::WhitePawn && endSquare >= 56) isPromotion = true;
    if(!whiteTurn && movingPiece == PieceType::BlackPawn && endSquare <= 7) isPromotion = true;
    if(isPromotion) moveType = MoveType::PROMOTION;
    if(isPromotion && capturedPiece != PieceType::None) moveType = MoveType::PROMOTION_CAPTURE;

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
//TODO: Add another function that sets up the promotion piece. 
bool Game::isMoveValid(Move move) {
    //std::cout << "Checking now if move is valid \n";
    int from = move.from;
    int to = move.to;
    if(to < 0 || to > 63) return false;
    if(from < 0 || from > 63) return false;
    //std::cout << "Move is inside board boundaries \n";
    //TODO: Implement here that the move is correct
    if (!board.position.isPieceAt(from, move.movingPiece)) return false;
    //std::cout << "Moving piece is at from square \n";
    switch(move.movingPiece) {
        case(PieceType::WhitePawn):
            //std::cout << "Wanting to move white pawn \n";
            if(Pawn::isMoveValid(move, board.position, whiteTurn)) return true;
        case(PieceType::BlackPawn):
            if(Pawn::isMoveValid(move, board.position, whiteTurn)) return true;
            //TODO: Add here more pieces once implemented
    }
    return false; 
}

//TODO: Implement this, dont forget to update all important bitboards. Also doesnt update the piece location one
//Always add more cases when new pieces are added. For now only has pawns
void Game::makeMove(Move move) {
    uint64_t fromMask = 1ULL << move.from;
    uint64_t toMask   = 1ULL << move.to;
    //Delete pieces first
    if (move.capturedPiece != PieceType::None) {
        uint64_t capMask = 1ULL << move.to;
        switch(move.capturedPiece) {
            case PieceType::WhitePawn:   board.position.whitePawns &= ~capMask; break;
            case PieceType::BlackPawn:   board.position.blackPawns &= ~capMask; break;
            //add more pieces once implemented
        }
    }
    //Add moving piece at right square
    switch(move.movingPiece) {
        case PieceType::WhitePawn:
            board.position.whitePawns = (board.position.whitePawns & ~fromMask) | toMask;
            board.position.whiteOccupied = (board.position.whiteOccupied & ~fromMask) | toMask;
            break;
        case PieceType::BlackPawn:
            board.position.blackPawns = (board.position.blackPawns & ~fromMask) | toMask;
            board.position.blackOccupied = (board.position.blackOccupied & ~fromMask) | toMask;
            break;
        //add more pieces once implemented
    }
    
    //Update other bitboards
    board.position.occupiedSquares = board.position.whiteOccupied | board.position.blackOccupied;
    board.position.emptySquares = ~board.position.occupiedSquares;
}

PieceType Game::promotePiece() {
    std::cout << "You can promote your pawn! Select a piece to promote into with:\n";
    std::cout << "Write Q for queen and K for knight\n"
    return PieceType::None;
}