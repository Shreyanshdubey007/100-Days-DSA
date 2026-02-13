//Given an m x n matrix, return all elements of the matrix in spiral order.

#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = matrixColSize[0];

    int* result = (int*)malloc(m * n * sizeof(int));
    *returnSize = m * n;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    int index = 0;

    while (top <= bottom && left <= right) {

        for (int i = left; i <= right; i++)
            result[index++] = matrix[top][i];
        top++;

        for (int i = top; i <= bottom; i++)
            result[index++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result[index++] = matrix[bottom][i];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[index++] = matrix[i][left];
            left++;
        }
    }

    return result;
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

    int returnSize;
    int* result = spiralOrder(matrix, m, matrixColSize, &returnSize);

    printf("Spiral order:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    for (int i = 0; i < m; i++)
        free(matrix[i]);
    free(matrix);
    free(matrixColSize);
    free(result);

    return 0;
}