cmake_minimum_required(VERSION 3.10)
project(ChessEngine)

# Add your source files for the main executable
add_executable(ChessEngine src/main.cpp src/chessboard.cpp src/pawn.cpp)

# Add GoogleTest
enable_testing()
add_subdirectory(googletest)

# Include directories
include_directories(src googletest/include)

# Add your test executable
add_executable(ChessEngineTests tests/test_pawn.cpp src/chessboard.cpp src/pawn.cpp)

# Link the test executable with GoogleTest libraries
target_link_libraries(ChessEngineTests gtest gtest_main)

# Enable tests to be discovered by CTest
add_test(NAME ChessEngineTests COMMAND ChessEngineTests)