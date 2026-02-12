//Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
//A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] != matrix[i - 1][j - 1]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int m, n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int* matrixColSize = (int*)malloc(sizeof(int));
    matrixColSize[0] = n;

    if (isToeplitzMatrix(matrix, m, matrixColSize))
        printf("True");
    else
        printf("False");

    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(matrixColSize);

    return 0;
}