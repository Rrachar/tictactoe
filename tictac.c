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
void printWinner(char);

int main() {
    char winner = ' ';
    resetBoard();

    while (winner == ' ' && checkFreeSpace() != 0) {
        printBoard();

        playerMove(); 
       

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
    int x;
    int y;  

    do {
        printf("Enter row number(1-3): ");
        scanf_s("%d", &x);
        x--;
        printf("Enter column number(1-3): ");
        scanf_s("%d", &y);
        y--;

        if (board[x][y] != '  ') {
            printf("Invalid Move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
    
}

void computerMove() { 
   
}

char checkWinner() { 
    
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1; // Row win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1; // Column win
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1; // Main diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1; // Other diagonal
    return 0;
}

void printWinner(char winner) { 
    
}
