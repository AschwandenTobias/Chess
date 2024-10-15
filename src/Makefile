# Makefile for the chess game

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Executable name
TARGET = chess_game

# Source files
SRCS = main.cpp chessboard.cpp pawn.cpp knight.cpp

# Object files (derived from source files)
OBJS = $(SRCS:.cpp=.o)

# Rule for building the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule for compiling source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)
