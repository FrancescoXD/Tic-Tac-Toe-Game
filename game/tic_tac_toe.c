#include <stdio.h>
#define TABLE_SIZE 9

enum Status { CONTINUE, FINISHED };
int currentPlayer = 1;
enum Status gameStatus = CONTINUE;

void showGameTable();
void askPlayerPosition(char *position, char *symbol);
void checkGameStatus(int *emptySlot);

char table[] = {' ', ' ', ' ',
                ' ', ' ', ' ',
                ' ', ' ', ' '};
int emptySlot = 8;

int main() {
    char position, symbol;

    printf("%s", "TIC TAC TOE GAME\n\n");

    do {
        showGameTable();
        askPlayerPosition(&position, &symbol);
        while(getchar() != '\n');
    } while (gameStatus == CONTINUE);

    showGameTable();
}

void askPlayerPosition(char *position, char *symbol) {
    if (currentPlayer % 2 == 1) {
        *symbol = 'X';
        printf("%s", "Player 1: ");
    } else {
        *symbol = 'O';
        printf("%s", "Player 2: ");
    }

    *position = getchar();

    int index = *position - 'a';
    if (table[index] == ' ') {
        table[index] = *symbol;
        ++currentPlayer;
        emptySlot--;
    } else {
        puts("Slot not empty!");
    }

    checkGameStatus(&emptySlot);
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

void checkGameStatus(int *emptySlot) {
    if (
            table[0] == 'X' && table[1] == 'X' && table[2] == 'X'
            || table[3] == 'X' && table[4] == 'X' && table[5] == 'X'
            || table[6] == 'X' && table[7] == 'X' && table[8] == 'X'
            || table[0] == 'X' && table[3] == 'X' && table[6] == 'X'
            || table[1] == 'X' && table[4] == 'X' && table[7] == 'X'
            || table[2] == 'X' && table[5] == 'X' && table[8] == 'X'
            || table[0] == 'X' && table[4] == 'X' && table[8] == 'X'
            || table[2] == 'X' && table[4] == 'X' && table[6] == 'X'
            ) {
        puts("Player 1 wins!");
        gameStatus = FINISHED;
    } else if (
            table[0] == 'O' && table[1] == 'O' && table[2] == 'O'
            || table[3] == 'O' && table[4] == 'O' && table[5] == 'O'
            || table[6] == 'O' && table[7] == 'O' && table[8] == 'O'
            || table[0] == 'O' && table[3] == 'O' && table[6] == 'O'
            || table[1] == 'O' && table[4] == 'O' && table[7] == 'O'
            || table[2] == 'O' && table[5] == 'O' && table[8] == 'O'
            || table[0] == 'O' && table[4] == 'O' && table[8] == 'O'
            || table[2] == 'O' && table[4] == 'O' && table[6] == 'O'
            ) {
        puts("Player 2 wins!");
        gameStatus = FINISHED;
    } else if (*emptySlot == 0) {
        puts("And the winner is... nobody!");
        gameStatus = FINISHED;
    }
}
