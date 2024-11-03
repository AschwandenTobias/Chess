cmake_minimum_required(VERSION 3.10)
project(ChessEngine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add your source files for the main executable
add_executable(ChessEngine src/main.cpp src/game.cpp src/chessboard.cpp src/pieces/pawn.cpp src/pieces/knight.cpp src/pieces/rook.cpp src/pieces/bishop.cpp src/pieces/queen.cpp src/pieces/king.cpp)

# Add GoogleTest for unit testing
enable_testing()
add_subdirectory(googletest)

# Include directories for your source files and GoogleTest
include_directories(src googletest/googletest/include)

# Add your test executable with all source and test files
add_executable(ChessEngineTests 
    tests/test_pawn.cpp 
    tests/test_knight.cpp 
    tests/test_rook.cpp
    tests/test_bishop.cpp
    tests/test_queen.cpp
    tests/test_king.cpp
    tests/test_games.cpp
    src/chessboard.cpp 
    src/pieces/pawn.cpp 
    src/pieces/knight.cpp
    src/pieces/rook.cpp
    src/pieces/bishop.cpp
    src/pieces/queen.cpp
    src/pieces/king.cpp
    src/game.cpp
)

# Link the test executable with GoogleTest libraries
target_link_libraries(ChessEngineTests gtest gtest_main)

# Enable tests to be discovered by CTest
add_test(NAME ChessEngineTests COMMAND ChessEngineTests)
