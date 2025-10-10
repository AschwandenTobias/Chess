CXX = g++

CXXFLAGS = -Wall -g

TARGET = chess

SRCS = main.cpp game.cpp chessboard.cpp position.cpp pieces/pawn.cpp pieces/king.cpp piece.cpp move.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Pattern rule for objects in any folder
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)