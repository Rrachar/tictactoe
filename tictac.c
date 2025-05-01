#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define SIZE 3

char board[SIZE][SIZE];
const char PLAYER = 'X';
const char COMPUTER = 'O';

// Function prototypes
void resetBoard();
void printBoard();
int checkFreeSpace();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char winner);

int main() {
    char winner = ' ';
    resetBoard();

    while (winner == ' ' && checkFreeSpace() != 0) {
        printBoard();
        playerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpace() == 0) break;

        computerMove();
        winner = checkWinner();
    }

    printBoard();
    printWinner(winner);

    return 0;
}

// Function Definitions

void resetBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpace() {
    int freeSpaces = 9;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove() {
    int x, y;

    do {
        printf("Enter row number (1-3): ");
        scanf_s("%d", &x);
        x--;
        printf("Enter column number (1-3): ");
        scanf_s("%d", &y);
        y--;

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y] != ' ') {
            printf("Invalid Move!\n");
        }
        else {
            board[x][y] = PLAYER;
            break;
        }
    } while (1);
}

void computerMove() {
    srand(time(0));
    int x, y;

    if (checkFreeSpace() > 0) {
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
}

char checkWinner() {
    for (int i = 0; i < SIZE; i++) {
        // Check rows and columns
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' ';
}

void printWinner(char winner) {
    if (winner == PLAYER) {
        printf("YOU WIN!!\n");
    }
    else if (winner == COMPUTER) {
        printf("YOU LOSE!!\n");
    }
    else {
        printf("IT'S A DRAW!!\n");
    }
}
