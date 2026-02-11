//Problem: Write a program to perform addition of two matrices having the same dimensions.
//The sum of two matrices is obtained by adding corresponding elements of the matrices.

#include <stdio.h>

int main() {
    
    int m, n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int A[m][n], B[m][n], C[m][n];

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("Resultant matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}