CXX = g++

CXXFLAGS = -Wall -g

TARGET = chess

SRCS = main.cpp game.cpp chessboard.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<


clean:
	rm -f $(OBJS) $(TARGET)