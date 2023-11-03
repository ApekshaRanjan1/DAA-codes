#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10 
// Maximum board size

int queens[MAX_N]; 
// Array to store column positions of queens

int absDiff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

bool isSafe(int row, int col) {
    for (int i = 1; i < row; i++) {
        // Check if the queens threaten each other in the same column or diagonals
        if (queens[i] == col || absDiff(queens[i], col) == absDiff(i, row)) {
            return false;
        }
    }
    return true;
}

void printSolution(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", queens[i]);
    }
    printf("\n");
}

void solveNQueens(int row, int n) {
    
    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            queens[row] = col;
            if (row == n) {
                printSolution(n);
            } 
            else {
                solveNQueens(row + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &n);

    if (n == 2 || n == 3) {
        printf("No solution exist for N = %d.\n", n);
    } 
    else if (n >= 1 && n <= MAX_N) {
        printf("Solutions for N = %d:\n",n);
        solveNQueens(1, n);
    } 
    else {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_N);
    }
}

