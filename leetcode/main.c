#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

void displayBoard(char board[SIZE][SIZE]);
bool checkWin(char board[SIZE][SIZE], char player);
bool checkDraw(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE], char player);

int main() {
    char board[SIZE][SIZE] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    char currentPlayer = 'X';
    bool gameRunning = true;

    printf("Welcome to Tic-Tac-Toe!\n");

    while (gameRunning) {
        displayBoard(board);

        printf("Player %c, enter your move: ", currentPlayer);
        playerMove(board, currentPlayer);

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            gameRunning = false;
        } else if (checkDraw(board)) {
            displayBoard(board);
            printf("It's a draw!\n");
            gameRunning = false;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
        }
    }

    return 0;
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

bool checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // At least one cell is empty
            }
        }
    }
    return true; // No empty cells
}

void playerMove(char board[SIZE][SIZE], char player) {
    int move;
    bool validMove = false;

    while (!validMove) {
        scanf("%d", &move);

        int row = (move - 1) / SIZE;
        int col = (move - 1) % SIZE;

        if (move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
            validMove = true;
        } else {
            printf("Invalid move. Try again: ");
        }
    }
}
