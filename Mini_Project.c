#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
#define EMPTY ' '

void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
            if (j < SIZE - 1) printf("| ");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---------\n");
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)) {
        return 1;
    }
    return 0;
}

int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == EMPTY) return 0;
    return 1;
}

void playGame() {
    char board[SIZE][SIZE] = { { EMPTY, EMPTY, EMPTY }, { EMPTY, EMPTY, EMPTY }, { EMPTY, EMPTY, EMPTY } };
    int move;
    char currentPlayer = 'X';

    while (1) {
        displayBoard(board);
        printf("Player %c, enter your move (1-9): ", currentPlayer);
        scanf("%d", &move);
        move--;

        int row = move / SIZE;
        int col = move % SIZE;

        if (move < 0 || move >= 9 || board[row][col] != EMPTY) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board)) {
            displayBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (isBoardFull(board)) {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
    }
}

int main() {
    playGame();
    return 0;
}