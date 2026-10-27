/*Start with an empty chessboard.
Begin with the first row.
Try placing a queen in each column of the current row.
Check whether the position is safe:
- No other queen exists in the same column.
- No other queen exists on the upper-left diagonal.
- No other queen exists on the upper-right diagonal.
If safe, place the queen and move to the next row.
If all N queens are placed, display the solution.
If no column is safe, remove the queen from the previous row and try another position.
Repeat to find one or all solutions.*/

#include <stdio.h>
int board[20][20];
int n, solutions = 0;
int isSafe(int row, int col) {
    int i, j;
    /* Check the same column */
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return 0;
    }
    /* Check upper-left diagonal */
    for (i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return 0;
    }
    /* Check upper-right diagonal */
    for (i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return 0;
    }
    return 1;
}
void printBoard() {
    int i, j;
    solutions++;
    printf("\nSolution %d:\n", solutions);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf("- ");
        }
        printf("\n");
    }
}
void solveNQueens(int row) {
    int col;
    if (row == n) {
        printBoard();
        return;
    }
    for (col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            solveNQueens(row + 1);
            /* Backtrack */
            board[row][col] = 0;
        }
    }
}
int main() {
    int i, j;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    if (n < 1 || n > 20) {
        printf("Enter N between 1 and 20.\n");
        return 0;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            board[i][j] = 0;
    }
    solveNQueens(0);
    if (solutions == 0)
        printf("No solution exists.\n");
    else
        printf("\nTotal solutions = %d\n", solutions);
    return 0;
}

