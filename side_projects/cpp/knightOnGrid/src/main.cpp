#include <iostream>
#include "../lib/knight.hpp"

void initializeBoard(char board[][SIZE]);

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);

    Knight knight;
    for (int i = 0; i < SIZE; i++) {
        std::cout << '|';
        for (int j = 0; j < SIZE; j++) {
            std::cout << board[i][j] << '|';
        }
        std::cout << '\n';
    }
    return 0;
}

void initializeBoard(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    board[0][0] = '0';
}