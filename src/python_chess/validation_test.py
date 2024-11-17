import chess

board = chess.Board()

coordinate_moves = ["e2e4", "e7e5", "g1f3"]

for coord in coordinate_moves:
    move = chess.Move.from_uci(coord)  
    if move in board.legal_moves:     
        print(f"Applying move: {board.san(move)}")
        board.push(move)            
    else:
        print(f"Illegal move: {coord}")

print(board)