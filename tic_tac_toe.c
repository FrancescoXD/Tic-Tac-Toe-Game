#include <stdio.h>
#define TABLE_SIZE 9

enum Status { CONTINUE, FINISHED };
int currentPlayer = 1;
enum Status gameStatus = CONTINUE;

void showGameTable();
void askPlayerPosition();
void checkGameStatus();

char table[] = {' ', ' ', ' ',
                ' ', ' ', ' ',
                ' ', ' ', ' '};
char position;
char symbol;
int emptySlot = 8;

int main() {
    printf("%s", "TIC TAC TOE GAME\n\n");

    showGameTable();
    askPlayerPosition();

    do {
        while (getchar() != '\n');
        showGameTable();
        askPlayerPosition();
    } while (gameStatus == CONTINUE);
    
    showGameTable();
}

void askPlayerPosition() {
    if (currentPlayer % 2 == 1) {
        symbol = 'X';
        printf("%s", "Player 1: ");
    } else {
        symbol = 'O';
        printf("%s", "Player 2: ");
    }

    position = getchar();

    int index = position - 'a';
    if (table[index] == ' ') {
        table[index] = symbol;
        ++currentPlayer;
    } else {
        puts("Slot not empty!");
    }

    checkGameStatus();
    emptySlot--;
}

void showGameTable() {
    unsigned int cont = 0;
    
    printf("%4c%4c%4c\n%4c%4c%4c\n%4c%4c%4c\n\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i');

    for (size_t i = 0; i < TABLE_SIZE; ++i) {
        printf("%4c", table[i]);
        ++cont;
        if (cont == 3) {
            puts("");
            cont = 0;
        }
    }
}

void checkGameStatus() {
    if (table[0] == 'X' && table[1] == 'X' && table[2] == 'X') {
        puts("Player 1 wins!");
        gameStatus = FINISHED;
    } else if (table[3] == 'X' && table[4] == 'X' && table[5] == 'X') {
        puts("Player 1 wins!");
        gameStatus = FINISHED;
    } else if (table[6] == 'X' && table[7] == 'X' && table[8] == 'X') {
        puts("Player 1 wins!");
        gameStatus = FINISHED;
    } else if (table[0] == 'X' && table[3] == 'X' && table[6] == 'X') {
        puts("Player 1 wins!");
        gameStatus = FINISHED;
    } else if (table[1] == 'X' && table[4] == 'X' && table[7] == 'X') {
        puts("Player 1 wins!");
        gameStatus = FINISHED;
    } else if (table[2] == 'X' && table[5] == 'X' && table[8] == 'X') {
        puts("Player 1 wins!");
        gameStatus = FINISHED;
    } else if (table[0] == 'X' && table[4] == 'X' && table[8] == 'X') {
        puts("Player 1 wins!");
        gameStatus = FINISHED;
    } else if (table[2] == 'X' && table[4] == 'X' && table[6] == 'X') {
        puts("Player 1 wins!");
        gameStatus = FINISHED;
    } else if (table[0] == 'O' && table[1] == 'O' && table[2] == 'O') {
        puts("Player 2 wins!");
        gameStatus = FINISHED;
    } else if (table[3] == 'O' && table[4] == 'O' && table[5] == 'O') {
        puts("Player 2 wins!");
        gameStatus = FINISHED;
    } else if (table[6] == 'O' && table[7] == 'O' && table[8] == 'O') {
        puts("Player 2 wins!");
        gameStatus = FINISHED;
    } else if (table[0] == 'O' && table[3] == 'O' && table[6] == 'O') {
        puts("Player 2 wins!");
        gameStatus = FINISHED;
    } else if (table[1] == 'O' && table[4] == 'O' && table[7] == 'O') {
        puts("Player 2 wins!");
        gameStatus = FINISHED;
    } else if (table[2] == 'O' && table[5] == 'O' && table[8] == 'O') {
        puts("Player 2 wins!");
        gameStatus = FINISHED;
    } else if (table[0] == 'O' && table[4] == 'O' && table[8] == 'O') {
        puts("Player 2 wins!");
        gameStatus = FINISHED;
    } else if (table[2] == 'O' && table[4] == 'O' && table[6] == 'O') {
        puts("Player 2 wins!");
        gameStatus = FINISHED;
    } else if (emptySlot == 0) {
        puts("And the winner is... nobody!");
        gameStatus = FINISHED;
    }
}