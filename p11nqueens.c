#include <stdbool.h>
#include <stdio.h>

#define N_MAX 10

int N;

void printSolution(int board[N_MAX][N_MAX]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N_MAX][N_MAX], int row, int col) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N_MAX][N_MAX], int col) {
    if (col >= N) {
        printSolution(board);
        return true;
    }

    bool res = false;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            res = solveNQUtil(board, col + 1) || res;

            board[i][col] = 0;
        }
    }

    return res;
}

bool solveNQ() {
    printf("Enter the value N : ");
    scanf("%d", &N);

    if (N <= 0 || N > N_MAX) {
        printf("Invalid input for N.\n");
        return false;
    }

    int board[N_MAX][N_MAX] = {0};

    if (!solveNQUtil(board, 0)) {
        printf("Solution does not exist\n");
        return false;
    }

    return true;
}

int main() {
    solveNQ();
    return 0;
}
