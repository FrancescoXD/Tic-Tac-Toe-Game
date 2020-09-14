#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void startGame(char player1, char player2);
int gameFinished(char board[9], char *winner, char playerTurn);
void showBoard(char board[9]);
int pickPosition(char player, char board[9]);
int isValidPosition(char board[9], int position);
char selectPlayer(char player1, char player2);

int main() {
    char player1, player2;
    puts("Tic Tac Toe Game");

    printf("%s", "Player 1 symbol: ");
    scanf("%c", &player1);
    while (getchar() != '\n');

    printf("%s", "Player 2 symbol: ");
    scanf("%c", &player2);
    while (getchar() != '\n');

    startGame(player1, player2);

    return 0;
}

void startGame(char player1, char player2) {
    char board[9] = {0};
    int emptySlot = 9;
    char playerTurn = selectPlayer(player1, player2);
    char winner = 0;

    while (!gameFinished(board, &winner, playerTurn)) {
        if (playerTurn == player1) {
            playerTurn = player2;
        } else {
            playerTurn = player1;
        }
        showBoard(board);
        int position = pickPosition(playerTurn, board);
        board[position] = playerTurn;
        emptySlot--;
    }
    showBoard(board);
    printf("%s%c\n", "The winner is: ", winner);
}

char selectPlayer(char player1, char player2) {
    srand(time(NULL));
    int random = rand();
    if (random % 2) return player1;

    return player2;
}

int gameFinished(char board[9], char *winner, char playerTurn) {
    if (board[0] == playerTurn && board[1] == playerTurn && board[2] == playerTurn) {
        *winner = playerTurn;
        return 1;
    } else if (board[3] == playerTurn && board[4] == playerTurn && board[5] == playerTurn) {
        *winner = playerTurn;
    } else if (board[6] == playerTurn && board[7] == playerTurn && board[8] == playerTurn) {
        *winner = playerTurn;
    } else if (board[0] == playerTurn && board[3] == playerTurn && board[6] == playerTurn) {
        *winner = playerTurn;
    } else if (board[1] == playerTurn && board[4] == playerTurn && board[7] == playerTurn) {
        *winner = playerTurn;
    } else if (board[2] == playerTurn && board[5] == playerTurn && board[8] == playerTurn) {
        *winner = playerTurn;
    } else if (board[0] == playerTurn && board[4] == playerTurn && board[8] == playerTurn) {
        *winner = playerTurn;
    } else if (board[2] == playerTurn && board[4] == playerTurn && board[6] == playerTurn) {
        *winner = playerTurn;
    } else return 0;
}

void showBoard(char board[9]) {
    printf("1%c 2%c 3%c\n4%c 5%c 6%c\n7%c 8%c 9%c\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
}

int pickPosition(char player, char board[9]) {
    int position;
    printf("%s %c: ", "Player turn", player);
    scanf("%d", &position);
    while (getchar() != '\n');
    while (!isValidPosition(board, (position - 1))) {
        printf("%s", "Position not empty: ");
        scanf("%d", &position);
    }

    return position - 1;
}

int isValidPosition(char board[9], int position) {
    if (board[position] == 0) return 1;

    return 0;
}