#include <stdio.h>

void startGame(char player1, char player2);
int gameFinished(char board[9], char *winner);
void showBoard(char board[9]);
int pickPosition(char player, char board[9]);
int isValidPosition(char board[9], int position);

int main() {
    char player1 = 'X';
    char player2 = 'O';

    startGame(player1, player2);

    return 0;
}

void startGame(char player1, char player2) {
    char board[9];
    for (size_t i = 0; i <= 9; ++i) {
        board[i] = ' ';
    }
    char playerTurn = player1;
    char winner = 0;

    while (!gameFinished(board, &winner)) {
        showBoard(board);
        int position = pickPosition(playerTurn, board);
        board[position] = playerTurn;
        if (playerTurn == player1) {
            playerTurn = player2;
        } else {
            playerTurn = player1;
        }
    }
    showBoard(board);
    printf("%s%c\n", "The winner is: ", winner);
}

int gameFinished(char board[9], char *winner) {
    if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') {
        *winner = 'X';
        return 1;
    } else if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') {
        *winner = 'X';
    } else if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') {
        *winner = 'X';
    } else if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') {
        *winner = 'X';
    } else if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') {
        *winner = 'X';
    } else if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') {
        *winner = 'X';
    } else if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') {
        *winner = 'X';
    } else if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') {
        *winner = 'X';
    } else if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') {
        *winner = 'O';
    } else if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') {
        *winner = 'O';
    } else if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') {
        *winner = 'O';
    } else if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') {
        *winner = 'O';
    } else if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') {
        *winner = 'O';
    } else if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') {
        *winner = 'O';
    } else if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') {
        *winner = 'O';
    } else if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O') {
        *winner = 'O';
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

    return position-1;
}

int isValidPosition(char board[9], int position) {
    if (board[position] == ' ') return 1;

    return 0;
}