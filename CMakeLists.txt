cmake_minimum_required(VERSION 3.10)
project(ChessEngine)

# Add your source files
add_executable(ChessEngine src/main.cpp src/chessboard.cpp)

# Add GoogleTest
enable_testing()
add_subdirectory(googletest)

# Include directories
include_directories(src googletest/include)

# Add your test executable and link with ChessEngine sources and GoogleTest
add_executable(ChessEngineTests tests/test_main.cpp src/chessboard.cpp)
target_link_libraries(ChessEngineTests gtest gtest_main)