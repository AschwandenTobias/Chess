import chess

def apply_moves_from_file(filename):
    board = chess.Board()

    with open(filename, 'r') as file:
        for line in file:
            moves = line.strip().split()

            for move_str in moves:
                move = chess.Move.from_uci(move_str) 
                
                if move in board.legal_moves:
                    print(f"Applying move: {move_str} ({board.san(move)})")
                    board.push(move) 
                else:
                    print(f"Illegal move: {move_str}")
            
            print(board)

apply_moves_from_file('../games.txt')