# Makefile for the chess game

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Executable name
TARGET = chess_game

# Source files
SRCS = main.cpp chessboard.cpp move.cpp game.cpp pieces/Pawn.cpp pieces/Knight.cpp pieces/Bishop.cpp pieces/Rook.cpp pieces/Queen.cpp pieces/King.cpp engines/randomEngine.cpp 

# Object files (derived from source files)
OBJS = $(SRCS:.cpp=.o)

# Rule for building the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for compiling source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)
