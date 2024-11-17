import chess

def print_board_custom(board):
    """
    Prints the chessboard with file and rank labels.
    """
    print("     a b c d e f g h")  # Column headers (files)
    print(" +---------------------+")
    
    # Loop over each row (rank) and print it
    for rank in range(7, -1, -1):  # Ranks go from 8 to 1 (7 to 0 in 0-indexed)
        row = " | "
        for file in range(8):  # Files go from a to h (0 to 7 in 0-indexed)
            square = chess.square(file, rank)
            piece = board.piece_at(square)
            # Print piece or an empty space
            row += (str(piece) if piece else '.') + " "
        print(f"{rank+1} {row}|")  # Print rank number and row
    print(" +---------------------+")
    
def apply_moves_from_file(filename):
    # Open the file and read all lines
    with open(filename, 'r') as file:
        for line in file:
            board = chess.Board()  # Start a new game for each line

            moves = line.strip().split()  # Split the line into individual moves

            for move_str in moves:
                move = chess.Move.from_uci(move_str)  # Convert move to UCI format
                
                if move in board.legal_moves:
                    print(f"Applying move: {move_str} ({board.san(move)})")
                    board.push(move)  # Apply the move to the board
                else:
                    print(f"Illegal move: {move_str}")
                    print_board_custom(board)
            
            print_board_custom(board)  # Print the board after each game
            print("\n--- End of Game ---\n")  # Separator between games

# Call the function to apply moves from the games.txt file
apply_moves_from_file('../games.txt')
